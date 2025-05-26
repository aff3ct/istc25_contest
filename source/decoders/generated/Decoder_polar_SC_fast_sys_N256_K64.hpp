#ifndef DECODER_POLAR_SC_FAST_SYS_N256_K64_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N256_K64_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SC_fast_sys_fb_256_64 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

template <typename API_polar>
class Decoder_polar_SC_fast_sys_N256_K64 : public Decoder_polar_SC_fast_sys
{
public:
	Decoder_polar_SC_fast_sys_N256_K64(const int& K, const int& N, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys(K, N, Decoder_polar_SC_fast_sys_fb_256_64)
	{
		const std::string name = "Decoder_polar_SC_fast_sys_N256_K64";
		this->set_name(name);
		assert(N == 256);
		assert(K == 75);
	}

	virtual ~Decoder_polar_SC_fast_sys_N256_K64()
	{
	}

	void _decode()
	{

		auto &l = this->l;
		auto &s = this->s;

		API_polar::template f  <128>(   l,   0+  0,   0+128,            0+256, 128);
		API_polar::template f  < 64>(   l, 256+  0, 256+ 64,          256+128,  64);
		API_polar::template rep< 64>(s, l, 384+  0,                     0+  0,  64);
		API_polar::template gr < 64>(s, l, 256+  0, 256+ 64,   0+  0, 256+128,  64);
		API_polar::template f  < 32>(   l, 384+  0, 384+ 32,          384+ 64,  32);
		API_polar::template rep< 32>(s, l, 448+  0,                    64+  0,  32);
		API_polar::template gr < 32>(s, l, 384+  0, 384+ 32,  64+  0, 384+ 64,  32);
		API_polar::template f  < 16>(   l, 448+  0, 448+ 16,          448+ 32,  16);
		API_polar::template rep< 16>(s, l, 480+  0,                    96+  0,  16);
		API_polar::template gr < 16>(s, l, 448+  0, 448+ 16,  96+  0, 448+ 32,  16);
		API_polar::template f  <  8>(   l, 480+  0, 480+  8,          480+ 16,   8);
		API_polar::template g0 <  4>(   l, 496+  0, 496+  4,          496+  8,   4);
		API_polar::template g0 <  2>(   l, 504+  0, 504+  2,          504+  4,   2);
		API_polar::template h  <  2>(s, l, 508+  0,                   118+  0,   2);
		API_polar::template xo0<  2>(s,    116+  2,                   116+  0,   2);
		API_polar::template xo0<  4>(s,    112+  4,                   112+  0,   4);
		API_polar::template g  <  8>(s, l, 480+  0, 480+  8, 112+  0, 480+ 16,   8);
		API_polar::template spc<  8>(s, l, 496+  0,                   120+  0,   8);
		API_polar::template xo <  8>(s,    112+  0, 112+  8,          112+  0,   8);
		API_polar::template xo < 16>(s,     96+  0,  96+ 16,           96+  0,  16);
		API_polar::template xo < 32>(s,     64+  0,  64+ 32,           64+  0,  32);
		API_polar::template xo < 64>(s,      0+  0,   0+ 64,            0+  0,  64);
		API_polar::template g  <128>(s, l,   0+  0,   0+128,   0+  0,   0+256, 128);
		API_polar::template f  < 64>(   l, 256+  0, 256+ 64,          256+128,  64);
		API_polar::template f  < 32>(   l, 384+  0, 384+ 32,          384+ 64,  32);
		API_polar::template g0 < 16>(   l, 448+  0, 448+ 16,          448+ 32,  16);
		API_polar::template g0 <  8>(   l, 480+  0, 480+  8,          480+ 16,   8);
		API_polar::template g0 <  4>(   l, 496+  0, 496+  4,          496+  8,   4);
		API_polar::template g0 <  2>(   l, 504+  0, 504+  2,          504+  4,   2);
		API_polar::template h  <  2>(s, l, 508+  0,                   158+  0,   2);
		API_polar::template xo0<  2>(s,    156+  2,                   156+  0,   2);
		API_polar::template xo0<  4>(s,    152+  4,                   152+  0,   4);
		API_polar::template xo0<  8>(s,    144+  8,                   144+  0,   8);
		API_polar::template xo0< 16>(s,    128+ 16,                   128+  0,  16);
		API_polar::template g  < 32>(s, l, 384+  0, 384+ 32, 128+  0, 384+ 64,  32);
		API_polar::template f  < 16>(   l, 448+  0, 448+ 16,          448+ 32,  16);
		API_polar::template g0 <  8>(   l, 480+  0, 480+  8,          480+ 16,   8);
		API_polar::template g0 <  4>(   l, 496+  0, 496+  4,          496+  8,   4);
		API_polar::template spc<  4>(s, l, 504+  0,                   172+  0,   4);
		API_polar::template xo0<  4>(s,    168+  4,                   168+  0,   4);
		API_polar::template xo0<  8>(s,    160+  8,                   160+  0,   8);
		API_polar::template g  < 16>(s, l, 448+  0, 448+ 16, 160+  0, 448+ 32,  16);
		API_polar::template f  <  8>(   l, 480+  0, 480+  8,          480+ 16,   8);
		API_polar::template f  <  4>(   l, 496+  0, 496+  4,          496+  8,   4);
		API_polar::template rep<  4>(s, l, 504+  0,                   176+  0,   4);
		API_polar::template gr <  4>(s, l, 496+  0, 496+  4, 176+  0, 496+  8,   4);
		API_polar::template spc<  4>(s, l, 504+  0,                   180+  0,   4);
		API_polar::template xo <  4>(s,    176+  0, 176+  4,          176+  0,   4);
		API_polar::template g  <  8>(s, l, 480+  0, 480+  8, 176+  0, 480+ 16,   8);
		API_polar::template spc<  8>(s, l, 496+  0,                   184+  0,   8);
		API_polar::template xo <  8>(s,    176+  0, 176+  8,          176+  0,   8);
		API_polar::template xo < 16>(s,    160+  0, 160+ 16,          160+  0,  16);
		API_polar::template xo < 32>(s,    128+  0, 128+ 32,          128+  0,  32);
		API_polar::template g  < 64>(s, l, 256+  0, 256+ 64, 128+  0, 256+128,  64);
		API_polar::template f  < 32>(   l, 384+  0, 384+ 32,          384+ 64,  32);
		API_polar::template f  < 16>(   l, 448+  0, 448+ 16,          448+ 32,  16);
		API_polar::template f  <  8>(   l, 480+  0, 480+  8,          480+ 16,   8);
		API_polar::template rep<  8>(s, l, 496+  0,                   192+  0,   8);
		API_polar::template gr <  8>(s, l, 480+  0, 480+  8, 192+  0, 480+ 16,   8);
		API_polar::template f  <  4>(   l, 496+  0, 496+  4,          496+  8,   4);
		API_polar::template rep<  4>(s, l, 504+  0,                   200+  0,   4);
		API_polar::template gr <  4>(s, l, 496+  0, 496+  4, 200+  0, 496+  8,   4);
		API_polar::template spc<  4>(s, l, 504+  0,                   204+  0,   4);
		API_polar::template xo <  4>(s,    200+  0, 200+  4,          200+  0,   4);
		API_polar::template xo <  8>(s,    192+  0, 192+  8,          192+  0,   8);
		API_polar::template g  < 16>(s, l, 448+  0, 448+ 16, 192+  0, 448+ 32,  16);
		API_polar::template f  <  8>(   l, 480+  0, 480+  8,          480+ 16,   8);
		API_polar::template f  <  4>(   l, 496+  0, 496+  4,          496+  8,   4);
		API_polar::template rep<  4>(s, l, 504+  0,                   208+  0,   4);
		API_polar::template gr <  4>(s, l, 496+  0, 496+  4, 208+  0, 496+  8,   4);
		API_polar::template spc<  4>(s, l, 504+  0,                   212+  0,   4);
		API_polar::template xo <  4>(s,    208+  0, 208+  4,          208+  0,   4);
		API_polar::template g  <  8>(s, l, 480+  0, 480+  8, 208+  0, 480+ 16,   8);
		API_polar::template h  <  8>(s, l, 496+  0,                   216+  0,   8);
		API_polar::template xo <  8>(s,    208+  0, 208+  8,          208+  0,   8);
		API_polar::template xo < 16>(s,    192+  0, 192+ 16,          192+  0,  16);
		API_polar::template g  < 32>(s, l, 384+  0, 384+ 32, 192+  0, 384+ 64,  32);
		API_polar::template f  < 16>(   l, 448+  0, 448+ 16,          448+ 32,  16);
		API_polar::template f  <  8>(   l, 480+  0, 480+  8,          480+ 16,   8);
		API_polar::template f  <  4>(   l, 496+  0, 496+  4,          496+  8,   4);
		API_polar::template g0 <  2>(   l, 504+  0, 504+  2,          504+  4,   2);
		API_polar::template h  <  2>(s, l, 508+  0,                   226+  0,   2);
		API_polar::template xo0<  2>(s,    224+  2,                   224+  0,   2);
		API_polar::template g  <  4>(s, l, 496+  0, 496+  4, 224+  0, 496+  8,   4);
		API_polar::template h  <  4>(s, l, 504+  0,                   228+  0,   4);
		API_polar::template xo <  4>(s,    224+  0, 224+  4,          224+  0,   4);
		API_polar::template g  <  8>(s, l, 480+  0, 480+  8, 224+  0, 480+ 16,   8);
		API_polar::template h  <  8>(s, l, 496+  0,                   232+  0,   8);
		API_polar::template xo <  8>(s,    224+  0, 224+  8,          224+  0,   8);
		API_polar::template g  < 16>(s, l, 448+  0, 448+ 16, 224+  0, 448+ 32,  16);
		API_polar::template h  < 16>(s, l, 480+  0,                   240+  0,  16);
		API_polar::template xo < 16>(s,    224+  0, 224+ 16,          224+  0,  16);
		API_polar::template xo < 32>(s,    192+  0, 192+ 32,          192+  0,  32);
		API_polar::template xo < 64>(s,    128+  0, 128+ 64,          128+  0,  64);
		API_polar::template xo <128>(s,      0+  0,   0+128,            0+  0, 128);
	}
};
}
}
#endif
