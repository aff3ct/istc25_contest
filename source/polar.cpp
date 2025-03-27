#include "polar.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>


int polar::init(int k, int n)
{
    this->k = k;
    this->n = n;
    this->m = std::log2(n);
    this->frozen_bits.resize(n);
    this->X_N_tmp.resize(n);

    // Initialize frozen bits randomly
    for (int i = 0; i < n; ++i)
    {
        if (i < k)
            frozen_bits[i] = false; // Information bits
        else
            frozen_bits[i] = true; // Frozen bits
    }

    return 0; // Return 0 for successful initialization
}

void polar::encode(bitvec &info, bitvec &cw)
{
    std::vector<int> U_N(n);
    auto j = 0;
    for (unsigned i = 0; i < frozen_bits.size(); i++)
        U_N[i] = (frozen_bits[i]) ? 0 : info[j++];

    for(auto k = this->n >> 1; k > 0; k >>= 1)
        for (auto j = 0; j < this->n; j += 2 * k)
            for (auto i = 0; i < k; i++)
                U_N[j + i] = U_N[j + i] ^ U_N[k + j + i];
}

int polar::decode(bitvec &llr, bitvec &cw_est, bitvec &info_est)
{
    // Decode the codeword bits into the information bits
    // for (int i = 0; i < m; ++i)
    // {
    //     if (frozen_bits[i])
    //         info_est[i] = 0;
    //     else
    //         info_est[i] = llr[i];
    // }
    return 0; // Return 0 for successful decoding
}