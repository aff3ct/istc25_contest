#ifndef DECODER_POLAR_SCL_FAST_CA_SYS_N320_K256_HPP_
#define DECODER_POLAR_SCL_FAST_CA_SYS_N320_K256_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SCL_fast_CA_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SCL_fast_CA_sys_fb_320_256 = {
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

template <class API_polar>
class Decoder_polar_SCL_fast_CA_sys_N320_K256 : public Decoder_polar_SCL_fast_CA_sys
{
public:
	Decoder_polar_SCL_fast_CA_sys_N320_K256(const int& K, const int& N, const int& L, CRC<int>& crc, const int n_frames = 1)
	:  Decoder_polar_SCL_fast_CA_sys(K, N, L, Decoder_polar_SCL_fast_CA_sys_fb_320_256, crc)
	{
		const std::string name = "Decoder_polar_SCL_fast_CA_sys_N320_K256";
		this->set_name(name);
		assert(N == 512);
		assert(K == 266);
	}

	virtual ~Decoder_polar_SCL_fast_CA_sys_N320_K256()
	{
	}

	void _decode(const float *Y_N)
	{

		auto  y = Y_N;
		auto &l = this->l;
		auto &s = this->s;

		API_polar::template f<256>(y, y + 256, l[0].data(), 256);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template f<128>(parent + 0, parent + 0 + 128, child + 0 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 256, parent + 256 + 64, child + 256 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 384, parent + 384 + 32, child + 384 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 448, parent + 448 + 16, child + 448 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(480, 0);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template gr<16>(parent + 448, parent + 448 + 16, s[path].data() + 0, child + 448 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 480, parent + 480 + 8, child + 480 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(496, 16);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template gr<8>(parent + 480, parent + 480 + 8, s[path].data() + 16, child + 480 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 496, parent + 496 + 4, child + 496 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(504, 24);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 496, parent + 496 + 4, s[path].data() + 24, child + 496 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(504, 28);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 24, 24 + 4, 24, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 16, 16 + 8, 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 0, 0 + 16, 0, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 384, parent + 384 + 32, s[path].data() + 0, child + 384 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 448, parent + 448 + 16, child + 448 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 480, parent + 480 + 8, child + 480 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(496, 32);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template gr<8>(parent + 480, parent + 480 + 8, s[path].data() + 32, child + 480 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 496, parent + 496 + 4, child + 496 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template f<2>(parent + 504, parent + 504 + 2, child + 504 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(508, 40);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template g0<2>(parent + 504, parent + 504 + 2, child + 504 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(508, 42);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<2>(s[this->paths[i]], 40 + 2, 40, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template g<4>(parent + 496, parent + 496 + 4, s[path].data() + 40, child + 496 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(504, 44);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 40, 40 + 4, 40, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 32, 32 + 8, 32, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 448, parent + 448 + 16, s[path].data() + 32, child + 448 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(480, 48);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 32, 32 + 16, 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 0, 0 + 32, 0, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g<64>(parent + 256, parent + 256 + 64, s[path].data() + 0, child + 256 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 384, parent + 384 + 32, child + 384 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 448, parent + 448 + 16, child + 448 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 480, parent + 480 + 8, child + 480 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 496, parent + 496 + 4, child + 496 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(504, 64);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template g0<4>(parent + 496, parent + 496 + 4, child + 496 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(504, 68);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<4>(s[this->paths[i]], 64 + 4, 64, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 480, parent + 480 + 8, s[path].data() + 64, child + 480 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(496, 72);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 64, 64 + 8, 64, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 448, parent + 448 + 16, s[path].data() + 64, child + 448 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(480, 80);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 64, 64 + 16, 64, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 384, parent + 384 + 32, s[path].data() + 64, child + 384 + 64, 32);
		}
		this->template update_paths_spc<5, 32>(448, 96);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 64, 64 + 32, 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<64>(s[this->paths[i]], 0, 0 + 64, 0, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template g<128>(parent + 0, parent + 0 + 128, s[path].data() + 0, child + 0 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 256, parent + 256 + 64, child + 256 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 384, parent + 384 + 32, child + 384 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 448, parent + 448 + 16, child + 448 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 480, parent + 480 + 8, child + 480 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 496, parent + 496 + 4, child + 496 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(504, 128);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 496, parent + 496 + 4, s[path].data() + 128, child + 496 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(504, 132);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 128, 128 + 4, 128, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 480, parent + 480 + 8, s[path].data() + 128, child + 480 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(496, 136);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 128, 128 + 8, 128, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 448, parent + 448 + 16, s[path].data() + 128, child + 448 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(480, 144);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 128, 128 + 16, 128, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 384, parent + 384 + 32, s[path].data() + 128, child + 384 + 64, 32);
		}
		this->template update_paths_r1<5, 32>(448, 160);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 128, 128 + 32, 128, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g<64>(parent + 256, parent + 256 + 64, s[path].data() + 128, child + 256 + 128, 64);
		}
		this->template update_paths_r1<6, 64>(384, 192);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<64>(s[this->paths[i]], 128, 128 + 64, 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<128>(s[this->paths[i]], 0, 0 + 128, 0, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path  = this->paths[i];
			const auto child = l[this->up_ref_array_idx(path, 9 -1)].data();
			API_polar::template g<256>(y, y + 256, s[path].data() + 0, child, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template f<128>(parent + 0, parent + 0 + 128, child + 0 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 256, parent + 256 + 64, child + 256 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 384, parent + 384 + 32, child + 384 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 448, parent + 448 + 16, child + 448 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 480, parent + 480 + 8, child + 480 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 496, parent + 496 + 4, child + 496 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(504, 256);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 496, parent + 496 + 4, s[path].data() + 256, child + 496 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(504, 260);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 256, 256 + 4, 256, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 480, parent + 480 + 8, s[path].data() + 256, child + 480 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(496, 264);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 256, 256 + 8, 256, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 448, parent + 448 + 16, s[path].data() + 256, child + 448 + 32, 16);
		}
		this->template update_paths_r1<4, 16>(480, 272);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 256, 256 + 16, 256, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 384, parent + 384 + 32, s[path].data() + 256, child + 384 + 64, 32);
		}
		this->template update_paths_r1<5, 32>(448, 288);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 256, 256 + 32, 256, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g<64>(parent + 256, parent + 256 + 64, s[path].data() + 256, child + 256 + 128, 64);
		}
		this->template update_paths_r0<6, 64>(384, 320);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<64>(s[this->paths[i]], 256, 256 + 64, 256, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template g<128>(parent + 0, parent + 0 + 128, s[path].data() + 256, child + 0 + 256, 128);
		}
		this->template update_paths_r0<7, 128>(256, 384);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<128>(s[this->paths[i]], 256, 256 + 128, 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<256>(s[this->paths[i]], 0, 0 + 256, 0, 256);
		}
	}
};
}
}
#endif
