#ifndef DECODER_POLAR_SCL_FAST_SYS_CA_N256_K76_SNR33_HPP_
#define DECODER_POLAR_SCL_FAST_SYS_CA_N256_K76_SNR33_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SCL_fast_CA_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SCL_fast_CA_sys_fb_256_76_33 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

class Decoder_polar_SCL_fast_CA_sys_N256_K76_SNR33 : public Decoder_polar_SCL_fast_CA_sys
{
public:
	Decoder_polar_SCL_fast_CA_sys_N256_K76_SNR33(const int& K, const int& N, const int& L, CRC<int>& crc, const int n_frames = 1)
	:  Decoder_polar_SCL_fast_CA_sys(K, N, L, Decoder_polar_SCL_fast_CA_sys_fb_256_76_33, crc)
	{
		const std::string name = "Decoder_polar_SCL_fast_CA_sys_N256_K76_SNR33";
		this->set_name(name);
		assert(N == 256);
		assert(K == 76);
	}

	virtual ~Decoder_polar_SCL_fast_CA_sys_N256_K76_SNR33()
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
		this->template update_paths_rep<6, 64>(128, 0);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			gr<64>(parent + 0, parent + 0 + 64, s[path].data() + 0, child + 0 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 128, parent + 128 + 32, child + 128 + 64, 32);
		}
		this->template update_paths_rep<5, 32>(192, 64);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			gr<32>(parent + 128, parent + 128 + 32, s[path].data() + 64, child + 128 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 192, parent + 192 + 16, child + 192 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(224, 96);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			gr<16>(parent + 192, parent + 192 + 16, s[path].data() + 96, child + 192 + 32, 16);
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
		this->template update_paths_r0<2, 4>(248, 112);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g0<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(248, 116);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<4>(s[this->paths[i]], 112 + 4, 112, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 112, child + 224 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(240, 120);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 112, 112 + 8, 112, 8);
		}
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
		this->template update_paths_r0<4, 16>(224, 128);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g0<16>(parent + 192, parent + 192 + 16, child + 192 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 224, parent + 224 + 8, child + 224 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(240, 144);
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
		this->template update_paths_r0<2, 4>(248, 152);
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
		this->template update_paths_r0<1, 2>(252, 156);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g0<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(252, 158);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<2>(s[this->paths[i]], 156 + 2, 156, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<4>(s[this->paths[i]], 152 + 4, 152, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<8>(s[this->paths[i]], 144 + 8, 144, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<16>(s[this->paths[i]], 128 + 16, 128, 16);
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
		this->template update_paths_r0<3, 8>(240, 160);
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
		this->template update_paths_rep<2, 4>(248, 168);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 240, parent + 240 + 4, s[path].data() + 168, child + 240 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(248, 172);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 168, 168 + 4, 168, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<8>(s[this->paths[i]], 160 + 8, 160, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 192, parent + 192 + 16, s[path].data() + 160, child + 192 + 32, 16);
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
		this->template update_paths_rep<2, 4>(248, 176);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 240, parent + 240 + 4, s[path].data() + 176, child + 240 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(248, 180);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 176, 176 + 4, 176, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 176, child + 224 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(240, 184);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 176, 176 + 8, 176, 8);
		}
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
		this->template update_paths_rep<3, 8>(240, 192);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			gr<8>(parent + 224, parent + 224 + 8, s[path].data() + 192, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(248, 200);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 240, parent + 240 + 4, s[path].data() + 200, child + 240 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(248, 204);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 200, 200 + 4, 200, 4);
		}
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
		this->template update_paths_rep<2, 4>(248, 208);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 240, parent + 240 + 4, s[path].data() + 208, child + 240 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(248, 212);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 208, 208 + 4, 208, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 208, child + 224 + 16, 8);
		}
		this->template update_paths_r1<3, 8>(240, 216);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 208, 208 + 8, 208, 8);
		}
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
		this->template update_paths_rep<2, 4>(248, 224);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 240, parent + 240 + 4, s[path].data() + 224, child + 240 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(248, 228);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 224, 224 + 4, 224, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 224, child + 224 + 16, 8);
		}
		this->template update_paths_r1<3, 8>(240, 232);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 224, 224 + 8, 224, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 192, parent + 192 + 16, s[path].data() + 224, child + 192 + 32, 16);
		}
		this->template update_paths_r1<4, 16>(224, 240);
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
	}
};
}
}
#endif
