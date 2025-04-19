#include <iostream>
#include <cmath>
#include "enc_dec.h"
#include "ldpc.h"
#include "polar.h"

polar* code;
int max_iter;

// Setup for [n,k] code
int enc_dec::init(int k, int n, bool opt_avg_latency) {
    code = factory::create(k, n);
    return 0;
}

llr_type enc_dec::llr2int(float float_llr) {
    // Contestants should replace this code
    //   This code should convert a single LLR to the integer representation used by decoder
    return float_llr;
}

// Encode k info bits into n codeword bits
void enc_dec::encode(bitvec &info, bitvec &cw) {
    // Contestants should replace this code
    //   Actual implementation would encode the information bits into codeword bits

    // Encode block
    code->encode(info, cw);
    // std::cout << "Encoded codeword: ";
    // for (auto i = 0; i < cw.size(); i++) {
    //     std::cout << cw[i] << " ";
    // }
    // std::cout << std::endl;
}

// Decode n llrs into n codeword bits and k info bits, return -1 if detected error
int enc_dec::decode(llrvec &llr, bitvec &cw_est, bitvec &info_est) {

    return code->decode(llr, cw_est, info_est);

}

