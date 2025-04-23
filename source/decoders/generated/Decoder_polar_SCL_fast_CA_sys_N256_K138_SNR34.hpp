#ifndef DECODER_POLAR_SCL_FAST_SYS_CA_N256_K138_SNR34_HPP_
#define DECODER_POLAR_SCL_FAST_SYS_CA_N256_K138_SNR34_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SCL_fast_CA_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SCL_fast_CA_sys_fb_256_138_34 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

class Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR34 : public Decoder_polar_SCL_fast_CA_sys
{
public:
	Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR34(const int& K, const int& N, const int& L, CRC<int>& crc, const int n_frames = 1)
	:  Decoder_polar_SCL_fast_CA_sys(K, N, L, Decoder_polar_SCL_fast_CA_sys_fb_256_138_34, crc)
	{
		const std::string name = "Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR34";
		this->set_name(name);
		assert(N == 256);
		assert(K == 138);
	}

	virtual ~Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR34()
	{
	}

	void _decode(const float *Y_N)
	{

		auto  y = Y_N;
		auto &l = this->l;
		auto &s = this->s;

		f<128>(y, y + 128, l[0].data(), 128);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			f<64>(parent + 0, parent + 0 + 64, child + 0 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 128, parent + 128 + 32, child + 128 + 64, 32);
		}
		this->template update_paths_r0<5, 32>(192, 0);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g0<32>(parent + 128, parent + 128 + 32, child + 128 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 192, parent + 192 + 16, child + 192 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(224, 32);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			gr<16>(parent + 192, parent + 192 + 16, s[path].data() + 32, child + 192 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 224, parent + 224 + 8, child + 224 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(240, 48);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			gr<8>(parent + 224, parent + 224 + 8, s[path].data() + 48, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(248, 56);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 240, parent + 240 + 4, s[path].data() + 56, child + 240 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(248, 60);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 56, 56 + 4, 56, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 48, 48 + 8, 48, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 32, 32 + 16, 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<32>(s[this->paths[i]], 0 + 32, 0, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			g<64>(parent + 0, parent + 0 + 64, s[path].data() + 0, child + 0 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 128, parent + 128 + 32, child + 128 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 192, parent + 192 + 16, child + 192 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(224, 64);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			gr<16>(parent + 192, parent + 192 + 16, s[path].data() + 64, child + 192 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 224, parent + 224 + 8, child + 224 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(240, 80);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			gr<8>(parent + 224, parent + 224 + 8, s[path].data() + 80, child + 224 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(240, 88);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 80, 80 + 8, 80, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 64, 64 + 16, 64, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 128, parent + 128 + 32, s[path].data() + 64, child + 128 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 192, parent + 192 + 16, child + 192 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 224, parent + 224 + 8, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(248, 96);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g0<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(248, 100);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<4>(s[this->paths[i]], 96 + 4, 96, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 96, child + 224 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(240, 104);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 96, 96 + 8, 96, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 192, parent + 192 + 16, s[path].data() + 96, child + 192 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(224, 112);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 96, 96 + 16, 96, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 64, 64 + 32, 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<64>(s[this->paths[i]], 0, 0 + 64, 0, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path  = this->paths[i];
			const auto child = l[this->up_ref_array_idx(path, 8 -1)].data();
			g<128>(y, y + 128, s[path].data() + 0, child, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			f<64>(parent + 0, parent + 0 + 64, child + 0 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 128, parent + 128 + 32, child + 128 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 192, parent + 192 + 16, child + 192 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 224, parent + 224 + 8, child + 224 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(240, 128);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g0<8>(parent + 224, parent + 224 + 8, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(248, 136);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g0<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(252, 140);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g0<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(252, 142);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<2>(s[this->paths[i]], 140 + 2, 140, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<4>(s[this->paths[i]], 136 + 4, 136, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<8>(s[this->paths[i]], 128 + 8, 128, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 192, parent + 192 + 16, s[path].data() + 128, child + 192 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 224, parent + 224 + 8, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(248, 144);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 240, parent + 240 + 4, s[path].data() + 144, child + 240 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(248, 148);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 144, 144 + 4, 144, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 144, child + 224 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(240, 152);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 144, 144 + 8, 144, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 128, 128 + 16, 128, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 128, parent + 128 + 32, s[path].data() + 128, child + 128 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 192, parent + 192 + 16, child + 192 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 224, parent + 224 + 8, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(248, 160);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 240, parent + 240 + 4, s[path].data() + 160, child + 240 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(248, 164);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 160, 160 + 4, 160, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 160, child + 224 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(240, 168);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 160, 160 + 8, 160, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 192, parent + 192 + 16, s[path].data() + 160, child + 192 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(224, 176);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 160, 160 + 16, 160, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 128, 128 + 32, 128, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			g<64>(parent + 0, parent + 0 + 64, s[path].data() + 128, child + 0 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 128, parent + 128 + 32, child + 128 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 192, parent + 192 + 16, child + 192 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 224, parent + 224 + 8, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(248, 192);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 240, parent + 240 + 4, s[path].data() + 192, child + 240 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(248, 196);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 192, 192 + 4, 192, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 192, child + 224 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(240, 200);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 192, 192 + 8, 192, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 192, parent + 192 + 16, s[path].data() + 192, child + 192 + 32, 16);
		}
		this->template update_paths_r1<4, 16>(224, 208);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 192, 192 + 16, 192, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 128, parent + 128 + 32, s[path].data() + 192, child + 128 + 64, 32);
		}
		this->template update_paths_r1<5, 32>(192, 224);
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
	}
};
}
}
#endif
