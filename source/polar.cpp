#include "polar.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

polar::polar(int K, int N, const std::vector<bool> &frozen_bits, aff3ct::module::Decoder_polar *decoder)
    : K(K), N(N), m((int)std::log2(N)), frozen_bits(frozen_bits), decoder(decoder)
{
    crc = nullptr;
    if (K <= 0 || N <= 0 || static_cast<int>(frozen_bits.size()) != N)
        throw std::invalid_argument("Invalid parameters for polar code");
}

polar::polar(int K, int N, const std::vector<bool> &frozen_bits, aff3ct::module::Decoder_polar *decoder, aff3ct::module::CRC<int> *crc)
    : K(K), N(N), m((int)std::log2(N)), U_K_crc(K), frozen_bits(frozen_bits), decoder(decoder), crc(crc)
{
    if (K <= 0 || N <= 0 || static_cast<int>(frozen_bits.size()) != N)
        throw std::invalid_argument("Invalid parameters for polar code");
}

polar::~polar()
{
    // Destructor to clean up resources
    delete decoder;
    delete crc;
}


void polar::encode(bitvec &info, bitvec &cw)
{
    std::vector<int> U_N(N);
    auto j = 0;

    if (crc == nullptr)
    {
        for (unsigned i = 0; i < frozen_bits.size(); i++)
            U_N[i] = (frozen_bits[i]) ? 0 : info[j++];
    }
    else
    {
        this->crc->build(info.data(), U_K_crc.data());

        for (unsigned i = 0; i < frozen_bits.size(); i++)
            U_N[i] = (frozen_bits[i]) ? 0 : U_K_crc[j++];
    }


    for(auto k = this->N >> 1; k > 0; k >>= 1)
        for (auto j = 0; j < this->N; j += 2 * k)
            for (auto i = 0; i < k; i++)
                U_N[j + i] = U_N[j + i] ^ U_N[k + j + i];

    for(auto i = 0; i < this->N; i++)
        U_N[i] = !this->frozen_bits[i] && U_N[i];

    for(auto k = this->N >> 1; k > 0; k >>= 1)
        for (auto j = 0; j < this->N; j += 2 * k)
            for (auto i = 0; i < k; i++)
                U_N[j + i] = U_N[j + i] ^ U_N[k + j + i];

    std::copy(U_N.begin(), U_N.end(), cw.begin());
}

int polar::decode(llrvec &llr, bitvec &cw_est, bitvec &info_est)
{

    this->decoder->decode(llr, cw_est, info_est);
    return 0; // Return 0 for successful decoding
}