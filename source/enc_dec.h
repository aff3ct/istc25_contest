#include <vector>
#ifndef ENC_DEC_H
#define ENC_DEC_H

// Standard header for contest submission

// Two types: bit and llr
typedef int bit_type;
typedef float llr_type;
using bitvec = std::vector<bit_type>;
using llrvec = std::vector<llr_type>;
using fltvec = std::vector<float>;
using intvec = std::vector<int>;

class enc_dec
{
  public:
    // Setup for [n,k] code
    int init(int k, int n, bool opt_avg_latency);

    // float LLR to integer representation
    llr_type llr2int(float float_llr);

    // Encode k info bits into n codeword bits
    void encode(bitvec &info, bitvec &cw);

    // Decode n llrs into n codeword bits and k info bits, return -1 if detected error
    int decode(llrvec &llr, bitvec &cw_est, bitvec &info_est);
};

#endif // ENC_DEC_H

