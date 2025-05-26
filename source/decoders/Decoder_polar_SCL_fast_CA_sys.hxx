#include <algorithm>

#include "polar_functions.hpp"

namespace aff3ct
{
namespace module
{

inline float sat_m(const float m) { return m; } // TODO REMOVE

template <int REV_D, int N_ELMTS>
void Decoder_polar_SCL_fast_CA_sys
::update_paths_r0(const int off_l, const int off_s)
{
	if (n_active_paths > 1)
    for (auto i = 0; i < n_active_paths; i++)
    {
        const auto path  = paths[i];
        const auto array = path_2_array[path][REV_D];

        auto pen = (float)0;
        for (auto j = 0; j < N_ELMTS; j++)
            pen = sat_m(pen + sat_m(-std::min((float)l[array][off_l +j], (float)0)));
        metrics[path] = sat_m(metrics[path] + pen); // add a penalty to the current path metric
    }

//	if (!polar_patterns.exist_node_type(polar_node_t::RATE_0_LEFT, REV_D +1))
    for (auto i = 0; i < n_active_paths; i++)
        base_api_polar::h0<N_ELMTS>(s[paths[i]], off_s, N_ELMTS);
}

template <int REV_D, int N_ELMTS>
void Decoder_polar_SCL_fast_CA_sys
::update_paths_r1(const int off_l, const int off_s)
{
	if (REV_D == 0)
	{
		update_paths_rep<REV_D, N_ELMTS>(off_l, off_s);
	}
	else
	{
		// generate the candidates with the Chase-II algorithm
		if (N_ELMTS == 2)
		{
			for (auto i = 0; i < n_active_paths; i++)
			{
				const auto path  = paths[i];
				const auto array = path_2_array[path][REV_D];

				bit_flips[2 * path +0] = 0;
				bit_flips[2 * path +1] = 1;

				const auto pen0 = sat_m(std::abs(l[array][off_l + bit_flips[2 * path +0]]));
				const auto pen1 = sat_m(std::abs(l[array][off_l + bit_flips[2 * path +1]]));

				metrics_vec[1][4 * path +0] =          metrics       [    path   ];
				metrics_vec[1][4 * path +1] = sat_m(metrics       [    path   ] + pen0);
				metrics_vec[1][4 * path +2] = sat_m(metrics       [    path   ] + pen1);
				metrics_vec[1][4 * path +3] = sat_m(metrics_vec[1][4 * path +1] + pen1);
			}
		}
		else
		{
			for (auto i = 0; i < n_active_paths; i++)
			{
				const auto path  = paths[i];
				const auto array = path_2_array[path][REV_D];

				for (auto i = 0; i < N_ELMTS; i++) l_tmp[i] = std::abs(l[array][off_l +i]);
				sorter.partial_sort_destructive(l_tmp.data(), best_idx, N_ELMTS, 2);
//				sorter_simd.partial_sort_abs(l[array].data() + off_l, best_idx, N_ELMTS, 2);

				bit_flips[2 * path +0] = best_idx[0];
				bit_flips[2 * path +1] = best_idx[1];

				const auto pen0 = sat_m(std::abs(l[array][off_l + bit_flips[2 * path +0]]));
				const auto pen1 = sat_m(std::abs(l[array][off_l + bit_flips[2 * path +1]]));

				metrics_vec[1][4 * path +0] =          metrics       [    path   ];
				metrics_vec[1][4 * path +1] = sat_m(metrics       [    path   ] + pen0);
				metrics_vec[1][4 * path +2] = sat_m(metrics       [    path   ] + pen1);
				metrics_vec[1][4 * path +3] = sat_m(metrics_vec[1][4 * path +1] + pen1);
			}
		}
		for (auto i = n_active_paths; i < L; i++)
			for (auto j = 0; j < 4; j++)
				metrics_vec[1][4 * paths[i] +j] = std::numeric_limits<float>::max();

		// L first of the lists are the L best paths
		const auto n_list = (n_active_paths * 4 >= L) ? L : n_active_paths * 4;
		sorter.partial_sort(metrics_vec[1].data(), best_idx, L * 4, n_list);

		// count the number of duplications per path
		for (auto i = 0; i < n_list; i++)
			dup_count[best_idx[i] / 4]++;

		// erase bad paths
		erase_bad_paths();

		for (auto i = 0; i < n_list; i++)
		{
			const auto path  = best_idx[i] / 4;
			const auto dup   = best_idx[i] % 4;
			const auto array = path_2_array[path][REV_D];

			base_api_polar::h<N_ELMTS>(s[path], l[array], off_l, off_s, N_ELMTS);

			const auto new_path = (dup_count[path] > 1) ? duplicate_tree(path, off_l, off_s, N_ELMTS) : path;
			flip_bits_r1(path, new_path, dup, off_s, N_ELMTS);
			metrics[new_path] = metrics_vec[1][best_idx[i]];

			dup_count[path]--;
		}
	}
}

template <int REV_D, int N_ELMTS>
void Decoder_polar_SCL_fast_CA_sys
::update_paths_rep(const int off_l, const int off_s)
{
	int b = bit_init<int>();

	// generate the two possible candidates
	for (auto i = 0; i < n_active_paths; i++)
	{
		const auto path  = paths[i];
		const auto array = path_2_array[path][REV_D];

		auto pen0 = (float)0;
		auto pen1 = (float)0;
		for (auto j = 0; j < N_ELMTS; j++)
		{
			pen0 = sat_m(pen0 + sat_m(-std::min(l[array][off_l +j], (float)0)));
			pen1 = sat_m(pen1 + sat_m(+std::max(l[array][off_l +j], (float)0)));
		}
		metrics_vec[0][2 * path +0] = sat_m(metrics[path] + pen0);
		metrics_vec[0][2 * path +1] = sat_m(metrics[path] + pen1);
	}

	if (n_active_paths <= L / 2)
	{
		const auto n_active_paths_cpy = n_active_paths;
		for (auto i = 0; i < n_active_paths_cpy; i++)
		{
			const auto path = paths[i];
			const auto new_path = duplicate_tree(path, off_l, off_s, N_ELMTS);

			std::fill(s[    path].begin() + off_s, s[    path].begin() + off_s + N_ELMTS, 0);
			std::fill(s[new_path].begin() + off_s, s[new_path].begin() + off_s + N_ELMTS, b);

			metrics[    path] = metrics_vec[0][2 * path +0];
			metrics[new_path] = metrics_vec[0][2 * path +1];
		}
	}
	else // n_active_paths == L
	{
		// sort hypothetic metrics
		sorter.partial_sort(metrics_vec[0].data(), best_idx, L * 2, L);

		// count the number of duplications per path
		for (auto i = 0; i < L; i++)
			dup_count[best_idx[i] / 2]++;

		// erase bad paths
		erase_bad_paths();

		// duplicate paths
		for (auto path = 0; path < L; path++)
		{
			if (dup_count[path] == 1)
			{
				const auto comp = metrics_vec[0][2 * path +0] > metrics_vec[0][2 * path +1];
				std::fill(s[path].begin() + off_s, s[path].begin() + off_s + N_ELMTS, comp ? b : 0);

				metrics[path] = metrics_vec[0][2 * path + (comp ? 1 : 0)];
			}
			else if (dup_count[path] == 2)
			{
				const auto new_path = duplicate_tree(path, off_l, off_s, N_ELMTS);
				std::fill(s[    path].begin() + off_s, s[    path].begin() + off_s + N_ELMTS, 0);
				std::fill(s[new_path].begin() + off_s, s[new_path].begin() + off_s + N_ELMTS, b);

				metrics[    path] = metrics_vec[0][2 * path +0];
				metrics[new_path] = metrics_vec[0][2 * path +1];
			}

			dup_count[path] = 0;
		}
	}
}

template <int REV_D, int N_ELMTS>
void Decoder_polar_SCL_fast_CA_sys
::update_paths_spc(const int off_l, const int off_s)
{
	// the number of candidates to generate per list
	const auto n_cands = L <= 2 ? 4 : 8;

	// generate the candidates with the Chase-II algorithm
	if (N_ELMTS == 4)
	{
		for (auto i = 0; i < n_active_paths; i++)
		{
			const auto path  = paths[i];
			const auto array = path_2_array[paths[i]][REV_D];

			for (auto j = 0; j < 4; j++)
				bit_flips[4 * path +j] = j;

			auto sum = 0;
			for (auto j = 0; j < N_ELMTS; j++)
				sum ^= (l[array][off_l +j] < 0);
			is_even[path] = (sum == 0);

			const auto pen0 = sat_m(std::abs(l[array][off_l + bit_flips[4 * path +0]]));
			const auto pen1 = sat_m(std::abs(l[array][off_l + bit_flips[4 * path +1]]));
			const auto pen2 = sat_m(std::abs(l[array][off_l + bit_flips[4 * path +2]]));
			const auto pen3 = sat_m(std::abs(l[array][off_l + bit_flips[4 * path +3]]));

			metrics_vec[2][n_cands * path +0] =       sat_m(metrics[path] + (!is_even[path] ? pen0 : 0));
			metrics_vec[2][n_cands * path +1] = sat_m(sat_m(metrics[path] + ( is_even[path] ? pen0 : 0)) + pen1);
			metrics_vec[2][n_cands * path +2] = sat_m(sat_m(metrics[path] + ( is_even[path] ? pen0 : 0)) + pen2);
			metrics_vec[2][n_cands * path +3] = sat_m(sat_m(metrics[path] + ( is_even[path] ? pen0 : 0)) + pen3);

			if (L > 2)
			{
				metrics_vec[2][n_cands * path +4] = sat_m(sat_m(metrics_vec[2][n_cands * path +0] + pen1) + pen2);
				metrics_vec[2][n_cands * path +5] = sat_m(sat_m(metrics_vec[2][n_cands * path +0] + pen1) + pen3);
				metrics_vec[2][n_cands * path +6] = sat_m(sat_m(metrics_vec[2][n_cands * path +0] + pen2) + pen3);
				metrics_vec[2][n_cands * path +7] = sat_m(sat_m(metrics_vec[2][n_cands * path +1] + pen2) + pen3);
			}
		}
	}
	else
	{
		for (auto i = 0; i < n_active_paths; i++)
		{
			const auto path  = paths[i];
			const auto array = path_2_array[paths[i]][REV_D];

			for (auto i = 0; i < N_ELMTS; i++) l_tmp[i] = std::abs(l[array][off_l +i]);
			sorter.partial_sort_destructive(l_tmp.data(), best_idx, N_ELMTS, 4);
//			sorter_simd.partial_sort_abs(l[array].data() + off_l, best_idx, N_ELMTS, 4);

			for (auto j = 0; j < 4; j++)
				bit_flips[4 * path +j] = best_idx[j];

			auto sum = 0;
			for (auto j = 0; j < N_ELMTS; j++)
				sum ^= (l[array][off_l +j] < 0);
			is_even[path] = (sum == 0);

			const auto pen0 = sat_m(std::abs(l[array][off_l + bit_flips[4 * path +0]]));
			const auto pen1 = sat_m(std::abs(l[array][off_l + bit_flips[4 * path +1]]));
			const auto pen2 = sat_m(std::abs(l[array][off_l + bit_flips[4 * path +2]]));
			const auto pen3 = sat_m(std::abs(l[array][off_l + bit_flips[4 * path +3]]));

			metrics_vec[2][n_cands * path +0] =       sat_m(metrics[path] + (!is_even[path] ? pen0 : 0));
			metrics_vec[2][n_cands * path +1] = sat_m(sat_m(metrics[path] + ( is_even[path] ? pen0 : 0)) + pen1);
			metrics_vec[2][n_cands * path +2] = sat_m(sat_m(metrics[path] + ( is_even[path] ? pen0 : 0)) + pen2);
			metrics_vec[2][n_cands * path +3] = sat_m(sat_m(metrics[path] + ( is_even[path] ? pen0 : 0)) + pen3);

			if (L > 2)
			{
				metrics_vec[2][n_cands * path +4] = sat_m(sat_m(metrics_vec[2][n_cands * path +0] + pen1) + pen2);
				metrics_vec[2][n_cands * path +5] = sat_m(sat_m(metrics_vec[2][n_cands * path +0] + pen1) + pen3);
				metrics_vec[2][n_cands * path +6] = sat_m(sat_m(metrics_vec[2][n_cands * path +0] + pen2) + pen3);
				metrics_vec[2][n_cands * path +7] = sat_m(sat_m(metrics_vec[2][n_cands * path +1] + pen2) + pen3);
			}
		}
	}
	for (auto i = n_active_paths; i < L; i++)
		for (auto j = 0; j < n_cands; j++)
			metrics_vec[2][n_cands * paths[i] +j] = std::numeric_limits<float>::max();

	// L first of the lists are the L best paths
	const auto n_list = (n_active_paths * n_cands >= L) ? L : n_active_paths * n_cands;
	sorter.partial_sort(metrics_vec[2].data(), best_idx, n_cands * L, n_list);

	// count the number of duplications per path
	for (auto i = 0; i < n_list; i++)
		dup_count[best_idx[i] / n_cands]++;

	// erase bad paths
	erase_bad_paths();

	for (auto i = 0; i < n_list; i++)
	{
		const auto path  = best_idx[i] / n_cands;
		const auto dup   = best_idx[i] % n_cands;
		const auto array = path_2_array[path][REV_D];

		base_api_polar::h<N_ELMTS>(s[path], l[array], off_l, off_s, N_ELMTS);

		const auto new_path = (dup_count[path] > 1) ? duplicate_tree(path, off_l, off_s, N_ELMTS) : path;
		flip_bits_spc(path, new_path, dup, off_s, N_ELMTS);
		metrics[new_path] = metrics_vec[2][best_idx[i]];

		dup_count[path]--;
	}
}

void Decoder_polar_SCL_fast_CA_sys
::flip_bits_spc(const int old_path, const int new_path, const int dup, const int off_s, const int n_elmts)
{
	constexpr int b = bit_init<int>();

	switch(dup)
	{
	case 0 :
		if (!is_even[old_path])
			s[new_path][off_s + bit_flips[4 * old_path +0]] = s[old_path][off_s + bit_flips[4 * old_path +0]] ? 0 : b;
		break;
	case 1 :
		if (is_even[old_path])
			s[new_path][off_s + bit_flips[4 * old_path +0]] = s[old_path][off_s + bit_flips[4 * old_path +0]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +1]] = s[old_path][off_s + bit_flips[4 * old_path +1]] ? 0 : b;
		break;
	case 2 :
		if (is_even[old_path])
			s[new_path][off_s + bit_flips[4 * old_path +0]] = s[old_path][off_s + bit_flips[4 * old_path +0]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +2]] = s[old_path][off_s + bit_flips[4 * old_path +2]] ? 0 : b;
		break;
	case 3 :
		if (is_even[old_path])
			s[new_path][off_s + bit_flips[4 * old_path +0]] = s[old_path][off_s + bit_flips[4 * old_path +0]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +3]] = s[old_path][off_s + bit_flips[4 * old_path +3]] ? 0 : b;
		break;
	case 4 :
		if (!is_even[old_path])
			s[new_path][off_s + bit_flips[4 * old_path +0]] = s[old_path][off_s + bit_flips[4 * old_path +0]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +1]] = s[old_path][off_s + bit_flips[4 * old_path +1]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +2]] = s[old_path][off_s + bit_flips[4 * old_path +2]] ? 0 : b;
		break;
	case 5 :
		if (!is_even[old_path])
			s[new_path][off_s + bit_flips[4 * old_path +0]] = s[old_path][off_s + bit_flips[4 * old_path +0]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +1]] = s[old_path][off_s + bit_flips[4 * old_path +1]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +3]] = s[old_path][off_s + bit_flips[4 * old_path +3]] ? 0 : b;
		break;
	case 6 :
		if (!is_even[old_path])
			s[new_path][off_s + bit_flips[4 * old_path +0]] = s[old_path][off_s + bit_flips[4 * old_path +0]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +2]] = s[old_path][off_s + bit_flips[4 * old_path +2]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +3]] = s[old_path][off_s + bit_flips[4 * old_path +3]] ? 0 : b;
		break;
	case 7 :
		if (is_even[old_path])
			s[new_path][off_s + bit_flips[4 * old_path +0]] = s[old_path][off_s + bit_flips[4 * old_path +0]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +1]] = s[old_path][off_s + bit_flips[4 * old_path +1]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +2]] = s[old_path][off_s + bit_flips[4 * old_path +2]] ? 0 : b;
		s[new_path][off_s + bit_flips[4 * old_path +3]] = s[old_path][off_s + bit_flips[4 * old_path +3]] ? 0 : b;
		break;
	default:
		throw std::runtime_error("Flip bits error on SPC node.");
		break;
	}
}

void Decoder_polar_SCL_fast_CA_sys
::delete_path(int path_id)
{
	const auto old_path = paths[path_id];
	for (auto i = 0; i < m; i++)
		n_array_ref[path_2_array[old_path][i]][i]--;

	paths[path_id] = paths[--n_active_paths];
	paths[n_active_paths] = old_path;
}

void Decoder_polar_SCL_fast_CA_sys
::flip_bits_r1(const int old_path, const int new_path, const int dup, const int off_s, const int n_elmts)
{
	constexpr int b = bit_init<int>();

	switch (dup)
	{
	case 0:
		// nothing to do
		break;
	case 1:
		s[new_path][off_s + bit_flips[2 * old_path +0]] = !s[old_path][off_s + bit_flips[2 * old_path +0]] ? b : 0;
		break;
	case 2:
		s[new_path][off_s + bit_flips[2 * old_path +1]] = !s[old_path][off_s + bit_flips[2 * old_path +1]] ? b : 0;
		break;
	case 3:
		s[new_path][off_s + bit_flips[2 * old_path +0]] = !s[old_path][off_s + bit_flips[2 * old_path +0]] ? b : 0;
		s[new_path][off_s + bit_flips[2 * old_path +1]] = !s[old_path][off_s + bit_flips[2 * old_path +1]] ? b : 0;
		break;
	default:
		throw std::runtime_error("Flip bits error on rate 1 node.");
		break;
	}
}

bool Decoder_polar_SCL_fast_CA_sys
::crc_check(std::vector<int> &s)
{
	auto k = 0;
	for (auto i = 0; i < this->N; i++)
	{
		if (this->frozen_bits[i] == 0)
			U_test[k++] = s[i];
	}
	this->check = this->crc.check(U_test.data());
	return this->check;
}

int Decoder_polar_SCL_fast_CA_sys
::select_best_path()
{
	std::sort(this->paths.begin(), this->paths.begin() + this->n_active_paths,
		[this](int x, int y){
			return this->metrics[x] < this->metrics[y];
		});

	auto i = 0;
	while (i < this->n_active_paths && !crc_check(this->s[this->paths[i]])) i++;

	this->best_path = (i == this->n_active_paths) ? this->paths[0] : this->paths[i];
	fast_store = i != this->n_active_paths;

	return this->n_active_paths -i;
}

void Decoder_polar_SCL_fast_CA_sys
::erase_bad_paths()
{
	// erase bad paths
	auto k = 0;
	auto n_active_paths_cpy = n_active_paths;
	for (auto i = 0; i < n_active_paths_cpy; i++)
		if (dup_count[paths[k]] == 0)
			delete_path(k);
		else
			k++;
}

int Decoder_polar_SCL_fast_CA_sys
::duplicate_tree(const int old_path, const int off_l, const int off_s, const int n_elmts)
{
	const auto new_path = paths[n_active_paths++];

	std::copy(path_2_array[old_path].begin(), path_2_array[old_path].end(), path_2_array[new_path].begin());

	for (auto i = 0; i < m; i++)
		n_array_ref[path_2_array[new_path][i]][i]++;

	std::copy(s[old_path].begin(), s[old_path].begin() + off_s + n_elmts, s[new_path].begin());

	return new_path;
}

void Decoder_polar_SCL_fast_CA_sys
::init_buffers()
{
    metrics[0] = std::numeric_limits<float>::min();
	std::iota(paths.begin(), paths.begin() + L, 0);

	n_active_paths = 1;

	// at the beginning, path 0 points to array 0
	std::fill(n_array_ref [0].begin(), n_array_ref [0].end(), 1);
	std::fill(path_2_array[0].begin(), path_2_array[0].end(), 0);

	for (auto i = 1; i < L; i++)
		std::fill(n_array_ref[i].begin(), n_array_ref[i].end(), 0);
}


int Decoder_polar_SCL_fast_CA_sys
::up_ref_array_idx(const int path, const int r_d)
{
	auto old_array = path_2_array[path][r_d];

	// if more than 1 path points to the array
	if (n_array_ref[old_array][r_d] > 1)
	{
		// allocate new array to given path, r_d
		n_array_ref[old_array][r_d]--;

		auto new_array = 0;
		while (n_array_ref[new_array][r_d]) new_array++;

		path_2_array[path     ][r_d] = new_array;
		n_array_ref [new_array][r_d]++;

		return new_array;
	}

	return old_array;
}

}
}