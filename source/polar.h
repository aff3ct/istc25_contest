#ifndef POLAR_H
#define POLAR_H

#include "enc_dec.h"
#include <string>
#include <vector>
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

#include "decoders/generated/Decoder_polar_SC_fast_sys_N8_K4_SNR25.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N64_K32_SNR25.hpp"

#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K64_SNR48.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N128_K64_SNR54.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N512_K128_SNR41.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K128_SNR48.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N1024_K256_SNR36.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N512_K256_SNR44.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N2048_K512_SNR30.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N1024_K512_SNR38.hpp"


using intvec = std::vector<int>;
using fltvec = std::vector<float>;


// Class for generating, encoding, and decoding binary low-density parity-check codes
class polar
{
    protected:
        int K; // number of information bits
        int N; // number of codeword bits
        int m; // log_2 of code length
        std::vector<int> X_N_tmp; // temporary storage for codeword bits

        std::vector<float> Y_N; // received LLRs
        std::vector<float> l;            // lambda, LR or LLR
        std::vector<int> s;            // bits, partial sums
        std::vector<int> s_bis;        // bits, partial sums
        const  std::vector<bool> &frozen_bits; // frozen bits
        aff3ct::module::Decoder_polar_SC_fast_sys *decoder; // decoder instance

    public:
        // Constructor
        polar(int K, int N, const std::vector<bool> &frozen_bits, aff3ct::module::Decoder_polar_SC_fast_sys *decoder);

        int init(int K, int N);

        void encode(bitvec &info, bitvec &cw);

        int decode(llrvec &llr, bitvec &cw_est, bitvec &info_est);

};

class factory
{
    public:
        // Factory method to create a polar code instance
        static polar* create(int K, int N)
        {

            std::cout << "Creating polar code with K = " << K << " and N = " << N << std::endl;
                 if (K == 4 && N == 8)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_8_4_25,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N8_K4_SNR25(K,N,1));
            else if (K == 32 && N == 64)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_64_32_25,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N64_K32_SNR25(K,N,1));
            else if (K == 64 && N == 256)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_256_64_48,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N256_K64_SNR48(K,N,1));
            else if (K == 64 && N == 128)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_128_64_54,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N128_K64_SNR54(K,N,1));
            else if (K == 128 && N == 512)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_512_128_41,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N512_K128_SNR41(K,N,1));
            else if (K == 128 && N == 256)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_256_128_48,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N256_K128_SNR48(K,N,1));
            else if (K == 256 && N == 1024)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_1024_256_36,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N1024_K256_SNR36(K,N,1));
            else if (K == 256 && N == 512)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_512_256_44,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N512_K256_SNR44(K,N,1));
            else if (K == 512 && N == 2048)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_2048_512_30,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N2048_K512_SNR30(K,N,1));
            else if (K == 512 && N == 1024)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_1024_512_38,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N1024_K512_SNR38(K,N,1));
                        else
                throw std::invalid_argument("Unsupported polar code parameters");
        }
};


#endif // POLAR_H

