#ifndef DECODER_POLAR_SCL_FAST_SYS_CA_N256_K64_SNR25_HPP_
#define DECODER_POLAR_SCL_FAST_SYS_CA_N256_K64_SNR25_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SCL_fast_CA_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SCL_fast_CA_sys_fb_256_64_25 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

class Decoder_polar_SCL_fast_CA_sys_N256_K64_SNR25 : public Decoder_polar_SCL_fast_CA_sys
{
public:
	Decoder_polar_SCL_fast_CA_sys_N256_K64_SNR25(const int& K, const int& N, const int& L, CRC<int>& crc, const int n_frames = 1)
	:  Decoder_polar_SCL_fast_CA_sys(K, N, L, Decoder_polar_SCL_fast_CA_sys_fb_256_64_25, crc)
	{
		const std::string name = "Decoder_polar_SCL_fast_CA_sys_N256_K64_SNR25";
		this->set_name(name);
		assert(N == 256);
		assert(K == 64);
	}

	virtual ~Decoder_polar_SCL_fast_CA_sys_N256_K64_SNR25()
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
		this->template update_paths_r0<6, 64>(128, 0);
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
		this->template update_paths_r0<4, 16>(224, 64);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 192, parent + 192 + 16, s[path].data() + 64, child + 192 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 224, parent + 224 + 8, child + 224 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(240, 80);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 80, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(248, 88);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 88, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(252, 92);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 92, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 94);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 94, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 95);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 94, 94 + 1, 94, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 92, 92 + 2, 92, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 88, 88 + 4, 88, 4);
		}
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
		this->template update_paths_r0<3, 8>(240, 96);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 96, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(248, 104);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 104, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(252, 108);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 108, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 110);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 110, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 111);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 110, 110 + 1, 110, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 108, 108 + 2, 108, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 104, 104 + 4, 104, 4);
		}
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
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 112, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(252, 116);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 116, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 118);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 118, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 119);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 118, 118 + 1, 118, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 116, 116 + 2, 116, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 112, 112 + 4, 112, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 112, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(252, 120);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 120, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 122);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 122, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 123);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 122, 122 + 1, 122, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 120, 120 + 2, 120, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 120, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 124);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 124, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 125);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 124, 124 + 1, 124, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 124, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 126);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 126, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 127);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 126, 126 + 1, 126, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 124, 124 + 2, 124, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 120, 120 + 4, 120, 4);
		}
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
			g<16>(parent + 192, parent + 192 + 16, s[path].data() + 128, child + 192 + 32, 16);
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
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 144, child + 224 + 16, 8);
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
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 152, child + 240 + 8, 4);
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
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 156, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 158);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 158, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 159);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 158, 158 + 1, 158, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 156, 156 + 2, 156, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 152, 152 + 4, 152, 4);
		}
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
		this->template update_paths_r0<3, 8>(240, 160);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 160, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(248, 168);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 168, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(252, 172);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 172, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 174);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 174, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 175);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 174, 174 + 1, 174, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 172, 172 + 2, 172, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 168, 168 + 4, 168, 4);
		}
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
		this->template update_paths_r0<2, 4>(248, 176);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 176, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 180);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 180, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 181);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 180, 180 + 1, 180, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 180, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 182);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 182, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 183);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 182, 182 + 1, 182, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 180, 180 + 2, 180, 2);
		}
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
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 184);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 184, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 185);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 184, 184 + 1, 184, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 184, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 186);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 186, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 187);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 186, 186 + 1, 186, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 184, 184 + 2, 184, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 184, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 188);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 188, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 189);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 188, 188 + 1, 188, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 188, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 190);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 190, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 191);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 190, 190 + 1, 190, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 188, 188 + 2, 188, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 184, 184 + 4, 184, 4);
		}
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
		this->template update_paths_r0<3, 8>(240, 192);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 192, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(252, 200);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 200, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 202);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 202, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 203);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 202, 202 + 1, 202, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 200, 200 + 2, 200, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 200, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 204);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 204, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 205);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 204, 204 + 1, 204, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 204, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 206);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 206, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 207);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 206, 206 + 1, 206, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 204, 204 + 2, 204, 2);
		}
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
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(252, 208);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 208, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 210);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 210, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 211);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 210, 210 + 1, 210, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 208, 208 + 2, 208, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 208, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 212);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 212, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 213);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 212, 212 + 1, 212, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 212, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 214);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 214, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 215);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 214, 214 + 1, 214, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 212, 212 + 2, 212, 2);
		}
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
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 216);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 216, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 217);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 216, 216 + 1, 216, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 216, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 218);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 218, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 219);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 218, 218 + 1, 218, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 216, 216 + 2, 216, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 216, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 220);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 220, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 221);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 220, 220 + 1, 220, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 220, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 222);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 222, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 223);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 222, 222 + 1, 222, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 220, 220 + 2, 220, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 216, 216 + 4, 216, 4);
		}
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
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(252, 224);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 224, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 226);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 226, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 227);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 226, 226 + 1, 226, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 224, 224 + 2, 224, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 224, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(254, 228);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 228, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 229);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 228, 228 + 1, 228, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 228, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 230);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 230, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 231);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 230, 230 + 1, 230, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 228, 228 + 2, 228, 2);
		}
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
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 232);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 232, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 233);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 232, 232 + 1, 232, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 232, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 234);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 234, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 235);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 234, 234 + 1, 234, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 232, 232 + 2, 232, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 232, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 236);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 236, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 237);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 236, 236 + 1, 236, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 236, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 238);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 238, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 239);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 238, 238 + 1, 238, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 236, 236 + 2, 236, 2);
		}
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
			g<16>(parent + 192, parent + 192 + 16, s[path].data() + 224, child + 192 + 32, 16);
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
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 240);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 240, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 241);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 240, 240 + 1, 240, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 240, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 242);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 242, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 243);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 242, 242 + 1, 242, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 240, 240 + 2, 240, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 240, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 244);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 244, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 245);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 244, 244 + 1, 244, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 244, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 246);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 246, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 247);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 246, 246 + 1, 246, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 244, 244 + 2, 244, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 240, 240 + 4, 240, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 224, parent + 224 + 8, s[path].data() + 240, child + 224 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 240, parent + 240 + 4, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 248);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 248, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 249);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 248, 248 + 1, 248, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 248, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 250);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 250, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 251);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 250, 250 + 1, 250, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 248, 248 + 2, 248, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 240, parent + 240 + 4, s[path].data() + 248, child + 240 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 248, parent + 248 + 2, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 252);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 252, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 253);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 252, 252 + 1, 252, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 248, parent + 248 + 2, s[path].data() + 252, child + 248 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 252, parent + 252 + 1, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 254);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 252, parent + 252 + 1, s[path].data() + 254, child + 252 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(254, 255);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<1>(s[this->paths[i]], 254, 254 + 1, 254, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<2>(s[this->paths[i]], 252, 252 + 2, 252, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 248, 248 + 4, 248, 4);
		}
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
	}
};
}
}
#endif
