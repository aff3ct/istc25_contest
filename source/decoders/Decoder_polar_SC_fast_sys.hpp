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
#include "Tools/Code/Polar/Pattern_polar_parser.hpp"
#include "Tools/Code/Polar/Patterns/Pattern_polar_r0.hpp"
#include "Tools/Code/Polar/Patterns/Pattern_polar_r0_left.hpp"
#include "Tools/Code/Polar/Patterns/Pattern_polar_r1.hpp"
#include "Tools/Code/Polar/Patterns/Pattern_polar_rep.hpp"
#include "Tools/Code/Polar/Patterns/Pattern_polar_rep_left.hpp"
#include "Tools/Code/Polar/Patterns/Pattern_polar_spc.hpp"
#include "Tools/Code/Polar/Patterns/Pattern_polar_std.hpp"
#include "Tools/Code/Polar/fb_extract.h"

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
	    tools::Pattern_polar_parser polar_patterns;

public:
Decoder_polar_SC_fast_sys(const int& K, const int& N, const std::vector<bool>& frozen_bits)
: Decoder_polar(K, N),
  l(2*N),
  s(N),
  s_bis(N),
  frozen_bits(frozen_bits),
  polar_patterns(frozen_bits, {new tools::Pattern_polar_std,
                                new tools::Pattern_polar_r0_left,
                                new tools::Pattern_polar_r0,
                                new tools::Pattern_polar_r1,
                                new tools::Pattern_polar_rep_left,
                                new tools::Pattern_polar_rep,
                                new tools::Pattern_polar_spc},
                 2, 3)
{
    // Constructor implementation
};

virtual ~Decoder_polar_SC_fast_sys() = default;

int decode(llrvec &llr, bitvec &cw_est, bitvec &info_est)
{
    // Copy the LLRs to the internal buffer
    this->_load(llr);

    // Call the decode function
    this->_decode();

    // Store the decoded bits
    this->_store(cw_est, info_est);

    return 1;
}

protected:

            static int to_ones(int c)
            {
                return c != 0;
            }
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
            }
    virtual void _decode        (){}
            void _store         (bitvec& cw_est, bitvec& info_est)
            {
                std::transform(this->s.begin(), this->s.end(), this->s.begin(), to_ones);
                tools::fb_extract(this->polar_patterns.get_leaves_pattern_types(), this->s.data(), info_est.data());

                std::copy(this->s.begin(), this->s.begin() + cw_est.size(), cw_est.begin());
            }

};
}
}

#endif /* DECODER_POLAR_SC_FAST_SYS_ */
