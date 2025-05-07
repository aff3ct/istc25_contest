#include "polar.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdint>
#include <array>

#pragma GCC push_options
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,fma")

#include <immintrin.h>

void pack_64_scalar(const uint8_t* bits, std::vector<uint64_t>& packData,
                    int N)
{
    const uint8_t* vec_in    = bits;
    uint64_t*      symbs_out = packData.data();

    const std::size_t n_symbs = static_cast<std::size_t>(N) >> 6;
    const std::size_t rest    = static_cast<std::size_t>(N) & 0x3F;

    for (std::size_t blk = 0; blk < n_symbs; ++blk)
    {
        uint64_t symb = 0;

        for (std::size_t j = 0; j < 64; ++j)
        {
            symb <<= 1;                    // shift toward MSB
            symb |= (vec_in[j] & 1u);      // keep only LSB (or any non‑zero → 1)
        }

        *symbs_out++ = symb;
        vec_in      += 64;
    }

    if (rest)
    {
        uint64_t symb = 0;
        for (std::size_t j = 0; j < rest; ++j)
        {
            symb <<= 1;
            symb |= (vec_in[j] & 1u);
        }
        symb <<= (64 - rest);              // left‑align to MSB as in AVX2 path
        *symbs_out = symb;
    }
}

alignas(16) uint8_t bit_expand_lookup[256][8];


polar::polar(int K, int N, const std::vector<bool> &frozen_bits, aff3ct::module::Decoder_polar *decoder)
    : K(K), N(N), m((int)std::ceil(std::log2(N))), N_polar((int)std::exp2(m)), frozen_bits(frozen_bits), decoder(decoder)
{
    crc = nullptr;
    if (K <= 0 || N <= 0 || static_cast<int>(frozen_bits.size()) != N)
        throw std::invalid_argument("Invalid parameters for polar code");

    packed_frozen_bits.resize(N / 64, 0);

    std::vector<uint8_t> notfb(N, 0);
    info_pos.clear();
    for (int i = 0; i < N; ++i) {
        notfb[i] = !frozen_bits[i];
        if (!frozen_bits[i]) info_pos.push_back(i);
    }

    pack_64_scalar(notfb.data(), packed_frozen_bits, N);
    //std::cout<<packed_frozen_bits.size()<<std::endl;

    for (int i = 0; i < 256; ++i)
        for (int j = 0; j < 8; ++j)
            bit_expand_lookup[i][j] = (i >> (7 - j)) & 1;
}

polar::polar(int K, int N, const std::vector<bool> &frozen_bits, aff3ct::module::Decoder_polar *decoder, aff3ct::module::CRC<int> *crc)
    : K(K), N(N), m((int)std::ceil(std::log2(N))), N_polar((int)std::exp2(m)), U_K_crc(K), frozen_bits(frozen_bits), decoder(decoder), crc(crc)
{
    if (K <= 0 || N <= 0 || static_cast<int>(frozen_bits.size()) != N)
        throw std::invalid_argument("Invalid parameters for polar code");

    packed_frozen_bits.resize(N / 64, 0);

    std::vector<uint8_t> notfb(N, 0);
    info_pos.clear();
    for (int i = 0; i < N; ++i) {
        notfb[i] = !frozen_bits[i];
        if (!frozen_bits[i]) info_pos.push_back(i);
    }

    pack_64_scalar(notfb.data(), packed_frozen_bits, N);

    for (int i = 0; i < 256; ++i)
        for (int j = 0; j < 8; ++j)
            bit_expand_lookup[i][j] = (i >> (7 - j)) & 1;


}

polar::~polar()
{
    // Destructor to clean up resources
    delete decoder;
    if (crc != nullptr)
        delete crc;
}


void __attribute__((target("avx2")))  polar::encode(bitvec &info, bitvec &cw)
{

    int N   = cw.size();
    const size_t uint64N  = (N + 63) / 64;
    std::vector<std::uint64_t> packData(uint64N, 0);

    // Build full bit sequence: 0 on frozen positions, info[i] on information positions
    std::vector<std::uint8_t> bits(N, 0);

    if (crc == nullptr)
    {
        for (size_t i = 0; i < info_pos.size(); ++i)
            bits[info_pos[i]] = static_cast<uint8_t>(info[i]);

    }
    else
    {
        this->crc->build(info.data(), U_K_crc.data());
        for (size_t i = 0; i < info_pos.size(); ++i)
            bits[info_pos[i]] = static_cast<uint8_t>(U_K_crc[i]);
    }

    const std::uint8_t* vec_in    = bits.data();
    std::uint64_t*      symbs_out = packData.data();
    const std::size_t   n_symbs   = N / 64;

    const __m256i zero = _mm256_setzero_si256();

    for (size_t i = 0; i < n_symbs; ++i) {
        __m256i in0  = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(vec_in));
        __m256i in1  = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(vec_in + 32));
        __m256i m0   = _mm256_cmpgt_epi8(in0, zero);
        __m256i m1   = _mm256_cmpgt_epi8(in1, zero);
        uint32_t ms0 = static_cast<uint32_t>(_mm256_movemask_epi8(m0));
        uint32_t ms1 = static_cast<uint32_t>(_mm256_movemask_epi8(m1));
        uint64_t pack_rev = (static_cast<uint64_t>(ms1) << 32) | ms0;


        pack_rev = ((pack_rev >> 1)  & 0x5555555555555555ULL) | ((pack_rev & 0x5555555555555555ULL) << 1);
        pack_rev = ((pack_rev >> 2)  & 0x3333333333333333ULL) | ((pack_rev & 0x3333333333333333ULL) << 2);
        pack_rev = ((pack_rev >> 4)  & 0x0f0f0f0f0f0f0f0fULL) | ((pack_rev & 0x0f0f0f0f0f0f0f0fULL) << 4);
        pack_rev = ((pack_rev >> 8)  & 0x00ff00ff00ff00ffULL) | ((pack_rev & 0x00ff00ff00ff00ffULL) << 8);
        pack_rev = ((pack_rev >> 16) & 0x0000ffff0000ffffULL) | ((pack_rev & 0x0000ffff0000ffffULL) << 16);
        pack_rev =  (pack_rev >> 32) | (pack_rev << 32);


        *symbs_out++ = pack_rev;
        vec_in += 64;
    }

    if(N==2048)
    {

        // Load 32 × 64‑bit words into eight 256‑bit lanes (a – h)
        __m256i a = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() +  0));
        __m256i b = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() +  4));
        __m256i c = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() +  8));
        __m256i d = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() + 12));
        __m256i e = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() + 16));
        __m256i f = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() + 20));
        __m256i g = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() + 24));
        __m256i h = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() + 28));

        static const std::vector<std::array<uint64_t,4>> masks = {
            {0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0x0ULL},
            {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL},
            {0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL},
            {0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL},
            {0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL},
            {0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL},
            {0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL},
            {0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL}
        };
        const int shifts[8] = {128,64,32,16,8,4,2,1};

        // Applique les 8 sous‑étages (k = 128 … 1) sur un registre de 256 bits
        auto process = [&](__m256i& reg) {
            for (int s = 0; s < 8; ++s) {
                // masque correspondant au sous‑étage s
                const __m256i mask = _mm256_loadu_si256(
                    reinterpret_cast<const __m256i*>(masks[s].data()));

                // s*bits puis masquage
                __m256i shifted = reg;

                int mod = shifts[s] / 64;
                int rst = shifts[s] % 64;
                for (int i = 0; i < mod; ++i)
                {
                    shifted = _mm256_permute4x64_epi64(shifted, _MM_SHUFFLE(0, 3, 2, 1));
                    shifted = _mm256_blend_epi32(shifted, _mm256_setzero_si256(), 0xC0);

                }

                __m256i innerCarry = _mm256_srli_epi64(shifted, 64 - rst);
                __m256i rotate     = _mm256_permute4x64_epi64(innerCarry, 0x93);
                __m256i carryMask  = _mm256_blend_epi32(_mm256_setzero_si256(), rotate, 0xFC);
                shifted              = _mm256_slli_epi64(shifted, rst);
                shifted              = _mm256_or_si256(shifted, carryMask);

                const __m256i res     = _mm256_and_si256(shifted, mask);

                // XOR pour terminer l’étage
                reg = _mm256_xor_si256(reg, res);
            }
        };


        process(a); process(b); process(c); process(d);
        process(e); process(f); process(g); process(h);

        // 512‑bit stage
        a ^= b; c ^= d; e ^= f; g ^= h;
        // 1024‑bit stage
        a ^= c; b ^= d; e ^= g; f ^= h;
        // 2048‑bit stage
        a ^= e; b ^= f; c ^= g; d ^= h;

        // Apply frozen‑bit mask (keeps only non‑frozen bits for the second half transform)
        auto apply_mask = [&](auto& reg, size_t offset){
            __m256i m = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packed_frozen_bits.data() + offset));
            reg = _mm256_and_si256(reg, m);
        };
        apply_mask(a,0); apply_mask(b,4); apply_mask(c,8);  apply_mask(d,12);
        apply_mask(e,16); apply_mask(f,20); apply_mask(g,24); apply_mask(h,28);

        // Re‑process after masking
        process(a); process(b); process(c); process(d);
        process(e); process(f); process(g); process(h);

        // Repeat XOR stages
        a ^= b; c ^= d; e ^= f; g ^= h;
        a ^= c; b ^= d; e ^= g; f ^= h;
        a ^= e; b ^= f; c ^= g; d ^= h;

        // Store and unpack
        _mm256_storeu_si256(reinterpret_cast<__m256i_u*>(packData.data()), a);
        _mm256_storeu_si256(reinterpret_cast<__m256i*>(packData.data() +  4), b);
        _mm256_storeu_si256(reinterpret_cast<__m256i*>(packData.data() +  8), c);
        _mm256_storeu_si256(reinterpret_cast<__m256i*>(packData.data() + 12), d);
        _mm256_storeu_si256(reinterpret_cast<__m256i*>(packData.data() + 16), e);
        _mm256_storeu_si256(reinterpret_cast<__m256i*>(packData.data() + 20), f);
        _mm256_storeu_si256(reinterpret_cast<__m256i*>(packData.data() + 24), g);
        _mm256_storeu_si256(reinterpret_cast<__m256i*>(packData.data() + 28), h);


        const size_t n_full = N / 64;
        const uint64_t* in  = packData.data();
        int* out           = cw.data();
        alignas(16) uint8_t tmp[64];

        for (size_t i = 0; i < n_full; ++i) {
            uint64_t s = *in++;
    #define LOAD_ROW(shift) _mm_loadl_epi64(reinterpret_cast<const __m128i*>(bit_expand_lookup[(s >> shift) & 0xFF]))
            __m128i r7 = LOAD_ROW(56), r6 = LOAD_ROW(48), r5 = LOAD_ROW(40), r4 = LOAD_ROW(32);
            __m128i r3 = LOAD_ROW(24), r2 = LOAD_ROW(16), r1 = LOAD_ROW(8),  r0 = LOAD_ROW(0);
    #undef LOAD_ROW
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp +  0), _mm_unpacklo_epi64(r7, r6));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 16), _mm_unpacklo_epi64(r5, r4));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 32), _mm_unpacklo_epi64(r3, r2));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 48), _mm_unpacklo_epi64(r1, r0));
            for (int k = 0; k < 64; ++k) *out++ = static_cast<int>(tmp[k]);
        }
    }

    if(N==1024)
    {
        // Load 32 × 64‑bit words into eight 256‑bit lanes (a – h)
        __m256i a = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() +  0));
        __m256i b = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() +  4));
        __m256i c = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() +  8));
        __m256i d = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() + 12));

        static const std::vector<std::array<uint64_t,4>> masks = {
            {0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0x0ULL},
            {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL},
            {0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL},
            {0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL},
            {0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL},
            {0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL},
            {0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL},
            {0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL}
        };
        const int shifts[8] = {128,64,32,16,8,4,2,1};

        // Applique les 8 sous‑étages (k = 128 … 1) sur un registre de 256 bits
        auto process = [&](__m256i& reg) {
            for (int s = 0; s < 8; ++s) {
                // masque correspondant au sous‑étage s
                const __m256i mask = _mm256_loadu_si256(
                    reinterpret_cast<const __m256i*>(masks[s].data()));

                // s*bits puis masquage
                __m256i shifted = reg;

                int mod = shifts[s] / 64;
                int rst = shifts[s] % 64;
                for (int i = 0; i < mod; ++i)
                {
                    shifted = _mm256_permute4x64_epi64(shifted, _MM_SHUFFLE(0, 3, 2, 1));
                    shifted = _mm256_blend_epi32(shifted, _mm256_setzero_si256(), 0xC0);

                }

                __m256i innerCarry = _mm256_srli_epi64(shifted, 64 - rst);
                __m256i rotate     = _mm256_permute4x64_epi64(innerCarry, 0x93);
                __m256i carryMask  = _mm256_blend_epi32(_mm256_setzero_si256(), rotate, 0xFC);
                shifted              = _mm256_slli_epi64(shifted, rst);
                shifted              = _mm256_or_si256(shifted, carryMask);

                const __m256i res     = _mm256_and_si256(shifted, mask);

                // XOR pour terminer l’étage
                reg = _mm256_xor_si256(reg, res);
            }
        };

        process(a); process(b); process(c); process(d);

        // stage of 512 vectors
        a ^= b; c ^= d;

        // stage of 1024 vectors
        a ^= c; b ^= d;

        // Apply frozen‑bit mask (keeps only non‑frozen bits for the second half transform)
        auto apply_mask = [&](auto& reg, size_t offset){
            __m256i m = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packed_frozen_bits.data() + offset));
            reg = _mm256_and_si256(reg, m);
        };
        apply_mask(a,0); apply_mask(b,4); apply_mask(c,8);  apply_mask(d,12);

        process(a); process(b); process(c); process(d);

        // stage of 512 vectors
        a ^= b; c ^= d;

        // stage of 1024 vectors
        a ^= c; b ^= d;

        // Store and unpack
        _mm256_storeu_si256(reinterpret_cast<__m256i_u*>(packData.data()), a);
        _mm256_storeu_si256(reinterpret_cast<__m256i*>(packData.data() +  4), b);
        _mm256_storeu_si256(reinterpret_cast<__m256i*>(packData.data() +  8), c);
        _mm256_storeu_si256(reinterpret_cast<__m256i*>(packData.data() + 12), d);

        const size_t n_full = N / 64;
        const uint64_t* in  = packData.data();
        int* out           = cw.data();
        alignas(16) uint8_t tmp[64];

        for (size_t i = 0; i < n_full; ++i) {
            uint64_t s = *in++;
    #define LOAD_ROW(shift) _mm_loadl_epi64(reinterpret_cast<const __m128i*>(bit_expand_lookup[(s >> shift) & 0xFF]))
            __m128i r7 = LOAD_ROW(56), r6 = LOAD_ROW(48), r5 = LOAD_ROW(40), r4 = LOAD_ROW(32);
            __m128i r3 = LOAD_ROW(24), r2 = LOAD_ROW(16), r1 = LOAD_ROW(8),  r0 = LOAD_ROW(0);
    #undef LOAD_ROW
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp +  0), _mm_unpacklo_epi64(r7, r6));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 16), _mm_unpacklo_epi64(r5, r4));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 32), _mm_unpacklo_epi64(r3, r2));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 48), _mm_unpacklo_epi64(r1, r0));
            for (int k = 0; k < 64; ++k) *out++ = static_cast<int>(tmp[k]);
        }
    }

    if(N==512)
    {

        // Load 32 × 64‑bit words into eight 256‑bit lanes (a – h)
        __m256i a = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() +  0));
        __m256i b = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() +  4));

        static const std::vector<std::array<uint64_t,4>> masks = {
            {0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0x0ULL},
            {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL},
            {0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL},
            {0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL},
            {0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL},
            {0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL},
            {0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL},
            {0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL}
        };
        const int shifts[8] = {128,64,32,16,8,4,2,1};

        // Applique les 8 sous‑étages (k = 128 … 1) sur un registre de 256 bits
        auto process = [&](__m256i& reg) {
            for (int s = 0; s < 8; ++s) {
                // masque correspondant au sous‑étage s
                const __m256i mask = _mm256_loadu_si256(
                    reinterpret_cast<const __m256i*>(masks[s].data()));

                // s*bits puis masquage
                __m256i shifted = reg;

                int mod = shifts[s] / 64;
                int rst = shifts[s] % 64;
                for (int i = 0; i < mod; ++i)
                {
                    shifted = _mm256_permute4x64_epi64(shifted, _MM_SHUFFLE(0, 3, 2, 1));
                    shifted = _mm256_blend_epi32(shifted, _mm256_setzero_si256(), 0xC0);

                }

                __m256i innerCarry = _mm256_srli_epi64(shifted, 64 - rst);
                __m256i rotate     = _mm256_permute4x64_epi64(innerCarry, 0x93);
                __m256i carryMask  = _mm256_blend_epi32(_mm256_setzero_si256(), rotate, 0xFC);
                shifted              = _mm256_slli_epi64(shifted, rst);
                shifted              = _mm256_or_si256(shifted, carryMask);

                const __m256i res     = _mm256_and_si256(shifted, mask);

                // XOR pour terminer l’étage
                reg = _mm256_xor_si256(reg, res);
            }
        };

        process(a); process(b);

        // stage of 512 vectors
        a ^= b;

        // Apply frozen‑bit mask (keeps only non‑frozen bits for the second half transform)
        auto apply_mask = [&](auto& reg, size_t offset){
            __m256i m = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packed_frozen_bits.data() + offset));
            reg = _mm256_and_si256(reg, m);
        };
        apply_mask(a,0); apply_mask(b,4);

        process(a); process(b);

        // stage of 512 vectors
        a ^= b;

        // Store and unpack
        _mm256_storeu_si256(reinterpret_cast<__m256i_u*>(packData.data()), a);
        _mm256_storeu_si256(reinterpret_cast<__m256i*>(packData.data() +  4), b);

        const size_t n_full = N / 64;
        const uint64_t* in  = packData.data();
        int* out           = cw.data();
        alignas(16) uint8_t tmp[64];

        for (size_t i = 0; i < n_full; ++i) {
            uint64_t s = *in++;
    #define LOAD_ROW(shift) _mm_loadl_epi64(reinterpret_cast<const __m128i*>(bit_expand_lookup[(s >> shift) & 0xFF]))
            __m128i r7 = LOAD_ROW(56), r6 = LOAD_ROW(48), r5 = LOAD_ROW(40), r4 = LOAD_ROW(32);
            __m128i r3 = LOAD_ROW(24), r2 = LOAD_ROW(16), r1 = LOAD_ROW(8),  r0 = LOAD_ROW(0);
    #undef LOAD_ROW
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp +  0), _mm_unpacklo_epi64(r7, r6));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 16), _mm_unpacklo_epi64(r5, r4));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 32), _mm_unpacklo_epi64(r3, r2));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 48), _mm_unpacklo_epi64(r1, r0));
            for (int k = 0; k < 64; ++k) *out++ = static_cast<int>(tmp[k]);
        }
    }

    if(N==256)
    {
        // Load 32 × 64‑bit words into eight 256‑bit lanes (a – h)
        __m256i a = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() +  0));

        static const std::vector<std::array<uint64_t,4>> masks = {
            {0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0x0ULL},
            {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL},
            {0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL},
            {0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL},
            {0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL},
            {0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL},
            {0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL},
            {0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL}
        };
        const int shifts[8] = {128,64,32,16,8,4,2,1};

        // Applique les 8 sous‑étages (k = 128 … 1) sur un registre de 256 bits
        auto process = [&](__m256i& reg) {
            for (int s = 0; s < 8; ++s) {
                // masque correspondant au sous‑étage s
                const __m256i mask = _mm256_loadu_si256(
                    reinterpret_cast<const __m256i*>(masks[s].data()));

                // s*bits puis masquage
                __m256i shifted = reg;

                int mod = shifts[s] / 64;
                int rst = shifts[s] % 64;
                for (int i = 0; i < mod; ++i)
                {
                    shifted = _mm256_permute4x64_epi64(shifted, _MM_SHUFFLE(0, 3, 2, 1));
                    shifted = _mm256_blend_epi32(shifted, _mm256_setzero_si256(), 0xC0);

                }

                __m256i innerCarry = _mm256_srli_epi64(shifted, 64 - rst);
                __m256i rotate     = _mm256_permute4x64_epi64(innerCarry, 0x93);
                __m256i carryMask  = _mm256_blend_epi32(_mm256_setzero_si256(), rotate, 0xFC);
                shifted              = _mm256_slli_epi64(shifted, rst);
                shifted              = _mm256_or_si256(shifted, carryMask);

                const __m256i res     = _mm256_and_si256(shifted, mask);

                // XOR pour terminer l’étage
                reg = _mm256_xor_si256(reg, res);
            }
        };

        process(a);

        // Apply frozen‑bit mask (keeps only non‑frozen bits for the second half transform)
        auto apply_mask = [&](auto& reg, size_t offset){
            __m256i m = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packed_frozen_bits.data() + offset));
            reg = _mm256_and_si256(reg, m);
        };
        apply_mask(a,0);

        process(a);

        // Store and unpack
        _mm256_storeu_si256(reinterpret_cast<__m256i_u*>(packData.data()), a);

        const size_t n_full = N / 64;
        const uint64_t* in  = packData.data();
        int* out           = cw.data();
        alignas(16) uint8_t tmp[64];

        for (size_t i = 0; i < n_full; ++i) {
            uint64_t s = *in++;
    #define LOAD_ROW(shift) _mm_loadl_epi64(reinterpret_cast<const __m128i*>(bit_expand_lookup[(s >> shift) & 0xFF]))
            __m128i r7 = LOAD_ROW(56), r6 = LOAD_ROW(48), r5 = LOAD_ROW(40), r4 = LOAD_ROW(32);
            __m128i r3 = LOAD_ROW(24), r2 = LOAD_ROW(16), r1 = LOAD_ROW(8),  r0 = LOAD_ROW(0);
    #undef LOAD_ROW
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp +  0), _mm_unpacklo_epi64(r7, r6));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 16), _mm_unpacklo_epi64(r5, r4));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 32), _mm_unpacklo_epi64(r3, r2));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 48), _mm_unpacklo_epi64(r1, r0));
            for (int k = 0; k < 64; ++k) *out++ = static_cast<int>(tmp[k]);
        }
    }

    if(N==128)
    {

        int N_0   = 256;
        const size_t uint64N  = (N_0 + 63) / 64;
        std::vector<std::uint64_t> packData(uint64N, 0);

        // Build full bit sequence: 0 on frozen positions, info[i] on information positions
        std::vector<std::uint8_t> bits(N_0, 0);

        if (crc == nullptr)
        {
            for (size_t i = 0; i < info_pos.size(); ++i)
                bits[info_pos[i]] = (uint8_t) info[i];

        }
        else
        {
            this->crc->build(info.data(), U_K_crc.data());
            for (size_t i = 0; i < info_pos.size(); ++i)
                bits[info_pos[i]] = (uint8_t) U_K_crc[i];
        }

        const std::uint8_t* vec_in    = bits.data();
        std::uint64_t*      symbs_out = packData.data();
        const std::size_t   n_symbs   = N / 64;

        const __m256i zero = _mm256_setzero_si256();

        for (size_t i = 0; i < n_symbs; ++i) {
            __m256i in0  = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(vec_in));
            __m256i in1  = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(vec_in + 32));
            __m256i m0   = _mm256_cmpgt_epi8(in0, zero);
            __m256i m1   = _mm256_cmpgt_epi8(in1, zero);
            uint32_t ms0 = static_cast<uint32_t>(_mm256_movemask_epi8(m0));
            uint32_t ms1 = static_cast<uint32_t>(_mm256_movemask_epi8(m1));
            uint64_t pack_rev = (static_cast<uint64_t>(ms1) << 32) | ms0;

            pack_rev = ((pack_rev >> 1)  & 0x5555555555555555ULL) | ((pack_rev & 0x5555555555555555ULL) << 1);
            pack_rev = ((pack_rev >> 2)  & 0x3333333333333333ULL) | ((pack_rev & 0x3333333333333333ULL) << 2);
            pack_rev = ((pack_rev >> 4)  & 0x0f0f0f0f0f0f0f0fULL) | ((pack_rev & 0x0f0f0f0f0f0f0f0fULL) << 4);
            pack_rev = ((pack_rev >> 8)  & 0x00ff00ff00ff00ffULL) | ((pack_rev & 0x00ff00ff00ff00ffULL) << 8);
            pack_rev = ((pack_rev >> 16) & 0x0000ffff0000ffffULL) | ((pack_rev & 0x0000ffff0000ffffULL) << 16);
            pack_rev =  (pack_rev >> 32) | (pack_rev << 32);

            *symbs_out++ = pack_rev;
            vec_in += 64;
        }

        // Load 32 × 64‑bit words into eight 256‑bit lanes (a – h)
        __m256i a = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packData.data() +  0));

        static const std::vector<std::array<uint64_t,4>> masks = {
            {0xFFFFFFFFFFFFFFFFULL, 0x0ULL, 0xFFFFFFFFFFFFFFFFULL, 0x0ULL},
            {0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL, 0xFFFFFFFF00000000ULL},
            {0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL, 0xFFFF0000FFFF0000ULL},
            {0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FF00ULL},
            {0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0F0ULL},
            {0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL, 0xCCCCCCCCCCCCCCCCULL},
            {0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL, 0xAAAAAAAAAAAAAAAAULL}
        };
        const int shifts[7] = {64,32,16,8,4,2,1};

        // Applique les 8 sous‑étages (k = 128 … 1) sur un registre de 256 bits
        auto process = [&](__m256i& reg) {
            for (int s = 0; s < 7; ++s) {
                // masque correspondant au sous‑étage s
                const __m256i mask = _mm256_loadu_si256(
                    reinterpret_cast<const __m256i*>(masks[s].data()));

                // s*bits puis masquage
                __m256i shifted = reg;

                int mod = shifts[s] / 64;
                int rst = shifts[s] % 64;
                for (int i = 0; i < mod; ++i)
                {
                    shifted = _mm256_permute4x64_epi64(shifted, _MM_SHUFFLE(0, 3, 2, 1));
                    shifted = _mm256_blend_epi32(shifted, _mm256_setzero_si256(), 0xC0);

                }

                __m256i innerCarry = _mm256_srli_epi64(shifted, 64 - rst);
                __m256i rotate     = _mm256_permute4x64_epi64(innerCarry, 0x93);
                __m256i carryMask  = _mm256_blend_epi32(_mm256_setzero_si256(), rotate, 0xFC);
                shifted              = _mm256_slli_epi64(shifted, rst);
                shifted              = _mm256_or_si256(shifted, carryMask);

                const __m256i res     = _mm256_and_si256(shifted, mask);

                // XOR pour terminer l’étage
                reg = _mm256_xor_si256(reg, res);
            }
        };

        process(a);

        // Apply frozen‑bit mask (keeps only non‑frozen bits for the second half transform)
        auto apply_mask = [&](auto& reg, size_t offset){
            __m256i m = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(packed_frozen_bits.data() + offset));
            reg = _mm256_and_si256(reg, m);
        };
        apply_mask(a,0);

        process(a);

        // Store and unpack
        _mm256_storeu_si256(reinterpret_cast<__m256i_u*>(packData.data()), a);

        const size_t n_full = N / 64;
        const uint64_t* in  = packData.data();
        int* out           = cw.data();
        alignas(16) uint8_t tmp[64];

        for (size_t i = 0; i < n_full; ++i) {
            uint64_t s = *in++;
    #define LOAD_ROW(shift) _mm_loadl_epi64(reinterpret_cast<const __m128i*>(bit_expand_lookup[(s >> shift) & 0xFF]))
            __m128i r7 = LOAD_ROW(56), r6 = LOAD_ROW(48), r5 = LOAD_ROW(40), r4 = LOAD_ROW(32);
            __m128i r3 = LOAD_ROW(24), r2 = LOAD_ROW(16), r1 = LOAD_ROW(8),  r0 = LOAD_ROW(0);
    #undef LOAD_ROW
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp +  0), _mm_unpacklo_epi64(r7, r6));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 16), _mm_unpacklo_epi64(r5, r4));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 32), _mm_unpacklo_epi64(r3, r2));
            _mm_store_si128(reinterpret_cast<__m128i*>(tmp + 48), _mm_unpacklo_epi64(r1, r0));
            for (int k = 0; k < 64; ++k) *out++ = static_cast<int>(tmp[k]);
        }
    }
}

int polar::decode(llrvec &llr, bitvec &cw_est, bitvec &info_est)
{
    return this->decoder->decode(llr, cw_est, info_est);
}