#ifndef DECODER_POLAR_SC_FAST_SYS_N1024_K256_HPP_
#define DECODER_POLAR_SC_FAST_SYS_N1024_K256_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SC_fast_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SC_fast_sys_fb_1024_256 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

template <typename API_polar>
class Decoder_polar_SC_fast_sys_N1024_K256 : public Decoder_polar_SC_fast_sys
{
public:
	Decoder_polar_SC_fast_sys_N1024_K256(const int& K, const int& N, const int n_frames = 1)
	: Decoder_polar_SC_fast_sys(K, N, Decoder_polar_SC_fast_sys_fb_1024_256)
	{
		const std::string name = "Decoder_polar_SC_fast_sys_N1024_K256";
		this->set_name(name);
		assert(N == 1024);
		assert(K == 268);
	}

	virtual ~Decoder_polar_SC_fast_sys_N1024_K256()
	{
	}

	void _decode()
	{

		auto &l = this->l;
		auto &s = this->s;

		API_polar::template f  <512>(   l,    0+   0,    0+ 512,               0+1024, 512);
		API_polar::template f  <256>(   l, 1024+   0, 1024+ 256,            1024+ 512, 256);
		API_polar::template rep<256>(s, l, 1536+   0,                          0+   0, 256);
		API_polar::template gr <256>(s, l, 1024+   0, 1024+ 256,    0+   0, 1024+ 512, 256);
		API_polar::template f  <128>(   l, 1536+   0, 1536+ 128,            1536+ 256, 128);
		API_polar::template g0 < 64>(   l, 1792+   0, 1792+  64,            1792+ 128,  64);
		API_polar::template g0 < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template g0 < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template g0 <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template g0 <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        380+   0,   4);
		API_polar::template xo0<  4>(s,     376+   4,                        376+   0,   4);
		API_polar::template xo0<  8>(s,     368+   8,                        368+   0,   8);
		API_polar::template xo0< 16>(s,     352+  16,                        352+   0,  16);
		API_polar::template xo0< 32>(s,     320+  32,                        320+   0,  32);
		API_polar::template xo0< 64>(s,     256+  64,                        256+   0,  64);
		API_polar::template g  <128>(s, l, 1536+   0, 1536+ 128,  256+   0, 1536+ 256, 128);
		API_polar::template f  < 64>(   l, 1792+   0, 1792+  64,            1792+ 128,  64);
		API_polar::template g0 < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template g0 < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template rep<  8>(s, l, 2032+   0,                        432+   0,   8);
		API_polar::template gr <  8>(s, l, 2016+   0, 2016+   8,  432+   0, 2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        440+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  440+   0, 2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        444+   0,   4);
		API_polar::template xo <  4>(s,     440+   0,  440+   4,             440+   0,   4);
		API_polar::template xo <  8>(s,     432+   0,  432+   8,             432+   0,   8);
		API_polar::template xo0< 16>(s,     416+  16,                        416+   0,  16);
		API_polar::template xo0< 32>(s,     384+  32,                        384+   0,  32);
		API_polar::template g  < 64>(s, l, 1792+   0, 1792+  64,  384+   0, 1792+ 128,  64);
		API_polar::template f  < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template rep< 16>(s, l, 2016+   0,                        448+   0,  16);
		API_polar::template gr < 16>(s, l, 1984+   0, 1984+  16,  448+   0, 1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template rep<  8>(s, l, 2032+   0,                        464+   0,   8);
		API_polar::template gr <  8>(s, l, 2016+   0, 2016+   8,  464+   0, 2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        472+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  472+   0, 2032+   8,   4);
		API_polar::template h  <  4>(s, l, 2040+   0,                        476+   0,   4);
		API_polar::template xo <  4>(s,     472+   0,  472+   4,             472+   0,   4);
		API_polar::template xo <  8>(s,     464+   0,  464+   8,             464+   0,   8);
		API_polar::template xo < 16>(s,     448+   0,  448+  16,             448+   0,  16);
		API_polar::template g  < 32>(s, l, 1920+   0, 1920+  32,  448+   0, 1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template g0 <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template g0 <  2>(   l, 2040+   0, 2040+   2,            2040+   4,   2);
		API_polar::template h  <  2>(s, l, 2044+   0,                        486+   0,   2);
		API_polar::template xo0<  2>(s,     484+   2,                        484+   0,   2);
		API_polar::template xo0<  4>(s,     480+   4,                        480+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,  480+   0, 2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template g0 <  2>(   l, 2040+   0, 2040+   2,            2040+   4,   2);
		API_polar::template h  <  2>(s, l, 2044+   0,                        490+   0,   2);
		API_polar::template xo0<  2>(s,     488+   2,                        488+   0,   2);
		API_polar::template g  <  4>(s, l, 2032+   0, 2032+   4,  488+   0, 2032+   8,   4);
		API_polar::template h  <  4>(s, l, 2040+   0,                        492+   0,   4);
		API_polar::template xo <  4>(s,     488+   0,  488+   4,             488+   0,   4);
		API_polar::template xo <  8>(s,     480+   0,  480+   8,             480+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,  480+   0, 1984+  32,  16);
		API_polar::template spc< 16>(s, l, 2016+   0,                        496+   0,  16);
		API_polar::template xo < 16>(s,     480+   0,  480+  16,             480+   0,  16);
		API_polar::template xo < 32>(s,     448+   0,  448+  32,             448+   0,  32);
		API_polar::template xo < 64>(s,     384+   0,  384+  64,             384+   0,  64);
		API_polar::template xo <128>(s,     256+   0,  256+ 128,             256+   0, 128);
		API_polar::template xo <256>(s,       0+   0,    0+ 256,               0+   0, 256);
		API_polar::template g  <512>(s, l,    0+   0,    0+ 512,    0+   0,    0+1024, 512);
		API_polar::template f  <256>(   l, 1024+   0, 1024+ 256,            1024+ 512, 256);
		API_polar::template f  <128>(   l, 1536+   0, 1536+ 128,            1536+ 256, 128);
		API_polar::template g0 < 64>(   l, 1792+   0, 1792+  64,            1792+ 128,  64);
		API_polar::template g0 < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template rep< 16>(s, l, 2016+   0,                        608+   0,  16);
		API_polar::template gr < 16>(s, l, 1984+   0, 1984+  16,  608+   0, 1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template rep<  8>(s, l, 2032+   0,                        624+   0,   8);
		API_polar::template gr <  8>(s, l, 2016+   0, 2016+   8,  624+   0, 2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        632+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  632+   0, 2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        636+   0,   4);
		API_polar::template xo <  4>(s,     632+   0,  632+   4,             632+   0,   4);
		API_polar::template xo <  8>(s,     624+   0,  624+   8,             624+   0,   8);
		API_polar::template xo < 16>(s,     608+   0,  608+  16,             608+   0,  16);
		API_polar::template xo0< 32>(s,     576+  32,                        576+   0,  32);
		API_polar::template xo0< 64>(s,     512+  64,                        512+   0,  64);
		API_polar::template g  <128>(s, l, 1536+   0, 1536+ 128,  512+   0, 1536+ 256, 128);
		API_polar::template f  < 64>(   l, 1792+   0, 1792+  64,            1792+ 128,  64);
		API_polar::template f  < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template rep< 32>(s, l, 1984+   0,                        640+   0,  32);
		API_polar::template gr < 32>(s, l, 1920+   0, 1920+  32,  640+   0, 1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template rep< 16>(s, l, 2016+   0,                        672+   0,  16);
		API_polar::template gr < 16>(s, l, 1984+   0, 1984+  16,  672+   0, 1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template rep<  8>(s, l, 2032+   0,                        688+   0,   8);
		API_polar::template gr <  8>(s, l, 2016+   0, 2016+   8,  688+   0, 2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template g0 <  2>(   l, 2040+   0, 2040+   2,            2040+   4,   2);
		API_polar::template h  <  2>(s, l, 2044+   0,                        698+   0,   2);
		API_polar::template xo0<  2>(s,     696+   2,                        696+   0,   2);
		API_polar::template g  <  4>(s, l, 2032+   0, 2032+   4,  696+   0, 2032+   8,   4);
		API_polar::template h  <  4>(s, l, 2040+   0,                        700+   0,   4);
		API_polar::template xo <  4>(s,     696+   0,  696+   4,             696+   0,   4);
		API_polar::template xo <  8>(s,     688+   0,  688+   8,             688+   0,   8);
		API_polar::template xo < 16>(s,     672+   0,  672+  16,             672+   0,  16);
		API_polar::template xo < 32>(s,     640+   0,  640+  32,             640+   0,  32);
		API_polar::template g  < 64>(s, l, 1792+   0, 1792+  64,  640+   0, 1792+ 128,  64);
		API_polar::template f  < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template g0 <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template g0 <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template g0 <  2>(   l, 2040+   0, 2040+   2,            2040+   4,   2);
		API_polar::template h  <  2>(s, l, 2044+   0,                        718+   0,   2);
		API_polar::template xo0<  2>(s,     716+   2,                        716+   0,   2);
		API_polar::template xo0<  4>(s,     712+   4,                        712+   0,   4);
		API_polar::template xo0<  8>(s,     704+   8,                        704+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,  704+   0, 1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template g0 <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        724+   0,   4);
		API_polar::template xo0<  4>(s,     720+   4,                        720+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,  720+   0, 2016+  16,   8);
		API_polar::template spc<  8>(s, l, 2032+   0,                        728+   0,   8);
		API_polar::template xo <  8>(s,     720+   0,  720+   8,             720+   0,   8);
		API_polar::template xo < 16>(s,     704+   0,  704+  16,             704+   0,  16);
		API_polar::template g  < 32>(s, l, 1920+   0, 1920+  32,  704+   0, 1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        736+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  736+   0, 2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        740+   0,   4);
		API_polar::template xo <  4>(s,     736+   0,  736+   4,             736+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,  736+   0, 2016+  16,   8);
		API_polar::template spc<  8>(s, l, 2032+   0,                        744+   0,   8);
		API_polar::template xo <  8>(s,     736+   0,  736+   8,             736+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,  736+   0, 1984+  32,  16);
		API_polar::template h  < 16>(s, l, 2016+   0,                        752+   0,  16);
		API_polar::template xo < 16>(s,     736+   0,  736+  16,             736+   0,  16);
		API_polar::template xo < 32>(s,     704+   0,  704+  32,             704+   0,  32);
		API_polar::template xo < 64>(s,     640+   0,  640+  64,             640+   0,  64);
		API_polar::template xo <128>(s,     512+   0,  512+ 128,             512+   0, 128);
		API_polar::template g  <256>(s, l, 1024+   0, 1024+ 256,  512+   0, 1024+ 512, 256);
		API_polar::template f  <128>(   l, 1536+   0, 1536+ 128,            1536+ 256, 128);
		API_polar::template f  < 64>(   l, 1792+   0, 1792+  64,            1792+ 128,  64);
		API_polar::template f  < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template rep< 32>(s, l, 1984+   0,                        768+   0,  32);
		API_polar::template gr < 32>(s, l, 1920+   0, 1920+  32,  768+   0, 1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template g0 <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template g0 <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        812+   0,   4);
		API_polar::template xo0<  4>(s,     808+   4,                        808+   0,   4);
		API_polar::template xo0<  8>(s,     800+   8,                        800+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,  800+   0, 1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        816+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  816+   0, 2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        820+   0,   4);
		API_polar::template xo <  4>(s,     816+   0,  816+   4,             816+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,  816+   0, 2016+  16,   8);
		API_polar::template spc<  8>(s, l, 2032+   0,                        824+   0,   8);
		API_polar::template xo <  8>(s,     816+   0,  816+   8,             816+   0,   8);
		API_polar::template xo < 16>(s,     800+   0,  800+  16,             800+   0,  16);
		API_polar::template xo < 32>(s,     768+   0,  768+  32,             768+   0,  32);
		API_polar::template g  < 64>(s, l, 1792+   0, 1792+  64,  768+   0, 1792+ 128,  64);
		API_polar::template f  < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template rep<  8>(s, l, 2032+   0,                        832+   0,   8);
		API_polar::template gr <  8>(s, l, 2016+   0, 2016+   8,  832+   0, 2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        840+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  840+   0, 2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        844+   0,   4);
		API_polar::template xo <  4>(s,     840+   0,  840+   4,             840+   0,   4);
		API_polar::template xo <  8>(s,     832+   0,  832+   8,             832+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,  832+   0, 1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        848+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  848+   0, 2032+   8,   4);
		API_polar::template spc<  4>(s, l, 2040+   0,                        852+   0,   4);
		API_polar::template xo <  4>(s,     848+   0,  848+   4,             848+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,  848+   0, 2016+  16,   8);
		API_polar::template h  <  8>(s, l, 2032+   0,                        856+   0,   8);
		API_polar::template xo <  8>(s,     848+   0,  848+   8,             848+   0,   8);
		API_polar::template xo < 16>(s,     832+   0,  832+  16,             832+   0,  16);
		API_polar::template g  < 32>(s, l, 1920+   0, 1920+  32,  832+   0, 1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        864+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  864+   0, 2032+   8,   4);
		API_polar::template h  <  4>(s, l, 2040+   0,                        868+   0,   4);
		API_polar::template xo <  4>(s,     864+   0,  864+   4,             864+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,  864+   0, 2016+  16,   8);
		API_polar::template h  <  8>(s, l, 2032+   0,                        872+   0,   8);
		API_polar::template xo <  8>(s,     864+   0,  864+   8,             864+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,  864+   0, 1984+  32,  16);
		API_polar::template h  < 16>(s, l, 2016+   0,                        880+   0,  16);
		API_polar::template xo < 16>(s,     864+   0,  864+  16,             864+   0,  16);
		API_polar::template xo < 32>(s,     832+   0,  832+  32,             832+   0,  32);
		API_polar::template xo < 64>(s,     768+   0,  768+  64,             768+   0,  64);
		API_polar::template g  <128>(s, l, 1536+   0, 1536+ 128,  768+   0, 1536+ 256, 128);
		API_polar::template f  < 64>(   l, 1792+   0, 1792+  64,            1792+ 128,  64);
		API_polar::template f  < 32>(   l, 1920+   0, 1920+  32,            1920+  64,  32);
		API_polar::template f  < 16>(   l, 1984+   0, 1984+  16,            1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template rep<  8>(s, l, 2032+   0,                        896+   0,   8);
		API_polar::template gr <  8>(s, l, 2016+   0, 2016+   8,  896+   0, 2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template rep<  4>(s, l, 2040+   0,                        904+   0,   4);
		API_polar::template gr <  4>(s, l, 2032+   0, 2032+   4,  904+   0, 2032+   8,   4);
		API_polar::template h  <  4>(s, l, 2040+   0,                        908+   0,   4);
		API_polar::template xo <  4>(s,     904+   0,  904+   4,             904+   0,   4);
		API_polar::template xo <  8>(s,     896+   0,  896+   8,             896+   0,   8);
		API_polar::template g  < 16>(s, l, 1984+   0, 1984+  16,  896+   0, 1984+  32,  16);
		API_polar::template f  <  8>(   l, 2016+   0, 2016+   8,            2016+  16,   8);
		API_polar::template f  <  4>(   l, 2032+   0, 2032+   4,            2032+   8,   4);
		API_polar::template g0 <  2>(   l, 2040+   0, 2040+   2,            2040+   4,   2);
		API_polar::template h  <  2>(s, l, 2044+   0,                        914+   0,   2);
		API_polar::template xo0<  2>(s,     912+   2,                        912+   0,   2);
		API_polar::template g  <  4>(s, l, 2032+   0, 2032+   4,  912+   0, 2032+   8,   4);
		API_polar::template h  <  4>(s, l, 2040+   0,                        916+   0,   4);
		API_polar::template xo <  4>(s,     912+   0,  912+   4,             912+   0,   4);
		API_polar::template g  <  8>(s, l, 2016+   0, 2016+   8,  912+   0, 2016+  16,   8);
		API_polar::template h  <  8>(s, l, 2032+   0,                        920+   0,   8);
		API_polar::template xo <  8>(s,     912+   0,  912+   8,             912+   0,   8);
		API_polar::template xo < 16>(s,     896+   0,  896+  16,             896+   0,  16);
		API_polar::template g  < 32>(s, l, 1920+   0, 1920+  32,  896+   0, 1920+  64,  32);
		API_polar::template spc< 32>(s, l, 1984+   0,                        928+   0,  32);
		API_polar::template xo < 32>(s,     896+   0,  896+  32,             896+   0,  32);
		API_polar::template g  < 64>(s, l, 1792+   0, 1792+  64,  896+   0, 1792+ 128,  64);
		API_polar::template spc< 64>(s, l, 1920+   0,                        960+   0,  64);
		API_polar::template xo < 64>(s,     896+   0,  896+  64,             896+   0,  64);
		API_polar::template xo <128>(s,     768+   0,  768+ 128,             768+   0, 128);
		API_polar::template xo <256>(s,     512+   0,  512+ 256,             512+   0, 256);
		API_polar::template xo <512>(s,       0+   0,    0+ 512,               0+   0, 512);
	}
};
}
}
#endif
