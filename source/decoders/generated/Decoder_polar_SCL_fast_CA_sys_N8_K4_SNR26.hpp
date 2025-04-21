#ifndef DECODER_POLAR_SCL_FAST_SYS_CA_N8_K4_SNR26_HPP_
#define DECODER_POLAR_SCL_FAST_SYS_CA_N8_K4_SNR26_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SCL_fast_CA_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SCL_fast_CA_sys_fb_8_4_26 = {
1, 1, 1, 0, 0, 0, 0, 1};

class Decoder_polar_SCL_fast_CA_sys_N8_K4_SNR26 : public Decoder_polar_SCL_fast_CA_sys
{
public:
	Decoder_polar_SCL_fast_CA_sys_N8_K4_SNR26(const int& K, const int& N, const int& L, CRC<int>& crc, const int n_frames = 1)
	:  Decoder_polar_SCL_fast_CA_sys(K, N, L, Decoder_polar_SCL_fast_CA_sys_fb_8_4_26, crc)
	{
		const std::string name = "Decoder_polar_SCL_fast_CA_sys_N8_K4_SNR26";
		this->set_name(name);
		assert(N == 8);
		assert(K == 4);
	}

	virtual ~Decoder_polar_SCL_fast_CA_sys_N8_K4_SNR26()
	{
	}

	void _decode(const float *Y_N)
	{

		auto  y = Y_N;
		auto &l = this->l;
		auto &s = this->s;

		f<4>(y, y + 4, l[0].data(), 4);
		this->template update_paths_rep<2, 4>(0, 0);
		for (auto i = 0; i < this->n_active_paths; i++)
		{
			const auto path  = this->paths[i];
			const auto child = l[this->up_ref_array_idx(path, 3 -1)].data();
			gr<4>(y, y + 4, s[path].data() + 0, child, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++)
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			f<2>(parent + 0, parent + 0 + 2, child + 0 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(4, 4);
		for (auto i = 0; i < this->n_active_paths; i++)
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			g<2>(parent + 0, parent + 0 + 2, s[path].data() + 4, child + 0 + 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++)
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			f<1>(parent + 4, parent + 4 + 1, child + 4 + 2, 1);
		}
		this->template update_paths_r1<0, 1>(6, 6);
		for (auto i = 0; i < this->n_active_paths; i++)
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][1   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 1 -1)].data();
			g<1>(parent + 4, parent + 4 + 1, s[path].data() + 6, child + 4 + 2, 1);
		}
		this->template update_paths_r0<0, 1>(6, 7);
		for (auto i = 0; i < this->n_active_paths; i++)
		{
			xo<1>(s[this->paths[i]], 6, 6 + 1, 6, 1);
		}
		for (auto i = 0; i < this->n_active_paths; i++)
		{
			xo<2>(s[this->paths[i]], 4, 4 + 2, 4, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++)
		{
			xo<4>(s[this->paths[i]], 0, 0 + 4, 0, 4);
		}
	}
};
}
}
#endif
