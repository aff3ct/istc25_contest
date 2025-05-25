#ifndef DECODER_POLAR_SCL_FAST_CA_SYS_N1024_K512_HPP_
#define DECODER_POLAR_SCL_FAST_CA_SYS_N1024_K512_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SCL_fast_CA_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SCL_fast_CA_sys_fb_1024_512 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

class Decoder_polar_SCL_fast_CA_sys_N1024_K512 : public Decoder_polar_SCL_fast_CA_sys
{
public:
	Decoder_polar_SCL_fast_CA_sys_N1024_K512(const int& K, const int& N, const int& L, CRC<int>& crc, const int n_frames = 1)
	:  Decoder_polar_SCL_fast_CA_sys(K, N, L, Decoder_polar_SCL_fast_CA_sys_fb_1024_512, crc)
	{
		const std::string name = "Decoder_polar_SCL_fast_CA_sys_N1024_K512";
		this->set_name(name);
		assert(N == 1024);
		assert(K == 528);
	}

	virtual ~Decoder_polar_SCL_fast_CA_sys_N1024_K512()
	{
	}

	void _decode(const float *Y_N)
	{

		auto  y = Y_N;
		auto &l = this->l;
		auto &s = this->s;

		f<512>(y, y + 512, l[0].data(), 512);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			f<256>(parent + 0, parent + 0 + 256, child + 0 + 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			f<128>(parent + 512, parent + 512 + 128, child + 512 + 256, 128);
		}
		this->template update_paths_rep<7, 128>(768, 0);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			gr<128>(parent + 512, parent + 512 + 128, s[path].data() + 0, child + 512 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			f<64>(parent + 768, parent + 768 + 64, child + 768 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		this->template update_paths_r0<5, 32>(960, 128);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g0<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		this->template update_paths_r0<4, 16>(992, 160);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g0<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(1008, 176);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g0<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(1016, 184);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g0<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 1016, parent + 1016 + 2, child + 1016 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(1020, 188);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g0<2>(parent + 1016, parent + 1016 + 2, child + 1016 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(1020, 190);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<2>(s[this->paths[i]], 188 + 2, 188, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<4>(s[this->paths[i]], 184 + 4, 184, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<8>(s[this->paths[i]], 176 + 8, 176, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<16>(s[this->paths[i]], 160 + 16, 160, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<32>(s[this->paths[i]], 128 + 32, 128, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			g<64>(parent + 768, parent + 768 + 64, s[path].data() + 128, child + 768 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		this->template update_paths_r0<4, 16>(992, 192);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g0<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(1008, 208);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g0<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(1016, 216);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g0<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 220);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<4>(s[this->paths[i]], 216 + 4, 216, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<8>(s[this->paths[i]], 208 + 8, 208, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<16>(s[this->paths[i]], 192 + 16, 192, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 896, parent + 896 + 32, s[path].data() + 192, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(1008, 224);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			gr<8>(parent + 992, parent + 992 + 8, s[path].data() + 224, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 232);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 232, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 236);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 232, 232 + 4, 232, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 224, 224 + 8, 224, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 960, parent + 960 + 16, s[path].data() + 224, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 240);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 240, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 244);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 240, 240 + 4, 240, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 992, parent + 992 + 8, s[path].data() + 240, child + 992 + 16, 8);
		}
		this->template update_paths_r1<3, 8>(1008, 248);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 240, 240 + 8, 240, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 224, 224 + 16, 224, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 192, 192 + 32, 192, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<64>(s[this->paths[i]], 128, 128 + 64, 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<128>(s[this->paths[i]], 0, 0 + 128, 0, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			g<256>(parent + 0, parent + 0 + 256, s[path].data() + 0, child + 0 + 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			f<128>(parent + 512, parent + 512 + 128, child + 512 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			f<64>(parent + 768, parent + 768 + 64, child + 768 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		this->template update_paths_r0<5, 32>(960, 256);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g0<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		this->template update_paths_r0<4, 16>(992, 288);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g0<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(1008, 304);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g0<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 312);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 312, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 316);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 312, 312 + 4, 312, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<8>(s[this->paths[i]], 304 + 8, 304, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<16>(s[this->paths[i]], 288 + 16, 288, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<32>(s[this->paths[i]], 256 + 32, 256, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			g<64>(parent + 768, parent + 768 + 64, s[path].data() + 256, child + 768 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(992, 320);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			gr<16>(parent + 960, parent + 960 + 16, s[path].data() + 320, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(1008, 336);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			gr<8>(parent + 992, parent + 992 + 8, s[path].data() + 336, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 344);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 344, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 348);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 344, 344 + 4, 344, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 336, 336 + 8, 336, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 320, 320 + 16, 320, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 896, parent + 896 + 32, s[path].data() + 320, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(1008, 352);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			gr<8>(parent + 992, parent + 992 + 8, s[path].data() + 352, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 360);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 360, child + 1008 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(1016, 364);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 360, 360 + 4, 360, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 352, 352 + 8, 352, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 960, parent + 960 + 16, s[path].data() + 352, child + 960 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(992, 368);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 352, 352 + 16, 352, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 320, 320 + 32, 320, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<64>(s[this->paths[i]], 256, 256 + 64, 256, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			g<128>(parent + 512, parent + 512 + 128, s[path].data() + 256, child + 512 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			f<64>(parent + 768, parent + 768 + 64, child + 768 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(992, 384);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			gr<16>(parent + 960, parent + 960 + 16, s[path].data() + 384, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(1008, 400);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			gr<8>(parent + 992, parent + 992 + 8, s[path].data() + 400, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 1016, parent + 1016 + 2, child + 1016 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(1020, 408);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g0<2>(parent + 1016, parent + 1016 + 2, child + 1016 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(1020, 410);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<2>(s[this->paths[i]], 408 + 2, 408, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 408, child + 1008 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(1016, 412);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 408, 408 + 4, 408, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 400, 400 + 8, 400, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 384, 384 + 16, 384, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 896, parent + 896 + 32, s[path].data() + 384, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(1016, 416);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g0<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 420);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<4>(s[this->paths[i]], 416 + 4, 416, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 992, parent + 992 + 8, s[path].data() + 416, child + 992 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(1008, 424);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 416, 416 + 8, 416, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 960, parent + 960 + 16, s[path].data() + 416, child + 960 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(992, 432);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 416, 416 + 16, 416, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 384, 384 + 32, 384, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			g<64>(parent + 768, parent + 768 + 64, s[path].data() + 384, child + 768 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 448);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 448, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 452);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 448, 448 + 4, 448, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 992, parent + 992 + 8, s[path].data() + 448, child + 992 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(1008, 456);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 448, 448 + 8, 448, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 960, parent + 960 + 16, s[path].data() + 448, child + 960 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(992, 464);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 448, 448 + 16, 448, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 896, parent + 896 + 32, s[path].data() + 448, child + 896 + 64, 32);
		}
		this->template update_paths_r1<5, 32>(960, 480);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 448, 448 + 32, 448, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<64>(s[this->paths[i]], 384, 384 + 64, 384, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<128>(s[this->paths[i]], 256, 256 + 128, 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<256>(s[this->paths[i]], 0, 0 + 256, 0, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path  = this->paths[i];
			const auto child = l[this->up_ref_array_idx(path, 10 -1)].data();
			g<512>(y, y + 512, s[path].data() + 0, child, 512);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			f<256>(parent + 0, parent + 0 + 256, child + 0 + 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			f<128>(parent + 512, parent + 512 + 128, child + 512 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			f<64>(parent + 768, parent + 768 + 64, child + 768 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		this->template update_paths_rep<5, 32>(960, 512);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			gr<32>(parent + 896, parent + 896 + 32, s[path].data() + 512, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(992, 544);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			gr<16>(parent + 960, parent + 960 + 16, s[path].data() + 544, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(1008, 560);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			gr<8>(parent + 992, parent + 992 + 8, s[path].data() + 560, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 568);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 568, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 572);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 568, 568 + 4, 568, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 560, 560 + 8, 560, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 544, 544 + 16, 544, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 512, 512 + 32, 512, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			g<64>(parent + 768, parent + 768 + 64, s[path].data() + 512, child + 768 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(992, 576);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			gr<16>(parent + 960, parent + 960 + 16, s[path].data() + 576, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(1016, 592);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g0<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 1016, parent + 1016 + 2, child + 1016 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(1020, 596);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g0<2>(parent + 1016, parent + 1016 + 2, child + 1016 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(1020, 598);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<2>(s[this->paths[i]], 596 + 2, 596, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<4>(s[this->paths[i]], 592 + 4, 592, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 992, parent + 992 + 8, s[path].data() + 592, child + 992 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(1008, 600);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 592, 592 + 8, 592, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 576, 576 + 16, 576, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 896, parent + 896 + 32, s[path].data() + 576, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 608);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 608, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 612);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 608, 608 + 4, 608, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 992, parent + 992 + 8, s[path].data() + 608, child + 992 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(1008, 616);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 608, 608 + 8, 608, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 960, parent + 960 + 16, s[path].data() + 608, child + 960 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(992, 624);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 608, 608 + 16, 608, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 576, 576 + 32, 576, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<64>(s[this->paths[i]], 512, 512 + 64, 512, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			g<128>(parent + 512, parent + 512 + 128, s[path].data() + 512, child + 512 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			f<64>(parent + 768, parent + 768 + 64, child + 768 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(1008, 640);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g0<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 648);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 648, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 652);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 648, 648 + 4, 648, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<8>(s[this->paths[i]], 640 + 8, 640, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 960, parent + 960 + 16, s[path].data() + 640, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 656);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 656, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 660);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 656, 656 + 4, 656, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 992, parent + 992 + 8, s[path].data() + 656, child + 992 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(1008, 664);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 656, 656 + 8, 656, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 640, 640 + 16, 640, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 896, parent + 896 + 32, s[path].data() + 640, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 672);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 672, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 676);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 672, 672 + 4, 672, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 992, parent + 992 + 8, s[path].data() + 672, child + 992 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(1008, 680);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 672, 672 + 8, 672, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 960, parent + 960 + 16, s[path].data() + 672, child + 960 + 32, 16);
		}
		this->template update_paths_r1<4, 16>(992, 688);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 672, 672 + 16, 672, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 640, 640 + 32, 640, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			g<64>(parent + 768, parent + 768 + 64, s[path].data() + 640, child + 768 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 704);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 704, child + 1008 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(1016, 708);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 704, 704 + 4, 704, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 992, parent + 992 + 8, s[path].data() + 704, child + 992 + 16, 8);
		}
		this->template update_paths_r1<3, 8>(1008, 712);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 704, 704 + 8, 704, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 960, parent + 960 + 16, s[path].data() + 704, child + 960 + 32, 16);
		}
		this->template update_paths_r1<4, 16>(992, 720);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 704, 704 + 16, 704, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 896, parent + 896 + 32, s[path].data() + 704, child + 896 + 64, 32);
		}
		this->template update_paths_r1<5, 32>(960, 736);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 704, 704 + 32, 704, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<64>(s[this->paths[i]], 640, 640 + 64, 640, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<128>(s[this->paths[i]], 512, 512 + 128, 512, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			g<256>(parent + 0, parent + 0 + 256, s[path].data() + 512, child + 0 + 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			f<128>(parent + 512, parent + 512 + 128, child + 512 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			f<64>(parent + 768, parent + 768 + 64, child + 768 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 896, parent + 896 + 32, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(1008, 768);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			gr<8>(parent + 992, parent + 992 + 8, s[path].data() + 768, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 776);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 776, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 780);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 776, 776 + 4, 776, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 768, 768 + 8, 768, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 960, parent + 960 + 16, s[path].data() + 768, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(1016, 784);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 784, child + 1008 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(1016, 788);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 784, 784 + 4, 784, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 992, parent + 992 + 8, s[path].data() + 784, child + 992 + 16, 8);
		}
		this->template update_paths_r1<3, 8>(1008, 792);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 784, 784 + 8, 784, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 768, 768 + 16, 768, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 896, parent + 896 + 32, s[path].data() + 768, child + 896 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 960, parent + 960 + 16, child + 960 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 992, parent + 992 + 8, child + 992 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 1008, parent + 1008 + 4, child + 1008 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 1016, parent + 1016 + 2, child + 1016 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(1020, 800);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g0<2>(parent + 1016, parent + 1016 + 2, child + 1016 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(1020, 802);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<2>(s[this->paths[i]], 800 + 2, 800, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 1008, parent + 1008 + 4, s[path].data() + 800, child + 1008 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(1016, 804);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 800, 800 + 4, 800, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 992, parent + 992 + 8, s[path].data() + 800, child + 992 + 16, 8);
		}
		this->template update_paths_r1<3, 8>(1008, 808);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 800, 800 + 8, 800, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 960, parent + 960 + 16, s[path].data() + 800, child + 960 + 32, 16);
		}
		this->template update_paths_r1<4, 16>(992, 816);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 800, 800 + 16, 800, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 768, 768 + 32, 768, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			g<64>(parent + 768, parent + 768 + 64, s[path].data() + 768, child + 768 + 128, 64);
		}
		this->template update_paths_spc<6, 64>(896, 832);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<64>(s[this->paths[i]], 768, 768 + 64, 768, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			g<128>(parent + 512, parent + 512 + 128, s[path].data() + 768, child + 512 + 256, 128);
		}
		this->template update_paths_spc<7, 128>(768, 896);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<128>(s[this->paths[i]], 768, 768 + 128, 768, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<256>(s[this->paths[i]], 512, 512 + 256, 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<512>(s[this->paths[i]], 0, 0 + 512, 0, 512);
		}
	}
};
}
}
#endif
