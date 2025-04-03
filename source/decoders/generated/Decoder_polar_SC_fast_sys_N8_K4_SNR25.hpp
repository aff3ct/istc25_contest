#ifndef DECODER_POLAR_SC_FAST_SYS_N8_K4_SNR25_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N8_K4_SNR25_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SC_fast_sys_fb_8_4_25 = {
1, 1, 1, 0, 1, 0, 0, 0};

class Decoder_polar_SC_fast_sys_N8_K4_SNR25 : public Decoder_polar_SC_fast_sys
{
public:
	Decoder_polar_SC_fast_sys_N8_K4_SNR25(const int& K, const int& N, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys(K, N, Decoder_polar_SC_fast_sys_fb_8_4_25)
	{
		const std::string name = "Decoder_polar_SC_fast_sys_N8_K4_SNR25";
		this->set_name(name);
		assert(N == 8);
		assert(K == 4);
	}

	virtual ~Decoder_polar_SC_fast_sys_N8_K4_SNR25()
	{
	}

	void _decode()
	{

		auto &l = this->l;
		auto &s = this->s;

		f  <4>(   l,  0+ 0,  0+ 4,         0+ 8, 4);
		rep<4>(s, l,  8+ 0,                0+ 0, 4);
		gr <4>(s, l,  0+ 0,  0+ 4,  0+ 0,  0+ 8, 4);
		spc<4>(s, l,  8+ 0,                4+ 0, 4);
		xo <4>(s,     0+ 0,  0+ 4,         0+ 0, 4);
	}
};
}
}
#endif
