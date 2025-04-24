#ifndef DECODER_POLAR_SCL_FAST_SYS_CA_N128_K72_SNR39_HPP_
#define DECODER_POLAR_SCL_FAST_SYS_CA_N128_K72_SNR39_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SCL_fast_CA_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SCL_fast_CA_sys_fb_128_72_39 = {
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

class Decoder_polar_SCL_fast_CA_sys_N128_K72_SNR39 : public Decoder_polar_SCL_fast_CA_sys
{
public:
	Decoder_polar_SCL_fast_CA_sys_N128_K72_SNR39(const int& K, const int& N, const int& L, CRC<int>& crc, const int n_frames = 1)
	:  Decoder_polar_SCL_fast_CA_sys(K, N, L, Decoder_polar_SCL_fast_CA_sys_fb_128_72_39, crc)
	{
		const std::string name = "Decoder_polar_SCL_fast_CA_sys_N128_K72_SNR39";
		this->set_name(name);
		assert(N == 128);
		assert(K == 72);
	}

	virtual ~Decoder_polar_SCL_fast_CA_sys_N128_K72_SNR39()
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
		this->template update_paths_r0<4, 16>(96, 0);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g0<16>(parent + 64, parent + 64 + 16, child + 64 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 96, parent + 96 + 8, child + 96 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(112, 16);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g0<8>(parent + 96, parent + 96 + 8, child + 96 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 112, parent + 112 + 4, child + 112 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(120, 24);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 112, parent + 112 + 4, s[path].data() + 24, child + 112 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(120, 28);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 24, 24 + 4, 24, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<8>(s[this->paths[i]], 16 + 8, 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<16>(s[this->paths[i]], 0 + 16, 0, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			g<32>(parent + 0, parent + 0 + 32, s[path].data() + 0, child + 0 + 64, 32);
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
		this->template update_paths_rep<3, 8>(112, 32);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			gr<8>(parent + 96, parent + 96 + 8, s[path].data() + 32, child + 96 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 112, parent + 112 + 4, child + 112 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(120, 40);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 112, parent + 112 + 4, s[path].data() + 40, child + 112 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(120, 44);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 40, 40 + 4, 40, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 32, 32 + 8, 32, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 64, parent + 64 + 16, s[path].data() + 32, child + 64 + 32, 16);
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
		this->template update_paths_rep<2, 4>(120, 48);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 112, parent + 112 + 4, s[path].data() + 48, child + 112 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(120, 52);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 48, 48 + 4, 48, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 96, parent + 96 + 8, s[path].data() + 48, child + 96 + 16, 8);
		}
		this->template update_paths_r1<3, 8>(112, 56);
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
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			f<8>(parent + 96, parent + 96 + 8, child + 96 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(112, 64);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			gr<8>(parent + 96, parent + 96 + 8, s[path].data() + 64, child + 96 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			f<4>(parent + 112, parent + 112 + 4, child + 112 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(120, 72);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(parent + 112, parent + 112 + 4, s[path].data() + 72, child + 112 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(120, 76);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 72, 72 + 4, 72, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<8>(s[this->paths[i]], 64, 64 + 8, 64, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			g<16>(parent + 64, parent + 64 + 16, s[path].data() + 64, child + 64 + 32, 16);
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
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 120, parent + 120 + 2, child + 120 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(124, 80);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g0<2>(parent + 120, parent + 120 + 2, child + 120 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(124, 82);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo0<2>(s[this->paths[i]], 80 + 2, 80, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			g<4>(parent + 112, parent + 112 + 4, s[path].data() + 80, child + 112 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(120, 84);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			xo<4>(s[this->paths[i]], 80, 80 + 4, 80, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			g<8>(parent + 96, parent + 96 + 8, s[path].data() + 80, child + 96 + 16, 8);
		}
		this->template update_paths_r1<3, 8>(112, 88);
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
			g<32>(parent + 0, parent + 0 + 32, s[path].data() + 64, child + 0 + 64, 32);
		}
		this->template update_paths_spc<5, 32>(64, 96);
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
