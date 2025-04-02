#ifndef DECODER_POLAR_SC_FAST_SYS_N64_K32_SNR25_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N64_K32_SNR25_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"
#include "../polar_functions.hpp"


namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SC_fast_sys_fb_64_32_25 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0,
1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

class Decoder_polar_SC_fast_sys_N64_K32_SNR25 : public Decoder_polar_SC_fast_sys
{
public:
	Decoder_polar_SC_fast_sys_N64_K32_SNR25(const int& K, const int& N, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys(K, N, Decoder_polar_SC_fast_sys_fb_64_32_25)
	{
		const std::string name = "Decoder_polar_SC_fast_sys_N64_K32_SNR25";
		assert(N == 64);
		assert(K == 32);
	}

	virtual ~Decoder_polar_SC_fast_sys_N64_K32_SNR25()
	{
	}

	void _decode()
	{

		auto &l = this->l;
		auto &s = this->s;

		f  <32>(   l,   0+  0,   0+ 32,            0+ 64, 32);
		f  <16>(   l,  64+  0,  64+ 16,           64+ 32, 16);
		rep<16>(s, l,  96+  0,                     0+  0, 16);
		gr <16>(s, l,  64+  0,  64+ 16,   0+  0,  64+ 32, 16);
		f  < 8>(   l,  96+  0,  96+  8,           96+ 16,  8);
		rep< 8>(s, l, 112+  0,                    16+  0,  8);
		gr < 8>(s, l,  96+  0,  96+  8,  16+  0,  96+ 16,  8);
		f  < 4>(   l, 112+  0, 112+  4,          112+  8,  4);
		g0 < 2>(   l, 120+  0, 120+  2,          120+  4,  2);
		h  < 2>(s, l, 124+  0,                    26+  0,  2);
		xo0< 2>(s,     24+  2,                    24+  0,  2);
		g  < 4>(s, l, 112+  0, 112+  4,  24+  0, 112+  8,  4);
		h  < 4>(s, l, 120+  0,                    28+  0,  4);
		xo < 4>(s,     24+  0,  24+  4,           24+  0,  4);
		xo < 8>(s,     16+  0,  16+  8,           16+  0,  8);
		xo <16>(s,      0+  0,   0+ 16,            0+  0, 16);
		g  <32>(s, l,   0+  0,   0+ 32,   0+  0,   0+ 64, 32);
		f  <16>(   l,  64+  0,  64+ 16,           64+ 32, 16);
		f  < 8>(   l,  96+  0,  96+  8,           96+ 16,  8);
		g0 < 4>(   l, 112+  0, 112+  4,          112+  8,  4);
		g0 < 2>(   l, 120+  0, 120+  2,          120+  4,  2);
		h  < 2>(s, l, 124+  0,                    38+  0,  2);
		xo0< 2>(s,     36+  2,                    36+  0,  2);
		xo0< 4>(s,     32+  4,                    32+  0,  4);
		g  < 8>(s, l,  96+  0,  96+  8,  32+  0,  96+ 16,  8);
		spc< 8>(s, l, 112+  0,                    40+  0,  8);
		xo < 8>(s,     32+  0,  32+  8,           32+  0,  8);
		g  <16>(s, l,  64+  0,  64+ 16,  32+  0,  64+ 32, 16);
		spc<16>(s, l,  96+  0,                    48+  0, 16);
		xo <16>(s,     32+  0,  32+ 16,           32+  0, 16);
		xo <32>(s,      0+  0,   0+ 32,            0+  0, 32);
	}
};
}
}
#endif
