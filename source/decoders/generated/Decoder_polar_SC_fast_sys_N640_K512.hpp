#ifndef DECODER_POLAR_SC_FAST_SYS_N640_K512_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N640_K512_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SC_fast_sys_fb_640_512 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

template <typename API_polar>
class Decoder_polar_SC_fast_sys_N640_K512 : public Decoder_polar_SC_fast_sys
{
public:
	Decoder_polar_SC_fast_sys_N640_K512(const int& K, const int& N, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys(K, N, Decoder_polar_SC_fast_sys_fb_640_512)
	{
		const std::string name = "Decoder_polar_SC_fast_sys_N640_K512";
		this->set_name(name);
		assert(N == 1024);
		assert(K == 524);
	}

	virtual ~Decoder_polar_SC_fast_sys_N640_K512()
	{
	}

	void _decode()
	{

		auto &l = this->l;
		auto &s = this->s;

		API_polar::template f  <512>(   l,    0+   0,    0+ 512,               0+1024, 512);
		API_polar::template f  <256>(   l, 1024+   0, 1024+ 256,            1024+ 512, 256);
		API_polar::template f  <128>(   l, 1536+   0, 1536+ 128,            1536+ 256, 128);
		API_polar::template f  < 64>(   l, 1792+   0, 1792+  64,            1792+ 128,  64);
		API_polar::template f  < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template rep< 32>(s, l, 1984+   0,                          0+   0,  32);
		API_polar::template gr < 32>(s, l, 1920+   0, 1920+  32,    0+   0, 1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template rep< 16>(s, l, 2016+   0,                         32+   0,  16);
		API_polar::template gr < 16>(s, l, 1984+   0, 1984+  16,   32+   0, 1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template g0 <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                         52+   0,   4);
		API_polar::template xo0<  4>(s,      48+   4,                         48+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,   48+   0, 2016+  16,   8);
		API_polar::template spc<  8>(s, l, 2032+   0,                         56+   0,   8);
		API_polar::template xo <  8>(s,      48+   0,   48+   8,              48+   0,   8);
		API_polar::template xo < 16>(s,      32+   0,   32+  16,              32+   0,  16);
		API_polar::template xo < 32>(s,       0+   0,    0+  32,               0+   0,  32);
		API_polar::template g  < 64>(s, l, 1792+   0, 1792+  64,    0+   0, 1792+ 128,  64);
		API_polar::template f  < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template g0 <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template g0 <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                         76+   0,   4);
		API_polar::template xo0<  4>(s,      72+   4,                         72+   0,   4);
		API_polar::template xo0<  8>(s,      64+   8,                         64+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,   64+   0, 1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                         80+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,   80+   0, 2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                         84+   0,   4);
		API_polar::template xo <  4>(s,      80+   0,   80+   4,              80+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,   80+   0, 2016+  16,   8);
		API_polar::template spc<  8>(s, l, 2032+   0,                         88+   0,   8);
		API_polar::template xo <  8>(s,      80+   0,   80+   8,              80+   0,   8);
		API_polar::template xo < 16>(s,      64+   0,   64+  16,              64+   0,  16);
		API_polar::template g  < 32>(s, l, 1920+   0, 1920+  32,   64+   0, 1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                         96+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,   96+   0, 2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        100+   0,   4);
		API_polar::template xo <  4>(s,      96+   0,   96+   4,              96+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,   96+   0, 2016+  16,   8);
		API_polar::template h  <  8>(s, l, 2032+   0,                        104+   0,   8);
		API_polar::template xo <  8>(s,      96+   0,   96+   8,              96+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,   96+   0, 1984+  32,  16);
		API_polar::template h  < 16>(s, l, 2016+   0,                        112+   0,  16);
		API_polar::template xo < 16>(s,      96+   0,   96+  16,              96+   0,  16);
		API_polar::template xo < 32>(s,      64+   0,   64+  32,              64+   0,  32);
		API_polar::template xo < 64>(s,       0+   0,    0+  64,               0+   0,  64);
		API_polar::template g  <128>(s, l, 1536+   0, 1536+ 128,    0+   0, 1536+ 256, 128);
		API_polar::template f  < 64>(   l, 1792+   0, 1792+  64,            1792+ 128,  64);
		API_polar::template f  < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template rep<  8>(s, l, 2032+   0,                        128+   0,   8);
		API_polar::template gr <  8>(s, l, 2016+   0, 2016+   8,  128+   0, 2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        136+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  136+   0, 2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        140+   0,   4);
		API_polar::template xo <  4>(s,     136+   0,  136+   4,             136+   0,   4);
		API_polar::template xo <  8>(s,     128+   0,  128+   8,             128+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,  128+   0, 1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        144+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  144+   0, 2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        148+   0,   4);
		API_polar::template xo <  4>(s,     144+   0,  144+   4,             144+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,  144+   0, 2016+  16,   8);
		API_polar::template h  <  8>(s, l, 2032+   0,                        152+   0,   8);
		API_polar::template xo <  8>(s,     144+   0,  144+   8,             144+   0,   8);
		API_polar::template xo < 16>(s,     128+   0,  128+  16,             128+   0,  16);
		API_polar::template g  < 32>(s, l, 1920+   0, 1920+  32,  128+   0, 1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template g0 <  2>(   l, 2040+   0, 2040+   2,            2040+   4,   2);
		API_polar::template h  <  2>(s, l, 2044+   0,                        162+   0,   2);
		API_polar::template xo0<  2>(s,     160+   2,                        160+   0,   2);
		API_polar::template g  <  4>(s, l, 2032+   0, 2032+   4,  160+   0, 2032+   8,   4);
		API_polar::template h  <  4>(s, l, 2040+   0,                        164+   0,   4);
		API_polar::template xo <  4>(s,     160+   0,  160+   4,             160+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,  160+   0, 2016+  16,   8);
		API_polar::template h  <  8>(s, l, 2032+   0,                        168+   0,   8);
		API_polar::template xo <  8>(s,     160+   0,  160+   8,             160+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,  160+   0, 1984+  32,  16);
		API_polar::template h  < 16>(s, l, 2016+   0,                        176+   0,  16);
		API_polar::template xo < 16>(s,     160+   0,  160+  16,             160+   0,  16);
		API_polar::template xo < 32>(s,     128+   0,  128+  32,             128+   0,  32);
		API_polar::template g  < 64>(s, l, 1792+   0, 1792+  64,  128+   0, 1792+ 128,  64);
		API_polar::template spc< 64>(s, l, 1920+   0,                        192+   0,  64);
		API_polar::template xo < 64>(s,     128+   0,  128+  64,             128+   0,  64);
		API_polar::template xo <128>(s,       0+   0,    0+ 128,               0+   0, 128);
		API_polar::template g  <256>(s, l, 1024+   0, 1024+ 256,    0+   0, 1024+ 512, 256);
		API_polar::template f  <128>(   l, 1536+   0, 1536+ 128,            1536+ 256, 128);
		API_polar::template f  < 64>(   l, 1792+   0, 1792+  64,            1792+ 128,  64);
		API_polar::template f  < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template rep<  8>(s, l, 2032+   0,                        256+   0,   8);
		API_polar::template gr <  8>(s, l, 2016+   0, 2016+   8,  256+   0, 2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        264+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  264+   0, 2032+   8,   4);
		API_polar::template h  <  4>(s, l, 2040+   0,                        268+   0,   4);
		API_polar::template xo <  4>(s,     264+   0,  264+   4,             264+   0,   4);
		API_polar::template xo <  8>(s,     256+   0,  256+   8,             256+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,  256+   0, 1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template g0 <  2>(   l, 2040+   0, 2040+   2,            2040+   4,   2);
		API_polar::template h  <  2>(s, l, 2044+   0,                        274+   0,   2);
		API_polar::template xo0<  2>(s,     272+   2,                        272+   0,   2);
		API_polar::template g  <  4>(s, l, 2032+   0, 2032+   4,  272+   0, 2032+   8,   4);
		API_polar::template h  <  4>(s, l, 2040+   0,                        276+   0,   4);
		API_polar::template xo <  4>(s,     272+   0,  272+   4,             272+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,  272+   0, 2016+  16,   8);
		API_polar::template h  <  8>(s, l, 2032+   0,                        280+   0,   8);
		API_polar::template xo <  8>(s,     272+   0,  272+   8,             272+   0,   8);
		API_polar::template xo < 16>(s,     256+   0,  256+  16,             256+   0,  16);
		API_polar::template g  < 32>(s, l, 1920+   0, 1920+  32,  256+   0, 1920+  64,  32);
		API_polar::template spc< 32>(s, l, 1984+   0,                        288+   0,  32);
		API_polar::template xo < 32>(s,     256+   0,  256+  32,             256+   0,  32);
		API_polar::template g  < 64>(s, l, 1792+   0, 1792+  64,  256+   0, 1792+ 128,  64);
		API_polar::template spc< 64>(s, l, 1920+   0,                        320+   0,  64);
		API_polar::template xo < 64>(s,     256+   0,  256+  64,             256+   0,  64);
		API_polar::template g  <128>(s, l, 1536+   0, 1536+ 128,  256+   0, 1536+ 256, 128);
		API_polar::template spc<128>(s, l, 1792+   0,                        384+   0, 128);
		API_polar::template xo <128>(s,     256+   0,  256+ 128,             256+   0, 128);
		API_polar::template xo <256>(s,       0+   0,    0+ 256,               0+   0, 256);
		API_polar::template g  <512>(s, l,    0+   0,    0+ 512,    0+   0,    0+1024, 512);
		API_polar::template f  <256>(   l, 1024+   0, 1024+ 256,            1024+ 512, 256);
		API_polar::template f  <128>(   l, 1536+   0, 1536+ 128,            1536+ 256, 128);
		API_polar::template f  < 64>(   l, 1792+   0, 1792+  64,            1792+ 128,  64);
		API_polar::template f  < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template g0 <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        516+   0,   4);
		API_polar::template xo0<  4>(s,     512+   4,                        512+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,  512+   0, 2016+  16,   8);
		API_polar::template spc<  8>(s, l, 2032+   0,                        520+   0,   8);
		API_polar::template xo <  8>(s,     512+   0,  512+   8,             512+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,  512+   0, 1984+  32,  16);
		API_polar::template spc< 16>(s, l, 2016+   0,                        528+   0,  16);
		API_polar::template xo < 16>(s,     512+   0,  512+  16,             512+   0,  16);
		API_polar::template g  < 32>(s, l, 1920+   0, 1920+  32,  512+   0, 1920+  64,  32);
		API_polar::template spc< 32>(s, l, 1984+   0,                        544+   0,  32);
		API_polar::template xo < 32>(s,     512+   0,  512+  32,             512+   0,  32);
		API_polar::template g  < 64>(s, l, 1792+   0, 1792+  64,  512+   0, 1792+ 128,  64);
		API_polar::template spc< 64>(s, l, 1920+   0,                        576+   0,  64);
		API_polar::template xo < 64>(s,     512+   0,  512+  64,             512+   0,  64);
		API_polar::template g  <128>(s, l, 1536+   0, 1536+ 128,  512+   0, 1536+ 256, 128);
		API_polar::template xo <128>(s,     512+   0,  512+ 128,             512+   0, 128);
		API_polar::template g  <256>(s, l, 1024+   0, 1024+ 256,  512+   0, 1024+ 512, 256);
		API_polar::template xo <256>(s,     512+   0,  512+ 256,             512+   0, 256);
		API_polar::template xo <512>(s,       0+   0,    0+ 512,               0+   0, 512);
	}
};
}
}
#endif
