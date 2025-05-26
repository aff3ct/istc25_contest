#ifndef DECODER_POLAR_SC_FAST_SYS_N320_K256_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N320_K256_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SC_fast_sys_fb_320_256 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

template <typename API_polar>
class Decoder_polar_SC_fast_sys_N320_K256 : public Decoder_polar_SC_fast_sys
{
public:
	Decoder_polar_SC_fast_sys_N320_K256(const int& K, const int& N, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys(K, N, Decoder_polar_SC_fast_sys_fb_320_256)
	{
		const std::string name = "Decoder_polar_SC_fast_sys_N320_K256";
		this->set_name(name);
		assert(N == 512);
		assert(K == 266);
	}

	virtual ~Decoder_polar_SC_fast_sys_N320_K256()
	{
	}

	void _decode()
	{

		auto &l = this->l;
		auto &s = this->s;

		API_polar::template f  <256>(   l,    0+   0,    0+ 256,               0+ 512, 256);
		API_polar::template f  <128>(   l,  512+   0,  512+ 128,             512+ 256, 128);
		API_polar::template f  < 64>(   l,  768+   0,  768+  64,             768+ 128,  64);
		API_polar::template f  < 32>(   l,  896+   0,  896+  32,             896+  64,  32);
		API_polar::template f  < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template rep< 16>(s, l,  992+   0,                          0+   0,  16);
		API_polar::template gr < 16>(s, l,  960+   0,  960+  16,    0+   0,  960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template rep<  8>(s, l, 1008+   0,                         16+   0,   8);
		API_polar::template gr <  8>(s, l,  992+   0,  992+   8,   16+   0,  992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template rep<  4>(s, l, 1016+   0,                         24+   0,   4);
		API_polar::template gr <  4>(s, l, 1008+   0, 1008+   4,   24+   0, 1008+   8,   4);
		API_polar::template h  <  4>(s, l, 1016+   0,                         28+   0,   4);
		API_polar::template xo <  4>(s,      24+   0,   24+   4,              24+   0,   4);
		API_polar::template xo <  8>(s,      16+   0,   16+   8,              16+   0,   8);
		API_polar::template xo < 16>(s,       0+   0,    0+  16,               0+   0,  16);
		API_polar::template g  < 32>(s, l,  896+   0,  896+  32,    0+   0,  896+  64,  32);
		API_polar::template f  < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template rep<  8>(s, l, 1008+   0,                         32+   0,   8);
		API_polar::template gr <  8>(s, l,  992+   0,  992+   8,   32+   0,  992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template g0 <  2>(   l, 1016+   0, 1016+   2,            1016+   4,   2);
		API_polar::template h  <  2>(s, l, 1020+   0,                         42+   0,   2);
		API_polar::template xo0<  2>(s,      40+   2,                         40+   0,   2);
		API_polar::template g  <  4>(s, l, 1008+   0, 1008+   4,   40+   0, 1008+   8,   4);
		API_polar::template h  <  4>(s, l, 1016+   0,                         44+   0,   4);
		API_polar::template xo <  4>(s,      40+   0,   40+   4,              40+   0,   4);
		API_polar::template xo <  8>(s,      32+   0,   32+   8,              32+   0,   8);
		API_polar::template g  < 16>(s, l,  960+   0,  960+  16,   32+   0,  960+  32,  16);
		API_polar::template spc< 16>(s, l,  992+   0,                         48+   0,  16);
		API_polar::template xo < 16>(s,      32+   0,   32+  16,              32+   0,  16);
		API_polar::template xo < 32>(s,       0+   0,    0+  32,               0+   0,  32);
		API_polar::template g  < 64>(s, l,  768+   0,  768+  64,    0+   0,  768+ 128,  64);
		API_polar::template f  < 32>(   l,  896+   0,  896+  32,             896+  64,  32);
		API_polar::template f  < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template g0 <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template spc<  4>(s, l, 1016+   0,                         68+   0,   4);
		API_polar::template xo0<  4>(s,      64+   4,                         64+   0,   4);
		API_polar::template g  <  8>(s, l,  992+   0,  992+   8,   64+   0,  992+  16,   8);
		API_polar::template spc<  8>(s, l, 1008+   0,                         72+   0,   8);
		API_polar::template xo <  8>(s,      64+   0,   64+   8,              64+   0,   8);
		API_polar::template g  < 16>(s, l,  960+   0,  960+  16,   64+   0,  960+  32,  16);
		API_polar::template spc< 16>(s, l,  992+   0,                         80+   0,  16);
		API_polar::template xo < 16>(s,      64+   0,   64+  16,              64+   0,  16);
		API_polar::template g  < 32>(s, l,  896+   0,  896+  32,   64+   0,  896+  64,  32);
		API_polar::template spc< 32>(s, l,  960+   0,                         96+   0,  32);
		API_polar::template xo < 32>(s,      64+   0,   64+  32,              64+   0,  32);
		API_polar::template xo < 64>(s,       0+   0,    0+  64,               0+   0,  64);
		API_polar::template g  <128>(s, l,  512+   0,  512+ 128,    0+   0,  512+ 256, 128);
		API_polar::template f  < 64>(   l,  768+   0,  768+  64,             768+ 128,  64);
		API_polar::template f  < 32>(   l,  896+   0,  896+  32,             896+  64,  32);
		API_polar::template f  < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template rep<  4>(s, l, 1016+   0,                        128+   0,   4);
		API_polar::template gr <  4>(s, l, 1008+   0, 1008+   4,  128+   0, 1008+   8,   4);
		API_polar::template spc<  4>(s, l, 1016+   0,                        132+   0,   4);
		API_polar::template xo <  4>(s,     128+   0,  128+   4,             128+   0,   4);
		API_polar::template g  <  8>(s, l,  992+   0,  992+   8,  128+   0,  992+  16,   8);
		API_polar::template spc<  8>(s, l, 1008+   0,                        136+   0,   8);
		API_polar::template xo <  8>(s,     128+   0,  128+   8,             128+   0,   8);
		API_polar::template g  < 16>(s, l,  960+   0,  960+  16,  128+   0,  960+  32,  16);
		API_polar::template spc< 16>(s, l,  992+   0,                        144+   0,  16);
		API_polar::template xo < 16>(s,     128+   0,  128+  16,             128+   0,  16);
		API_polar::template g  < 32>(s, l,  896+   0,  896+  32,  128+   0,  896+  64,  32);
		API_polar::template h  < 32>(s, l,  960+   0,                        160+   0,  32);
		API_polar::template xo < 32>(s,     128+   0,  128+  32,             128+   0,  32);
		API_polar::template g  < 64>(s, l,  768+   0,  768+  64,  128+   0,  768+ 128,  64);
		API_polar::template h  < 64>(s, l,  896+   0,                        192+   0,  64);
		API_polar::template xo < 64>(s,     128+   0,  128+  64,             128+   0,  64);
		API_polar::template xo <128>(s,       0+   0,    0+ 128,               0+   0, 128);
		API_polar::template g  <256>(s, l,    0+   0,    0+ 256,    0+   0,    0+ 512, 256);
		API_polar::template f  <128>(   l,  512+   0,  512+ 128,             512+ 256, 128);
		API_polar::template f  < 64>(   l,  768+   0,  768+  64,             768+ 128,  64);
		API_polar::template f  < 32>(   l,  896+   0,  896+  32,             896+  64,  32);
		API_polar::template f  < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template rep<  4>(s, l, 1016+   0,                        256+   0,   4);
		API_polar::template gr <  4>(s, l, 1008+   0, 1008+   4,  256+   0, 1008+   8,   4);
		API_polar::template spc<  4>(s, l, 1016+   0,                        260+   0,   4);
		API_polar::template xo <  4>(s,     256+   0,  256+   4,             256+   0,   4);
		API_polar::template g  <  8>(s, l,  992+   0,  992+   8,  256+   0,  992+  16,   8);
		API_polar::template spc<  8>(s, l, 1008+   0,                        264+   0,   8);
		API_polar::template xo <  8>(s,     256+   0,  256+   8,             256+   0,   8);
		API_polar::template g  < 16>(s, l,  960+   0,  960+  16,  256+   0,  960+  32,  16);
		API_polar::template h  < 16>(s, l,  992+   0,                        272+   0,  16);
		API_polar::template xo < 16>(s,     256+   0,  256+  16,             256+   0,  16);
		API_polar::template g  < 32>(s, l,  896+   0,  896+  32,  256+   0,  896+  64,  32);
		API_polar::template h  < 32>(s, l,  960+   0,                        288+   0,  32);
		API_polar::template xo < 32>(s,     256+   0,  256+  32,             256+   0,  32);
		API_polar::template g  < 64>(s, l,  768+   0,  768+  64,  256+   0,  768+ 128,  64);
		API_polar::template xo < 64>(s,     256+   0,  256+  64,             256+   0,  64);
		API_polar::template g  <128>(s, l,  512+   0,  512+ 128,  256+   0,  512+ 256, 128);
		API_polar::template xo <128>(s,     256+   0,  256+ 128,             256+   0, 128);
		API_polar::template xo <256>(s,       0+   0,    0+ 256,               0+   0, 256);
	}
};
}
}
#endif
