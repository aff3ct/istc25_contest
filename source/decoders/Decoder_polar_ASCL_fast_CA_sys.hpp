/*!
* \file
* \brief Class module::Decoder_polar_SCL_fast_CA_sys.
*/
#ifndef DECODER_POLAR_ASCL_FAST_CA_SYS_
#define DECODER_POLAR_ASCL_FAST_CA_SYS_

#include <vector>
#include <cmath>
#include "Decoder_polar.hpp"
#include "CRC.hpp"
#include "Decoder_polar_SC_fast_sys.hpp"
#include "Decoder_polar_SCL_fast_CA_sys.hpp"


namespace aff3ct
{
namespace module
{

class Decoder_polar_ASCL_fast_CA_sys : public Decoder_polar
{

protected:
    Decoder_polar_SC_fast_sys& decoder_SC;
    Decoder_polar_SCL_fast_CA_sys& decoder_CASCL;
    CRC<int>& crc;
    std::vector<int> V_K_SC;

public:
    Decoder_polar_ASCL_fast_CA_sys(const int& K, const int& N, Decoder_polar_SC_fast_sys& decoder_SC, Decoder_polar_SCL_fast_CA_sys& decoder_CASCL, CRC<int>& crc)
    : Decoder_polar(K, N),
      decoder_SC(decoder_SC),
      decoder_CASCL(decoder_CASCL),
      crc(crc),
      V_K_SC(this->K + crc.get_size())
      {}


    virtual ~Decoder_polar_ASCL_fast_CA_sys() = default;

    void decode(llrvec &llr, bitvec &cw_est, bitvec &info_est)
    {
        this->decoder_SC.decode(llr, cw_est, V_K_SC);
        if(crc.check(V_K_SC.data()))
            crc.extract(V_K_SC.data(), info_est.data());
        else
        {
            this->decoder_CASCL.decode(llr, cw_est, info_est);
        }

    }

};
}
}

#endif /* DECODER_POLAR_ASCL_FAST_CA_SYS_ */
