#ifndef DECODER_POLAR_SC_FAST_SYS_N160_K128_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N160_K128_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SC_fast_sys_fb_160_128 = {
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

template <typename API_polar>
class Decoder_polar_SC_fast_sys_N160_K128 : public Decoder_polar_SC_fast_sys
{
public:
	Decoder_polar_SC_fast_sys_N160_K128(const int& K, const int& N, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys(K, N, Decoder_polar_SC_fast_sys_fb_160_128)
	{
		const std::string name = "Decoder_polar_SC_fast_sys_N160_K128";
		this->set_name(name);
		assert(N == 256);
		assert(K == 138);
	}

	virtual ~Decoder_polar_SC_fast_sys_N160_K128()
	{
	}

	void _decode()
	{

		auto &l = this->l;
		auto &s = this->s;

		API_polar::template f  <128>(   l,   0+  0,   0+128,            0+256, 128);
		API_polar::template f  < 64>(   l, 256+  0, 256+ 64,          256+128,  64);
		API_polar::template f  < 32>(   l, 384+  0, 384+ 32,          384+ 64,  32);
		API_polar::template f  < 16>(   l, 448+  0, 448+ 16,          448+ 32,  16);
		API_polar::template f  <  8>(   l, 480+  0, 480+  8,          480+ 16,   8);
		API_polar::template rep<  8>(s, l, 496+  0,                     0+  0,   8);
		API_polar::template gr <  8>(s, l, 480+  0, 480+  8,   0+  0, 480+ 16,   8);
		API_polar::template f  <  4>(   l, 496+  0, 496+  4,          496+  8,   4);
		API_polar::template rep<  4>(s, l, 504+  0,                     8+  0,   4);
		API_polar::template gr <  4>(s, l, 496+  0, 496+  4,   8+  0, 496+  8,   4);
		API_polar::template spc<  4>(s, l, 504+  0,                    12+  0,   4);
		API_polar::template xo <  4>(s,      8+  0,   8+  4,            8+  0,   4);
		API_polar::template xo <  8>(s,      0+  0,   0+  8,            0+  0,   8);
		API_polar::template g  < 16>(s, l, 448+  0, 448+ 16,   0+  0, 448+ 32,  16);
		API_polar::template f  <  8>(   l, 480+  0, 480+  8,          480+ 16,   8);
		API_polar::template f  <  4>(   l, 496+  0, 496+  4,          496+  8,   4);
		API_polar::template rep<  4>(s, l, 504+  0,                    16+  0,   4);
		API_polar::template gr <  4>(s, l, 496+  0, 496+  4,  16+  0, 496+  8,   4);
		API_polar::template spc<  4>(s, l, 504+  0,                    20+  0,   4);
		API_polar::template xo <  4>(s,     16+  0,  16+  4,           16+  0,   4);
		API_polar::template g  <  8>(s, l, 480+  0, 480+  8,  16+  0, 480+ 16,   8);
		API_polar::template spc<  8>(s, l, 496+  0,                    24+  0,   8);
		API_polar::template xo <  8>(s,     16+  0,  16+  8,           16+  0,   8);
		API_polar::template xo < 16>(s,      0+  0,   0+ 16,            0+  0,  16);
		API_polar::template g  < 32>(s, l, 384+  0, 384+ 32,   0+  0, 384+ 64,  32);
		API_polar::template f  < 16>(   l, 448+  0, 448+ 16,          448+ 32,  16);
		API_polar::template f  <  8>(   l, 480+  0, 480+  8,          480+ 16,   8);
		API_polar::template f  <  4>(   l, 496+  0, 496+  4,          496+  8,   4);
		API_polar::template rep<  4>(s, l, 504+  0,                    32+  0,   4);
		API_polar::template gr <  4>(s, l, 496+  0, 496+  4,  32+  0, 496+  8,   4);
		API_polar::template h  <  4>(s, l, 504+  0,                    36+  0,   4);
		API_polar::template xo <  4>(s,     32+  0,  32+  4,           32+  0,   4);
		API_polar::template g  <  8>(s, l, 480+  0, 480+  8,  32+  0, 480+ 16,   8);
		API_polar::template h  <  8>(s, l, 496+  0,                    40+  0,   8);
		API_polar::template xo <  8>(s,     32+  0,  32+  8,           32+  0,   8);
		API_polar::template g  < 16>(s, l, 448+  0, 448+ 16,  32+  0, 448+ 32,  16);
		API_polar::template h  < 16>(s, l, 480+  0,                    48+  0,  16);
		API_polar::template xo < 16>(s,     32+  0,  32+ 16,           32+  0,  16);
		API_polar::template xo < 32>(s,      0+  0,   0+ 32,            0+  0,  32);
		API_polar::template g  < 64>(s, l, 256+  0, 256+ 64,   0+  0, 256+128,  64);
		API_polar::template f  < 32>(   l, 384+  0, 384+ 32,          384+ 64,  32);
		API_polar::template f  < 16>(   l, 448+  0, 448+ 16,          448+ 32,  16);
		API_polar::template f  <  8>(   l, 480+  0, 480+  8,          480+ 16,   8);
		API_polar::template f  <  4>(   l, 496+  0, 496+  4,          496+  8,   4);
		API_polar::template g0 <  2>(   l, 504+  0, 504+  2,          504+  4,   2);
		API_polar::template h  <  2>(s, l, 508+  0,                    66+  0,   2);
		API_polar::template xo0<  2>(s,     64+  2,                    64+  0,   2);
		API_polar::template g  <  4>(s, l, 496+  0, 496+  4,  64+  0, 496+  8,   4);
		API_polar::template h  <  4>(s, l, 504+  0,                    68+  0,   4);
		API_polar::template xo <  4>(s,     64+  0,  64+  4,           64+  0,   4);
		API_polar::template g  <  8>(s, l, 480+  0, 480+  8,  64+  0, 480+ 16,   8);
		API_polar::template h  <  8>(s, l, 496+  0,                    72+  0,   8);
		API_polar::template xo <  8>(s,     64+  0,  64+  8,           64+  0,   8);
		API_polar::template g  < 16>(s, l, 448+  0, 448+ 16,  64+  0, 448+ 32,  16);
		API_polar::template h  < 16>(s, l, 480+  0,                    80+  0,  16);
		API_polar::template xo < 16>(s,     64+  0,  64+ 16,           64+  0,  16);
		API_polar::template g  < 32>(s, l, 384+  0, 384+ 32,  64+  0, 384+ 64,  32);
		API_polar::template h  < 32>(s, l, 448+  0,                    96+  0,  32);
		API_polar::template xo < 32>(s,     64+  0,  64+ 32,           64+  0,  32);
		API_polar::template xo < 64>(s,      0+  0,   0+ 64,            0+  0,  64);
		API_polar::template g  <128>(s, l,   0+  0,   0+128,   0+  0,   0+256, 128);
		API_polar::template f  < 64>(   l, 256+  0, 256+ 64,          256+128,  64);
		API_polar::template f  < 32>(   l, 384+  0, 384+ 32,          384+ 64,  32);
		API_polar::template spc< 32>(s, l, 448+  0,                   128+  0,  32);
		API_polar::template g  < 32>(s, l, 384+  0, 384+ 32, 128+  0, 384+ 64,  32);
		API_polar::template xo < 32>(s,    128+  0, 128+ 32,          128+  0,  32);
		API_polar::template g  < 64>(s, l, 256+  0, 256+ 64, 128+  0, 256+128,  64);
		API_polar::template xo < 64>(s,    128+  0, 128+ 64,          128+  0,  64);
		API_polar::template xo <128>(s,      0+  0,   0+128,            0+  0, 128);
	}
};
}
}
#endif
