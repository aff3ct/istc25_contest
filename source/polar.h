#ifndef POLAR_H
#define POLAR_H

#include "enc_dec.h"
#include <string>
#include <vector>
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

#include "decoders/Decoder_polar_ASCL_fast_CA_sys.hpp"

#include "decoders/CRC.hpp"

#include "decoders/polar_functions.hpp"

using intvec = std::vector<int>;
using fltvec = std::vector<float>;


// Class for generating, encoding, and decoding binary low-density parity-check codes
class polar
{
    protected:
        int K; // number of information bits
        int N; // number of codeword bits
        int m; // log_2 of code length
        int N_polar; // polar code length (N = 2^m)
        std::vector<int> X_N_tmp; // temporary storage for codeword bits
        std::vector<int> U_K_crc; // information bits with CRC

        std::vector<float> Y_N; // received LLRs
        std::vector<float> l;            // lambda, LR or LLR
        std::vector<int> s;            // bits, partial sums
        std::vector<int> s_bis;        // bits, partial sums
        const  std::vector<bool> &frozen_bits; // frozen bits


        std::vector<uint64_t> packed_frozen_bits; // packed (¬frozen) mask used by SIMD
        std::vector<int> info_pos;                // positions of information bits (size = K)



        aff3ct::module::Decoder_polar *decoder; // decoder instance
        aff3ct::module::CRC<int> *crc;
    public:
        // Constructor
        polar(int K, int N, const std::vector<bool> &frozen_bits, aff3ct::module::Decoder_polar *decoder);
        polar(int K, int N, const std::vector<bool> &frozen_bits, aff3ct::module::Decoder_polar *decoder, aff3ct::module::CRC<int> *crc);

        // Destructor
        ~polar();

        void encode(bitvec &info, bitvec &cw);

        int decode(llrvec &llr, bitvec &cw_est, bitvec &info_est);

};

#include "factory.h"

#endif // POLAR_H

