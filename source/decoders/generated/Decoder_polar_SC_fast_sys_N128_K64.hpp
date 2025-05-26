#ifndef DECODER_POLAR_SC_FAST_SYS_N128_K64_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N128_K64_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SC_fast_sys_fb_128_64 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

template <typename API_polar>
class Decoder_polar_SC_fast_sys_N128_K64 : public Decoder_polar_SC_fast_sys
{
public:
	Decoder_polar_SC_fast_sys_N128_K64(const int& K, const int& N, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys(K, N, Decoder_polar_SC_fast_sys_fb_128_64)
	{
		const std::string name = "Decoder_polar_SC_fast_sys_N128_K64";
		this->set_name(name);
		assert(N == 128);
		assert(K == 71);
	}

	virtual ~Decoder_polar_SC_fast_sys_N128_K64()
	{
	}

	void _decode()
	{

		auto &l = this->l;
		auto &s = this->s;

		API_polar::template f  <64>(   l,   0+  0,   0+ 64,            0+128, 64);
		API_polar::template f  <32>(   l, 128+  0, 128+ 32,          128+ 64, 32);
		API_polar::template g0 <16>(   l, 192+  0, 192+ 16,          192+ 32, 16);
		API_polar::template g0 < 8>(   l, 224+  0, 224+  8,          224+ 16,  8);
		API_polar::template f  < 4>(   l, 240+  0, 240+  4,          240+  8,  4);
		API_polar::template rep< 4>(s, l, 248+  0,                    24+  0,  4);
		API_polar::template gr < 4>(s, l, 240+  0, 240+  4,  24+  0, 240+  8,  4);
		API_polar::template spc< 4>(s, l, 248+  0,                    28+  0,  4);
		API_polar::template xo < 4>(s,     24+  0,  24+  4,           24+  0,  4);
		API_polar::template xo0< 8>(s,     16+  8,                    16+  0,  8);
		API_polar::template xo0<16>(s,      0+ 16,                     0+  0, 16);
		API_polar::template g  <32>(s, l, 128+  0, 128+ 32,   0+  0, 128+ 64, 32);
		API_polar::template f  <16>(   l, 192+  0, 192+ 16,          192+ 32, 16);
		API_polar::template f  < 8>(   l, 224+  0, 224+  8,          224+ 16,  8);
		API_polar::template rep< 8>(s, l, 240+  0,                    32+  0,  8);
		API_polar::template gr < 8>(s, l, 224+  0, 224+  8,  32+  0, 224+ 16,  8);
		API_polar::template f  < 4>(   l, 240+  0, 240+  4,          240+  8,  4);
		API_polar::template rep< 4>(s, l, 248+  0,                    40+  0,  4);
		API_polar::template gr < 4>(s, l, 240+  0, 240+  4,  40+  0, 240+  8,  4);
		API_polar::template spc< 4>(s, l, 248+  0,                    44+  0,  4);
		API_polar::template xo < 4>(s,     40+  0,  40+  4,           40+  0,  4);
		API_polar::template xo < 8>(s,     32+  0,  32+  8,           32+  0,  8);
		API_polar::template g  <16>(s, l, 192+  0, 192+ 16,  32+  0, 192+ 32, 16);
		API_polar::template f  < 8>(   l, 224+  0, 224+  8,          224+ 16,  8);
		API_polar::template f  < 4>(   l, 240+  0, 240+  4,          240+  8,  4);
		API_polar::template rep< 4>(s, l, 248+  0,                    48+  0,  4);
		API_polar::template gr < 4>(s, l, 240+  0, 240+  4,  48+  0, 240+  8,  4);
		API_polar::template spc< 4>(s, l, 248+  0,                    52+  0,  4);
		API_polar::template xo < 4>(s,     48+  0,  48+  4,           48+  0,  4);
		API_polar::template g  < 8>(s, l, 224+  0, 224+  8,  48+  0, 224+ 16,  8);
		API_polar::template h  < 8>(s, l, 240+  0,                    56+  0,  8);
		API_polar::template xo < 8>(s,     48+  0,  48+  8,           48+  0,  8);
		API_polar::template xo <16>(s,     32+  0,  32+ 16,           32+  0, 16);
		API_polar::template xo <32>(s,      0+  0,   0+ 32,            0+  0, 32);
		API_polar::template g  <64>(s, l,   0+  0,   0+ 64,   0+  0,   0+128, 64);
		API_polar::template f  <32>(   l, 128+  0, 128+ 32,          128+ 64, 32);
		API_polar::template f  <16>(   l, 192+  0, 192+ 16,          192+ 32, 16);
		API_polar::template f  < 8>(   l, 224+  0, 224+  8,          224+ 16,  8);
		API_polar::template rep< 8>(s, l, 240+  0,                    64+  0,  8);
		API_polar::template gr < 8>(s, l, 224+  0, 224+  8,  64+  0, 224+ 16,  8);
		API_polar::template f  < 4>(   l, 240+  0, 240+  4,          240+  8,  4);
		API_polar::template rep< 4>(s, l, 248+  0,                    72+  0,  4);
		API_polar::template gr < 4>(s, l, 240+  0, 240+  4,  72+  0, 240+  8,  4);
		API_polar::template spc< 4>(s, l, 248+  0,                    76+  0,  4);
		API_polar::template xo < 4>(s,     72+  0,  72+  4,           72+  0,  4);
		API_polar::template xo < 8>(s,     64+  0,  64+  8,           64+  0,  8);
		API_polar::template g  <16>(s, l, 192+  0, 192+ 16,  64+  0, 192+ 32, 16);
		API_polar::template f  < 8>(   l, 224+  0, 224+  8,          224+ 16,  8);
		API_polar::template f  < 4>(   l, 240+  0, 240+  4,          240+  8,  4);
		API_polar::template g0 < 2>(   l, 248+  0, 248+  2,          248+  4,  2);
		API_polar::template h  < 2>(s, l, 252+  0,                    82+  0,  2);
		API_polar::template xo0< 2>(s,     80+  2,                    80+  0,  2);
		API_polar::template g  < 4>(s, l, 240+  0, 240+  4,  80+  0, 240+  8,  4);
		API_polar::template h  < 4>(s, l, 248+  0,                    84+  0,  4);
		API_polar::template xo < 4>(s,     80+  0,  80+  4,           80+  0,  4);
		API_polar::template g  < 8>(s, l, 224+  0, 224+  8,  80+  0, 224+ 16,  8);
		API_polar::template h  < 8>(s, l, 240+  0,                    88+  0,  8);
		API_polar::template xo < 8>(s,     80+  0,  80+  8,           80+  0,  8);
		API_polar::template xo <16>(s,     64+  0,  64+ 16,           64+  0, 16);
		API_polar::template g  <32>(s, l, 128+  0, 128+ 32,  64+  0, 128+ 64, 32);
		API_polar::template spc<32>(s, l, 192+  0,                    96+  0, 32);
		API_polar::template xo <32>(s,     64+  0,  64+ 32,           64+  0, 32);
		API_polar::template xo <64>(s,      0+  0,   0+ 64,            0+  0, 64);
	}
};
}
}
#endif
