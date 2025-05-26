#ifndef DECODER_POLAR_SCL_FAST_CA_SYS_N2048_K512_HPP_
#define DECODER_POLAR_SCL_FAST_CA_SYS_N2048_K512_HPP_

#include <vector>
#include <cassert>

#include "../Decoder_polar_SCL_fast_CA_sys.hpp"

namespace aff3ct
{
namespace module
{
static const std::vector<bool> Decoder_polar_SCL_fast_CA_sys_fb_2048_512 = {
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
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

template <class API_polar>
class Decoder_polar_SCL_fast_CA_sys_N2048_K512 : public Decoder_polar_SCL_fast_CA_sys
{
public:
	Decoder_polar_SCL_fast_CA_sys_N2048_K512(const int& K, const int& N, const int& L, CRC<int>& crc, const int n_frames = 1)
	:  Decoder_polar_SCL_fast_CA_sys(K, N, L, Decoder_polar_SCL_fast_CA_sys_fb_2048_512, crc)
	{
		const std::string name = "Decoder_polar_SCL_fast_CA_sys_N2048_K512";
		this->set_name(name);
		assert(N == 2048);
		assert(K == 524);
	}

	virtual ~Decoder_polar_SCL_fast_CA_sys_N2048_K512()
	{
	}

	void _decode(const float *Y_N)
	{

		auto  y = Y_N;
		auto &l = this->l;
		auto &s = this->s;

		API_polar::template f<1024>(y, y + 1024, l[0].data(), 1024);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][10   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 10 -1)].data();
			API_polar::template f<512>(parent + 0, parent + 0 + 512, child + 0 + 1024, 512);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			API_polar::template f<256>(parent + 1024, parent + 1024 + 256, child + 1024 + 512, 256);
		}
		this->template update_paths_r0<8, 256>(1536, 0);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			API_polar::template g0<256>(parent + 1024, parent + 1024 + 256, child + 1024 + 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template f<128>(parent + 1536, parent + 1536 + 128, child + 1536 + 256, 128);
		}
		this->template update_paths_r0<7, 128>(1792, 256);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template g0<128>(parent + 1536, parent + 1536 + 128, child + 1536 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		this->template update_paths_r0<6, 64>(1920, 384);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g0<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		this->template update_paths_r0<5, 32>(1984, 448);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g0<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		this->template update_paths_r0<4, 16>(2016, 480);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g0<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(2032, 496);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g0<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(2040, 504);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template g0<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template f<2>(parent + 2040, parent + 2040 + 2, child + 2040 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(2044, 508);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template g0<2>(parent + 2040, parent + 2040 + 2, child + 2040 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(2044, 510);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<2>(s[this->paths[i]], 508 + 2, 508, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<4>(s[this->paths[i]], 504 + 4, 504, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<8>(s[this->paths[i]], 496 + 8, 496, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<16>(s[this->paths[i]], 480 + 16, 480, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<32>(s[this->paths[i]], 448 + 32, 448, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<64>(s[this->paths[i]], 384 + 64, 384, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<128>(s[this->paths[i]], 256 + 128, 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<256>(s[this->paths[i]], 0 + 256, 0, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][10   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 10 -1)].data();
			API_polar::template g<512>(parent + 0, parent + 0 + 512, s[path].data() + 0, child + 0 + 1024, 512);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			API_polar::template f<256>(parent + 1024, parent + 1024 + 256, child + 1024 + 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template f<128>(parent + 1536, parent + 1536 + 128, child + 1536 + 256, 128);
		}
		this->template update_paths_r0<7, 128>(1792, 512);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template g0<128>(parent + 1536, parent + 1536 + 128, child + 1536 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		this->template update_paths_r0<6, 64>(1920, 640);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g0<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		this->template update_paths_r0<5, 32>(1984, 704);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g0<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		this->template update_paths_r0<4, 16>(2016, 736);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g0<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(2032, 752);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template gr<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 752, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 760);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 760, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 764);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 760, 760 + 4, 760, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 752, 752 + 8, 752, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<16>(s[this->paths[i]], 736 + 16, 736, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<32>(s[this->paths[i]], 704 + 32, 704, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<64>(s[this->paths[i]], 640 + 64, 640, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<128>(s[this->paths[i]], 512 + 128, 512, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			API_polar::template g<256>(parent + 1024, parent + 1024 + 256, s[path].data() + 512, child + 1024 + 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template f<128>(parent + 1536, parent + 1536 + 128, child + 1536 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		this->template update_paths_r0<6, 64>(1920, 768);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g0<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		this->template update_paths_rep<5, 32>(1984, 832);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template gr<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 832, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(2016, 864);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template gr<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 864, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(2032, 880);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template gr<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 880, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template f<2>(parent + 2040, parent + 2040 + 2, child + 2040 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(2044, 888);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template g0<2>(parent + 2040, parent + 2040 + 2, child + 2040 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(2044, 890);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<2>(s[this->paths[i]], 888 + 2, 888, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template g<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 888, child + 2032 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(2040, 892);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 888, 888 + 4, 888, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 880, 880 + 8, 880, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 864, 864 + 16, 864, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 832, 832 + 32, 832, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<64>(s[this->paths[i]], 768 + 64, 768, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template g<128>(parent + 1536, parent + 1536 + 128, s[path].data() + 768, child + 1536 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		this->template update_paths_rep<5, 32>(1984, 896);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template gr<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 896, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(2032, 928);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g0<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(2040, 936);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template g0<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template f<2>(parent + 2040, parent + 2040 + 2, child + 2040 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(2044, 940);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template g0<2>(parent + 2040, parent + 2040 + 2, child + 2040 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(2044, 942);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<2>(s[this->paths[i]], 940 + 2, 940, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<4>(s[this->paths[i]], 936 + 4, 936, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<8>(s[this->paths[i]], 928 + 8, 928, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 928, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 944);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 944, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 948);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 944, 944 + 4, 944, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 944, child + 2016 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(2032, 952);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 944, 944 + 8, 944, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 928, 928 + 16, 928, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 896, 896 + 32, 896, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g<64>(parent + 1792, parent + 1792 + 64, s[path].data() + 896, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(2032, 960);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g0<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 968);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 968, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 972);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 968, 968 + 4, 968, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<8>(s[this->paths[i]], 960 + 8, 960, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 960, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 976);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 976, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 980);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 976, 976 + 4, 976, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 976, child + 2016 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(2032, 984);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 976, 976 + 8, 976, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 960, 960 + 16, 960, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 960, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 992);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 992, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 996);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 992, 992 + 4, 992, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 992, child + 2016 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(2032, 1000);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 992, 992 + 8, 992, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 992, child + 1984 + 32, 16);
		}
		this->template update_paths_r1<4, 16>(2016, 1008);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 992, 992 + 16, 992, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 960, 960 + 32, 960, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<64>(s[this->paths[i]], 896, 896 + 64, 896, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<128>(s[this->paths[i]], 768, 768 + 128, 768, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<256>(s[this->paths[i]], 512, 512 + 256, 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<512>(s[this->paths[i]], 0, 0 + 512, 0, 512);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path  = this->paths[i];
			const auto child = l[this->up_ref_array_idx(path, 11 -1)].data();
			API_polar::template g<1024>(y, y + 1024, s[path].data() + 0, child, 1024);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][10   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 10 -1)].data();
			API_polar::template f<512>(parent + 0, parent + 0 + 512, child + 0 + 1024, 512);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			API_polar::template f<256>(parent + 1024, parent + 1024 + 256, child + 1024 + 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template f<128>(parent + 1536, parent + 1536 + 128, child + 1536 + 256, 128);
		}
		this->template update_paths_r0<7, 128>(1792, 1024);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template g0<128>(parent + 1536, parent + 1536 + 128, child + 1536 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		this->template update_paths_r0<6, 64>(1920, 1152);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g0<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		this->template update_paths_rep<5, 32>(1984, 1216);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template gr<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 1216, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(2016, 1248);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template gr<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1248, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(2040, 1264);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template g0<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1268);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<4>(s[this->paths[i]], 1264 + 4, 1264, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1264, child + 2016 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(2032, 1272);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1264, 1264 + 8, 1264, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1248, 1248 + 16, 1248, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 1216, 1216 + 32, 1216, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<64>(s[this->paths[i]], 1152 + 64, 1152, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<128>(s[this->paths[i]], 1024 + 128, 1024, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			API_polar::template g<256>(parent + 1024, parent + 1024 + 256, s[path].data() + 1024, child + 1024 + 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template f<128>(parent + 1536, parent + 1536 + 128, child + 1536 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		this->template update_paths_rep<6, 64>(1920, 1280);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template gr<64>(parent + 1792, parent + 1792 + 64, s[path].data() + 1280, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		this->template update_paths_r0<4, 16>(2016, 1344);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g0<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(2032, 1360);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g0<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(2040, 1368);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template g0<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1372);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<4>(s[this->paths[i]], 1368 + 4, 1368, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<8>(s[this->paths[i]], 1360 + 8, 1360, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<16>(s[this->paths[i]], 1344 + 16, 1344, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 1344, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(2032, 1376);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g0<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1384);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1384, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1388);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1384, 1384 + 4, 1384, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<8>(s[this->paths[i]], 1376 + 8, 1376, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1376, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1392);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1392, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1396);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1392, 1392 + 4, 1392, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1392, child + 2016 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(2032, 1400);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1392, 1392 + 8, 1392, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1376, 1376 + 16, 1376, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 1344, 1344 + 32, 1344, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<64>(s[this->paths[i]], 1280, 1280 + 64, 1280, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template g<128>(parent + 1536, parent + 1536 + 128, s[path].data() + 1280, child + 1536 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		this->template update_paths_r0<4, 16>(2016, 1408);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g0<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(2032, 1424);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template gr<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1424, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1432);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1432, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1436);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1432, 1432 + 4, 1432, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1424, 1424 + 8, 1424, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<16>(s[this->paths[i]], 1408 + 16, 1408, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 1408, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(2032, 1440);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template gr<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1440, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1448);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1448, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1452);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1448, 1448 + 4, 1448, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1440, 1440 + 8, 1440, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1440, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1456);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1456, child + 2032 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(2040, 1460);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1456, 1456 + 4, 1456, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1456, child + 2016 + 16, 8);
		}
		this->template update_paths_r1<3, 8>(2032, 1464);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1456, 1456 + 8, 1456, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1440, 1440 + 16, 1440, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 1408, 1408 + 32, 1408, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g<64>(parent + 1792, parent + 1792 + 64, s[path].data() + 1408, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(2032, 1472);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template gr<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1472, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template f<2>(parent + 2040, parent + 2040 + 2, child + 2040 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(2044, 1480);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template g0<2>(parent + 2040, parent + 2040 + 2, child + 2040 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(2044, 1482);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<2>(s[this->paths[i]], 1480 + 2, 1480, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template g<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1480, child + 2032 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(2040, 1484);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1480, 1480 + 4, 1480, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1472, 1472 + 8, 1472, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1472, child + 1984 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(2016, 1488);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1472, 1472 + 16, 1472, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 1472, child + 1920 + 64, 32);
		}
		this->template update_paths_spc<5, 32>(1984, 1504);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 1472, 1472 + 32, 1472, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<64>(s[this->paths[i]], 1408, 1408 + 64, 1408, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<128>(s[this->paths[i]], 1280, 1280 + 128, 1280, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<256>(s[this->paths[i]], 1024, 1024 + 256, 1024, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][10   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 10 -1)].data();
			API_polar::template g<512>(parent + 0, parent + 0 + 512, s[path].data() + 1024, child + 0 + 1024, 512);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			API_polar::template f<256>(parent + 1024, parent + 1024 + 256, child + 1024 + 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template f<128>(parent + 1536, parent + 1536 + 128, child + 1536 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		this->template update_paths_r0<5, 32>(1984, 1536);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g0<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		this->template update_paths_r0<4, 16>(2016, 1568);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g0<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(2032, 1584);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g0<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1592);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1592, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1596);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1592, 1592 + 4, 1592, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<8>(s[this->paths[i]], 1584 + 8, 1584, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<16>(s[this->paths[i]], 1568 + 16, 1568, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<32>(s[this->paths[i]], 1536 + 32, 1536, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g<64>(parent + 1792, parent + 1792 + 64, s[path].data() + 1536, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(2016, 1600);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template gr<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1600, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(2032, 1616);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template gr<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1616, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1624);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1624, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1628);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1624, 1624 + 4, 1624, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1616, 1616 + 8, 1616, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1600, 1600 + 16, 1600, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 1600, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(2032, 1632);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template gr<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1632, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1640);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1640, child + 2032 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(2040, 1644);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1640, 1640 + 4, 1640, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1632, 1632 + 8, 1632, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1632, child + 1984 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(2016, 1648);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1632, 1632 + 16, 1632, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 1600, 1600 + 32, 1600, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<64>(s[this->paths[i]], 1536, 1536 + 64, 1536, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template g<128>(parent + 1536, parent + 1536 + 128, s[path].data() + 1536, child + 1536 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		this->template update_paths_rep<4, 16>(2016, 1664);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template gr<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1664, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_rep<3, 8>(2032, 1680);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template gr<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1680, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template f<2>(parent + 2040, parent + 2040 + 2, child + 2040 + 4, 2);
		}
		this->template update_paths_r0<1, 2>(2044, 1688);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][2   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 2 -1)].data();
			API_polar::template g0<2>(parent + 2040, parent + 2040 + 2, child + 2040 + 4, 2);
		}
		this->template update_paths_r1<1, 2>(2044, 1690);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<2>(s[this->paths[i]], 1688 + 2, 1688, 2);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template g<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1688, child + 2032 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(2040, 1692);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1688, 1688 + 4, 1688, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1680, 1680 + 8, 1680, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1664, 1664 + 16, 1664, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 1664, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(2040, 1696);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template g0<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1700);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<4>(s[this->paths[i]], 1696 + 4, 1696, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1696, child + 2016 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(2032, 1704);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1696, 1696 + 8, 1696, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1696, child + 1984 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(2016, 1712);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1696, 1696 + 16, 1696, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 1664, 1664 + 32, 1664, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g<64>(parent + 1792, parent + 1792 + 64, s[path].data() + 1664, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1728);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1728, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1732);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1728, 1728 + 4, 1728, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1728, child + 2016 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(2032, 1736);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1728, 1728 + 8, 1728, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1728, child + 1984 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(2016, 1744);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1728, 1728 + 16, 1728, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 1728, child + 1920 + 64, 32);
		}
		this->template update_paths_spc<5, 32>(1984, 1760);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 1728, 1728 + 32, 1728, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<64>(s[this->paths[i]], 1664, 1664 + 64, 1664, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<128>(s[this->paths[i]], 1536, 1536 + 128, 1536, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][9   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 9 -1)].data();
			API_polar::template g<256>(parent + 1024, parent + 1024 + 256, s[path].data() + 1536, child + 1024 + 512, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template f<128>(parent + 1536, parent + 1536 + 128, child + 1536 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		this->template update_paths_r0<3, 8>(2032, 1792);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g0<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_r0<2, 4>(2040, 1800);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template g0<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1804);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<4>(s[this->paths[i]], 1800 + 4, 1800, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo0<8>(s[this->paths[i]], 1792 + 8, 1792, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1792, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1808);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1808, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1812);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1808, 1808 + 4, 1808, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1808, child + 2016 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(2032, 1816);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1808, 1808 + 8, 1808, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1792, 1792 + 16, 1792, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 1792, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1824);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1824, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1828);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1824, 1824 + 4, 1824, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1824, child + 2016 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(2032, 1832);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1824, 1824 + 8, 1824, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1824, child + 1984 + 32, 16);
		}
		this->template update_paths_spc<4, 16>(2016, 1840);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1824, 1824 + 16, 1824, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 1792, 1792 + 32, 1792, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g<64>(parent + 1792, parent + 1792 + 64, s[path].data() + 1792, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1856);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1856, child + 2032 + 8, 4);
		}
		this->template update_paths_spc<2, 4>(2040, 1860);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1856, 1856 + 4, 1856, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1856, child + 2016 + 16, 8);
		}
		this->template update_paths_spc<3, 8>(2032, 1864);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1856, 1856 + 8, 1856, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1856, child + 1984 + 32, 16);
		}
		this->template update_paths_r1<4, 16>(2016, 1872);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1856, 1856 + 16, 1856, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 1856, child + 1920 + 64, 32);
		}
		this->template update_paths_r1<5, 32>(1984, 1888);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 1856, 1856 + 32, 1856, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<64>(s[this->paths[i]], 1792, 1792 + 64, 1792, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][8   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 8 -1)].data();
			API_polar::template g<128>(parent + 1536, parent + 1536 + 128, s[path].data() + 1792, child + 1536 + 256, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template f<64>(parent + 1792, parent + 1792 + 64, child + 1792 + 128, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template f<32>(parent + 1920, parent + 1920 + 32, child + 1920 + 64, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template f<16>(parent + 1984, parent + 1984 + 16, child + 1984 + 32, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template f<8>(parent + 2016, parent + 2016 + 8, child + 2016 + 16, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template f<4>(parent + 2032, parent + 2032 + 4, child + 2032 + 8, 4);
		}
		this->template update_paths_rep<2, 4>(2040, 1920);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][3   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 3 -1)].data();
			API_polar::template gr<4>(parent + 2032, parent + 2032 + 4, s[path].data() + 1920, child + 2032 + 8, 4);
		}
		this->template update_paths_r1<2, 4>(2040, 1924);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<4>(s[this->paths[i]], 1920, 1920 + 4, 1920, 4);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][4   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 4 -1)].data();
			API_polar::template g<8>(parent + 2016, parent + 2016 + 8, s[path].data() + 1920, child + 2016 + 16, 8);
		}
		this->template update_paths_r1<3, 8>(2032, 1928);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<8>(s[this->paths[i]], 1920, 1920 + 8, 1920, 8);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][5   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 5 -1)].data();
			API_polar::template g<16>(parent + 1984, parent + 1984 + 16, s[path].data() + 1920, child + 1984 + 32, 16);
		}
		this->template update_paths_r1<4, 16>(2016, 1936);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<16>(s[this->paths[i]], 1920, 1920 + 16, 1920, 16);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][6   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 6 -1)].data();
			API_polar::template g<32>(parent + 1920, parent + 1920 + 32, s[path].data() + 1920, child + 1920 + 64, 32);
		}
		this->template update_paths_r1<5, 32>(1984, 1952);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<32>(s[this->paths[i]], 1920, 1920 + 32, 1920, 32);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			const auto path   = this->paths[i];
			const auto parent = l[this->path_2_array    [path][7   ]].data();
			const auto child  = l[this->up_ref_array_idx(path, 7 -1)].data();
			API_polar::template g<64>(parent + 1792, parent + 1792 + 64, s[path].data() + 1920, child + 1792 + 128, 64);
		}
		this->template update_paths_r1<6, 64>(1920, 1984);
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<64>(s[this->paths[i]], 1920, 1920 + 64, 1920, 64);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<128>(s[this->paths[i]], 1792, 1792 + 128, 1792, 128);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<256>(s[this->paths[i]], 1536, 1536 + 256, 1536, 256);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<512>(s[this->paths[i]], 1024, 1024 + 512, 1024, 512);
		}
		for (auto i = 0; i < this->n_active_paths; i++) 
		{
			API_polar::template xo<1024>(s[this->paths[i]], 0, 0 + 1024, 0, 1024);
		}
	}
};
}
}
#endif
