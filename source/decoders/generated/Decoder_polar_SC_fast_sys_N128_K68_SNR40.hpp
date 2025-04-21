#ifndef DECODER_POLAR_SC_FAST_SYS_N128_K68_SNR40_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N128_K68_SNR40_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SC_fast_sys_fb_128_68_40 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

class Decoder_polar_SC_fast_sys_N128_K68_SNR40 : public Decoder_polar_SC_fast_sys
{
public:
	Decoder_polar_SC_fast_sys_N128_K68_SNR40(const int& K, const int& N, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys(K, N, Decoder_polar_SC_fast_sys_fb_128_68_40)
	{
		const std::string name = "Decoder_polar_SC_fast_sys_N128_K68_SNR40";
		this->set_name(name);
		assert(N == 128);
		assert(K == 68);
	}

	virtual ~Decoder_polar_SC_fast_sys_N128_K68_SNR40()
	{
	}

	void _decode()
	{

		auto &l = this->l;
		auto &s = this->s;

		rep<128>(s, l,   0+  0,                     0+  0, 128);
	}
};
}
}
#endif
