/*!
 * \file
 * \brief Class module::Decoder_polar_SC_fast_sys.
 */
 #ifndef DECODER_POLAR
 #define DECODER_POLAR

 #include <vector>
 #include <cmath>
 #include "polar_functions.hpp"

namespace aff3ct
{
namespace module
{

class Decoder_polar
{
protected:
    const int              K;            // number of information bits
    const int              N;            // number of codeword bits
    const int              m;            // graph depth

public:
    Decoder_polar(const int& K, const int& N) :
        K(K),
        N(N),
        m((int)std::log2(N))
    {
        // Constructor implementation
    }
    virtual ~Decoder_polar() = default;

    virtual int decode(llrvec &llr, bitvec &cw_est, bitvec &info_est) = 0;
};

}
}

#endif