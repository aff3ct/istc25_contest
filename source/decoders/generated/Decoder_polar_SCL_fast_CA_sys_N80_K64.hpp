#ifndef DECODER_POLAR_SCL_FAST_CA_SYS_N80_K64_HPP_
#define DECODER_POLAR_SCL_FAST_CA_SYS_N80_K64_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SCL_fast_CA_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SCL_fast_CA_sys_fb_80_64 = {
1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

class Decoder_polar_SCL_fast_CA_sys_N80_K64 : public Decoder_polar_SCL_fast_CA_sys
{
public:
	Decoder_polar_SCL_fast_CA_sys_N80_K64(const int& K, const int& N, const int& L, CRC<int>& crc, const int n_frames = 1)
	:  Decoder_polar_SCL_fast_CA_sys(K, N, L, Decoder_polar_SCL_fast_CA_sys_fb_80_64, crc)
	{
		const std::string name = "Decoder_polar_SCL_fast_CA_sys_N80_K64";
		this->set_name(name);
		assert(N == 128);
		assert(K == 72);
	}

	virtual ~Decoder_polar_SCL_fast_CA_sys_N80_K64()
	{
	}

	void _decode(const float *Y_N)
	{

		auto  y = Y_N;
		auto &l = this->l;
		auto &s = this->s;

		f<64>(y, y + 64, l[0].data(), 64);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 0, parent + 0 + 32, child + 0 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 64, parent + 64 + 16, child + 64 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 96, parent + 96 + 8, child + 96 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 112, parent + 112 + 4, child + 112 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(120, 0);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g0<4>(parent + 112, parent + 112 + 4, child + 112 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(120, 4);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<4>(s[this->paths[i]], 0 + 4, 0, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 96, parent + 96 + 8, s[path].data() + 0, child + 96 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(112, 8);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 0, 0 + 8, 0, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 64, parent + 64 + 16, s[path].data() + 0, child + 64 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(96, 16);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 0, 0 + 16, 0, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 0, parent + 0 + 32, s[path].data() + 0, child + 0 + 64, 32);
		}
		this->template update_paths_spc<5, 32>(64, 32);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 0, 0 + 32, 0, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path  = this->paths[i];
			const auto child = l[this->up_ref_array_idx(path, 7 -1)].data();
			g<64>(y, y + 64, s[path].data() + 0, child, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			f<32>(parent + 0, parent + 0 + 32, child + 0 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			f<16>(parent + 64, parent + 64 + 16, child + 64 + 32, 16);
		}
		this->template update_paths_r1<4, 16>(96, 64);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 64, parent + 64 + 16, s[path].data() + 64, child + 64 + 32, 16);
		}
		this->template update_paths_r0<4, 16>(96, 80);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<16>(s[this->paths[i]], 64, 64 + 16, 64, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 0, parent + 0 + 32, s[path].data() + 64, child + 0 + 64, 32);
		}
		this->template update_paths_r0<5, 32>(64, 96);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<32>(s[this->paths[i]], 64, 64 + 32, 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<64>(s[this->paths[i]], 0, 0 + 64, 0, 64);
		}
	}
};
}
}
#endif
