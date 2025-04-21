/*!
* \file
* \brief Class module::Decoder_polar_SC_fast_sys.
*/
#ifndef DECODER_POLAR_SC_FAST_SYS_
#define DECODER_POLAR_SC_FAST_SYS_

#include <vector>
#include <cmath>
#include "polar_functions.hpp"
#include "Decoder_polar.hpp"

namespace aff3ct
{
namespace module
{

class Decoder_polar_SC_fast_sys : public Decoder_polar
{

protected:
        std::vector<float> l;            // lambda, LR or LLR
        std::vector<int>  s;              // bits, partial sums
        std::vector<int>  s_bis;          // bits, partial sums
    const  std::vector<bool> &frozen_bits; // frozen bits

public:
Decoder_polar_SC_fast_sys(const int& K, const int& N, const std::vector<bool>& frozen_bits)
: Decoder_polar(K, N),
  l(2*N),
  s(N),
  s_bis(N),
  frozen_bits(frozen_bits)
{
    // Constructor implementation
};

virtual ~Decoder_polar_SC_fast_sys() = default;

void decode(llrvec &llr, bitvec &cw_est, bitvec &info_est)
{
    // Copy the LLRs to the internal buffer
    this->_load(llr);

    // Call the decode function
    this->_decode();

    // Store the decoded bits
    this->_store(cw_est, info_est);
}

protected:

            void print_llr()
            {
            for (auto i = 0; i < 2 * this->N; i++)
            {
                std::cout << this->l[i] << " ";
            }
            std::cout << std::endl;
            }
            void print_s()
            {
            for (auto i = 0; i < this->N; i++)
            {
                std::cout << this->s[i] << " ";
            }
            std::cout << std::endl;
            }

            void set_name(const std::string& name)
            {
            }

            void _load(const llrvec llr)
            {
                std::copy(llr.begin(), llr.end(), this->l.begin());
                std::fill(this->l.begin() + llr.size(), this->l.end(), +std::numeric_limits<float>::infinity());

                std::fill(s.begin(), s.end(), 0);
            }
    virtual void _decode        (){}
            void _store         (bitvec& cw_est, bitvec& info_est)
            {
                auto k = 0;
                for (auto i = 0; i < this->N; i++)
                {
                    if (this->frozen_bits[i] == 0)
                        info_est[k++] = this->s[i];
                }
                std::copy(this->s.begin(), this->s.begin() + cw_est.size(), cw_est.begin());
            }

};
}
}

//  #include "Decoder_polar_SC_fast_sys.hxx"

#endif /* DECODER_POLAR_SC_FAST_SYS_ */
