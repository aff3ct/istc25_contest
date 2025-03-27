#ifndef POLAR_H
#define POLAR_H

#include "enc_dec.h"
#include <string>
#include <vector>
#include <vector>
#include <string>

using intvec = std::vector<int>;
using fltvec = std::vector<float>;



// Class for generating, encoding, and decoding binary low-density parity-check codes
class polar
{
    protected:
        int k; // number of information bits
        int n; // number of codeword bits
        int m; // log_2 of code length
        std::vector<bool> frozen_bits; // true means frozen, false means set to 0/1
        std::vector<int> X_N_tmp; // temporary storage for codeword bits

    public:

        int init(int k, int n);

        void encode(bitvec &info, bitvec &cw);

        int decode(llrvec &llr, bitvec &cw_est, bitvec &info_est);

};

#endif // POLAR_H

