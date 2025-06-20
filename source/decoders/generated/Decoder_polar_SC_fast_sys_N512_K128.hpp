#ifndef DECODER_POLAR_SC_FAST_SYS_N512_K128_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N512_K128_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SC_fast_sys_fb_512_128 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

template <typename API_polar>
class Decoder_polar_SC_fast_sys_N512_K128 : public Decoder_polar_SC_fast_sys
{
public:
	Decoder_polar_SC_fast_sys_N512_K128(const int& K, const int& N, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys(K, N, Decoder_polar_SC_fast_sys_fb_512_128)
	{
		const std::string name = "Decoder_polar_SC_fast_sys_N512_K128";
		this->set_name(name);
		assert(N == 512);
		assert(K == 140);
	}

	virtual ~Decoder_polar_SC_fast_sys_N512_K128()
	{
	}

	void _decode()
	{

		auto &l = this->l;
		auto &s = this->s;

		API_polar::template f  <256>(   l,    0+   0,    0+ 256,               0+ 512, 256);
		API_polar::template f  <128>(   l,  512+   0,  512+ 128,             512+ 256, 128);
		API_polar::template rep<128>(s, l,  768+   0,                          0+   0, 128);
		API_polar::template gr <128>(s, l,  512+   0,  512+ 128,    0+   0,  512+ 256, 128);
		API_polar::template f  < 64>(   l,  768+   0,  768+  64,             768+ 128,  64);
		API_polar::template g0 < 32>(   l,  896+   0,  896+  32,             896+  64,  32);
		API_polar::template g0 < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template g0 <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template g0 <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template g0 <  2>(   l, 1016+   0, 1016+   2,            1016+   4,   2);
		API_polar::template h  <  2>(s, l, 1020+   0,                        190+   0,   2);
		API_polar::template xo0<  2>(s,     188+   2,                        188+   0,   2);
		API_polar::template xo0<  4>(s,     184+   4,                        184+   0,   4);
		API_polar::template xo0<  8>(s,     176+   8,                        176+   0,   8);
		API_polar::template xo0< 16>(s,     160+  16,                        160+   0,  16);
		API_polar::template xo0< 32>(s,     128+  32,                        128+   0,  32);
		API_polar::template g  < 64>(s, l,  768+   0,  768+  64,  128+   0,  768+ 128,  64);
		API_polar::template f  < 32>(   l,  896+   0,  896+  32,             896+  64,  32);
		API_polar::template g0 < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template g0 <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template g0 <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template spc<  4>(s, l, 1016+   0,                        220+   0,   4);
		API_polar::template xo0<  4>(s,     216+   4,                        216+   0,   4);
		API_polar::template xo0<  8>(s,     208+   8,                        208+   0,   8);
		API_polar::template xo0< 16>(s,     192+  16,                        192+   0,  16);
		API_polar::template g  < 32>(s, l,  896+   0,  896+  32,  192+   0,  896+  64,  32);
		API_polar::template f  < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template g0 <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template rep<  4>(s, l, 1016+   0,                        232+   0,   4);
		API_polar::template gr <  4>(s, l, 1008+   0, 1008+   4,  232+   0, 1008+   8,   4);
		API_polar::template spc<  4>(s, l, 1016+   0,                        236+   0,   4);
		API_polar::template xo <  4>(s,     232+   0,  232+   4,             232+   0,   4);
		API_polar::template xo0<  8>(s,     224+   8,                        224+   0,   8);
		API_polar::template g  < 16>(s, l,  960+   0,  960+  16,  224+   0,  960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template rep<  4>(s, l, 1016+   0,                        240+   0,   4);
		API_polar::template gr <  4>(s, l, 1008+   0, 1008+   4,  240+   0, 1008+   8,   4);
		API_polar::template spc<  4>(s, l, 1016+   0,                        244+   0,   4);
		API_polar::template xo <  4>(s,     240+   0,  240+   4,             240+   0,   4);
		API_polar::template g  <  8>(s, l,  992+   0,  992+   8,  240+   0,  992+  16,   8);
		API_polar::template spc<  8>(s, l, 1008+   0,                        248+   0,   8);
		API_polar::template xo <  8>(s,     240+   0,  240+   8,             240+   0,   8);
		API_polar::template xo < 16>(s,     224+   0,  224+  16,             224+   0,  16);
		API_polar::template xo < 32>(s,     192+   0,  192+  32,             192+   0,  32);
		API_polar::template xo < 64>(s,     128+   0,  128+  64,             128+   0,  64);
		API_polar::template xo <128>(s,       0+   0,    0+ 128,               0+   0, 128);
		API_polar::template g  <256>(s, l,    0+   0,    0+ 256,    0+   0,    0+ 512, 256);
		API_polar::template f  <128>(   l,  512+   0,  512+ 128,             512+ 256, 128);
		API_polar::template f  < 64>(   l,  768+   0,  768+  64,             768+ 128,  64);
		API_polar::template g0 < 32>(   l,  896+   0,  896+  32,             896+  64,  32);
		API_polar::template g0 < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template g0 <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template rep<  4>(s, l, 1016+   0,                        312+   0,   4);
		API_polar::template gr <  4>(s, l, 1008+   0, 1008+   4,  312+   0, 1008+   8,   4);
		API_polar::template spc<  4>(s, l, 1016+   0,                        316+   0,   4);
		API_polar::template xo <  4>(s,     312+   0,  312+   4,             312+   0,   4);
		API_polar::template xo0<  8>(s,     304+   8,                        304+   0,   8);
		API_polar::template xo0< 16>(s,     288+  16,                        288+   0,  16);
		API_polar::template xo0< 32>(s,     256+  32,                        256+   0,  32);
		API_polar::template g  < 64>(s, l,  768+   0,  768+  64,  256+   0,  768+ 128,  64);
		API_polar::template f  < 32>(   l,  896+   0,  896+  32,             896+  64,  32);
		API_polar::template f  < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template rep< 16>(s, l,  992+   0,                        320+   0,  16);
		API_polar::template gr < 16>(s, l,  960+   0,  960+  16,  320+   0,  960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template rep<  8>(s, l, 1008+   0,                        336+   0,   8);
		API_polar::template gr <  8>(s, l,  992+   0,  992+   8,  336+   0,  992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template rep<  4>(s, l, 1016+   0,                        344+   0,   4);
		API_polar::template gr <  4>(s, l, 1008+   0, 1008+   4,  344+   0, 1008+   8,   4);
		API_polar::template spc<  4>(s, l, 1016+   0,                        348+   0,   4);
		API_polar::template xo <  4>(s,     344+   0,  344+   4,             344+   0,   4);
		API_polar::template xo <  8>(s,     336+   0,  336+   8,             336+   0,   8);
		API_polar::template xo < 16>(s,     320+   0,  320+  16,             320+   0,  16);
		API_polar::template g  < 32>(s, l,  896+   0,  896+  32,  320+   0,  896+  64,  32);
		API_polar::template f  < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template rep<  8>(s, l, 1008+   0,                        352+   0,   8);
		API_polar::template gr <  8>(s, l,  992+   0,  992+   8,  352+   0,  992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template rep<  4>(s, l, 1016+   0,                        360+   0,   4);
		API_polar::template gr <  4>(s, l, 1008+   0, 1008+   4,  360+   0, 1008+   8,   4);
		API_polar::template h  <  4>(s, l, 1016+   0,                        364+   0,   4);
		API_polar::template xo <  4>(s,     360+   0,  360+   4,             360+   0,   4);
		API_polar::template xo <  8>(s,     352+   0,  352+   8,             352+   0,   8);
		API_polar::template g  < 16>(s, l,  960+   0,  960+  16,  352+   0,  960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template g0 <  2>(   l, 1016+   0, 1016+   2,            1016+   4,   2);
		API_polar::template h  <  2>(s, l, 1020+   0,                        370+   0,   2);
		API_polar::template xo0<  2>(s,     368+   2,                        368+   0,   2);
		API_polar::template g  <  4>(s, l, 1008+   0, 1008+   4,  368+   0, 1008+   8,   4);
		API_polar::template h  <  4>(s, l, 1016+   0,                        372+   0,   4);
		API_polar::template xo <  4>(s,     368+   0,  368+   4,             368+   0,   4);
		API_polar::template g  <  8>(s, l,  992+   0,  992+   8,  368+   0,  992+  16,   8);
		API_polar::template h  <  8>(s, l, 1008+   0,                        376+   0,   8);
		API_polar::template xo <  8>(s,     368+   0,  368+   8,             368+   0,   8);
		API_polar::template xo < 16>(s,     352+   0,  352+  16,             352+   0,  16);
		API_polar::template xo < 32>(s,     320+   0,  320+  32,             320+   0,  32);
		API_polar::template xo < 64>(s,     256+   0,  256+  64,             256+   0,  64);
		API_polar::template g  <128>(s, l,  512+   0,  512+ 128,  256+   0,  512+ 256, 128);
		API_polar::template f  < 64>(   l,  768+   0,  768+  64,             768+ 128,  64);
		API_polar::template f  < 32>(   l,  896+   0,  896+  32,             896+  64,  32);
		API_polar::template f  < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template rep< 16>(s, l,  992+   0,                        384+   0,  16);
		API_polar::template gr < 16>(s, l,  960+   0,  960+  16,  384+   0,  960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template rep<  8>(s, l, 1008+   0,                        400+   0,   8);
		API_polar::template gr <  8>(s, l,  992+   0,  992+   8,  400+   0,  992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template rep<  4>(s, l, 1016+   0,                        408+   0,   4);
		API_polar::template gr <  4>(s, l, 1008+   0, 1008+   4,  408+   0, 1008+   8,   4);
		API_polar::template h  <  4>(s, l, 1016+   0,                        412+   0,   4);
		API_polar::template xo <  4>(s,     408+   0,  408+   4,             408+   0,   4);
		API_polar::template xo <  8>(s,     400+   0,  400+   8,             400+   0,   8);
		API_polar::template xo < 16>(s,     384+   0,  384+  16,             384+   0,  16);
		API_polar::template g  < 32>(s, l,  896+   0,  896+  32,  384+   0,  896+  64,  32);
		API_polar::template f  < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template g0 <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template g0 <  2>(   l, 1016+   0, 1016+   2,            1016+   4,   2);
		API_polar::template h  <  2>(s, l, 1020+   0,                        422+   0,   2);
		API_polar::template xo0<  2>(s,     420+   2,                        420+   0,   2);
		API_polar::template xo0<  4>(s,     416+   4,                        416+   0,   4);
		API_polar::template g  <  8>(s, l,  992+   0,  992+   8,  416+   0,  992+  16,   8);
		API_polar::template spc<  8>(s, l, 1008+   0,                        424+   0,   8);
		API_polar::template xo <  8>(s,     416+   0,  416+   8,             416+   0,   8);
		API_polar::template g  < 16>(s, l,  960+   0,  960+  16,  416+   0,  960+  32,  16);
		API_polar::template spc< 16>(s, l,  992+   0,                        432+   0,  16);
		API_polar::template xo < 16>(s,     416+   0,  416+  16,             416+   0,  16);
		API_polar::template xo < 32>(s,     384+   0,  384+  32,             384+   0,  32);
		API_polar::template g  < 64>(s, l,  768+   0,  768+  64,  384+   0,  768+ 128,  64);
		API_polar::template f  < 32>(   l,  896+   0,  896+  32,             896+  64,  32);
		API_polar::template f  < 16>(   l,  960+   0,  960+  16,             960+  32,  16);
		API_polar::template f  <  8>(   l,  992+   0,  992+   8,             992+  16,   8);
		API_polar::template f  <  4>(   l, 1008+   0, 1008+   4,            1008+   8,   4);
		API_polar::template rep<  4>(s, l, 1016+   0,                        448+   0,   4);
		API_polar::template gr <  4>(s, l, 1008+   0, 1008+   4,  448+   0, 1008+   8,   4);
		API_polar::template spc<  4>(s, l, 1016+   0,                        452+   0,   4);
		API_polar::template xo <  4>(s,     448+   0,  448+   4,             448+   0,   4);
		API_polar::template g  <  8>(s, l,  992+   0,  992+   8,  448+   0,  992+  16,   8);
		API_polar::template spc<  8>(s, l, 1008+   0,                        456+   0,   8);
		API_polar::template xo <  8>(s,     448+   0,  448+   8,             448+   0,   8);
		API_polar::template g  < 16>(s, l,  960+   0,  960+  16,  448+   0,  960+  32,  16);
		API_polar::template spc< 16>(s, l,  992+   0,                        464+   0,  16);
		API_polar::template xo < 16>(s,     448+   0,  448+  16,             448+   0,  16);
		API_polar::template g  < 32>(s, l,  896+   0,  896+  32,  448+   0,  896+  64,  32);
		API_polar::template h  < 32>(s, l,  960+   0,                        480+   0,  32);
		API_polar::template xo < 32>(s,     448+   0,  448+  32,             448+   0,  32);
		API_polar::template xo < 64>(s,     384+   0,  384+  64,             384+   0,  64);
		API_polar::template xo <128>(s,     256+   0,  256+ 128,             256+   0, 128);
		API_polar::template xo <256>(s,       0+   0,    0+ 256,               0+   0, 256);
	}
};
}
}
#endif
