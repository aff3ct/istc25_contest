#ifndef POLAR_H
#define POLAR_H

#include "enc_dec.h"
#include <string>
#include <vector>
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

#include "decoders/generated/Decoder_polar_SC_fast_sys_N64_K32_SNR25.hpp"

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
            if (K == 32 && N == 64)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_64_32_25,
                                 new aff3ct::module::Decoder_polar_SC_fast_sys_N64_K32_SNR25(K,N,1));
            else
                throw std::invalid_argument("Unsupported polar code parameters");
        }
};


#endif // POLAR_H

