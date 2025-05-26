#ifndef DECODER_POLAR_SC_FAST_SYS_N80_K64_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N80_K64_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SC_fast_sys_fb_80_64 = {
1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

template <typename API_polar>
class Decoder_polar_SC_fast_sys_N80_K64 : public Decoder_polar_SC_fast_sys
{
public:
	Decoder_polar_SC_fast_sys_N80_K64(const int& K, const int& N, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys(K, N, Decoder_polar_SC_fast_sys_fb_80_64)
	{
		const std::string name = "Decoder_polar_SC_fast_sys_N80_K64";
		this->set_name(name);
		assert(N == 128);
		assert(K == 72);
	}

	virtual ~Decoder_polar_SC_fast_sys_N80_K64()
	{
	}

	void _decode()
	{

		auto &l = this->l;
		auto &s = this->s;

		API_polar::template f  <64>(   l,   0+  0,   0+ 64,            0+128, 64);
		API_polar::template f  <32>(   l, 128+  0, 128+ 32,          128+ 64, 32);
		API_polar::template f  <16>(   l, 192+  0, 192+ 16,          192+ 32, 16);
		API_polar::template f  < 8>(   l, 224+  0, 224+  8,          224+ 16,  8);
		API_polar::template g0 < 4>(   l, 240+  0, 240+  4,          240+  8,  4);
		API_polar::template spc< 4>(s, l, 248+  0,                     4+  0,  4);
		API_polar::template xo0< 4>(s,      0+  4,                     0+  0,  4);
		API_polar::template g  < 8>(s, l, 224+  0, 224+  8,   0+  0, 224+ 16,  8);
		API_polar::template spc< 8>(s, l, 240+  0,                     8+  0,  8);
		API_polar::template xo < 8>(s,      0+  0,   0+  8,            0+  0,  8);
		API_polar::template g  <16>(s, l, 192+  0, 192+ 16,   0+  0, 192+ 32, 16);
		API_polar::template spc<16>(s, l, 224+  0,                    16+  0, 16);
		API_polar::template xo <16>(s,      0+  0,   0+ 16,            0+  0, 16);
		API_polar::template g  <32>(s, l, 128+  0, 128+ 32,   0+  0, 128+ 64, 32);
		API_polar::template spc<32>(s, l, 192+  0,                    32+  0, 32);
		API_polar::template xo <32>(s,      0+  0,   0+ 32,            0+  0, 32);
		API_polar::template g  <64>(s, l,   0+  0,   0+ 64,   0+  0,   0+128, 64);
		API_polar::template f  <32>(   l, 128+  0, 128+ 32,          128+ 64, 32);
		API_polar::template f  <16>(   l, 192+  0, 192+ 16,          192+ 32, 16);
		API_polar::template h  <16>(s, l, 224+  0,                    64+  0, 16);
		API_polar::template g  <16>(s, l, 192+  0, 192+ 16,  64+  0, 192+ 32, 16);
		API_polar::template xo <16>(s,     64+  0,  64+ 16,           64+  0, 16);
		API_polar::template g  <32>(s, l, 128+  0, 128+ 32,  64+  0, 128+ 64, 32);
		API_polar::template xo <32>(s,     64+  0,  64+ 32,           64+  0, 32);
		API_polar::template xo <64>(s,      0+  0,   0+ 64,            0+  0, 64);
	}
};
}
}
#endif
