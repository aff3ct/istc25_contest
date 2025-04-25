/*!
* \file
* \brief Class module::Decoder_polar_SCL_fast_CA_sys.
*/
#ifndef DECODER_POLAR_SCL_FAST_CA_SYS_
#define DECODER_POLAR_SCL_FAST_CA_SYS_

#include <vector>
#include <cmath>
#include "Decoder_polar.hpp"
#include "polar_functions.hpp"
#include "LC_sorter.hpp"
#include "CRC.hpp"

namespace aff3ct
{
namespace module
{

class Decoder_polar_SCL_fast_CA_sys : public Decoder_polar
{

protected:

    const int L;

    std ::vector<int >    paths;          // active paths
    std ::vector<float >  metrics;          // active paths
    std::vector<std::vector<float>>    l;            // lambda, LR or LLR
    std::vector<std::vector<int>>      s;              // bits, partial sums
    std::vector<std::vector<float>> metrics_vec;    // list of candidate metrics to be sorted
    std::vector<int>      dup_count;      // number of duplications of a path, at updating time
    std::vector<int>      bit_flips;      // index of the bits to be flipped
    std::vector<bool>     is_even;        // used to store parity of a spc node

    int best_path;
    int n_active_paths;

    std::vector<std::vector<int>>     n_array_ref;    // number of times an array is used
    std::vector<std::vector<int>>     path_2_array;   // give array used by a path
    tools::LC_sorter<float> sorter;
    std::vector<int> best_idx;
    std::vector<float> l_tmp;
    std::vector<int> U_test;

    std::vector<float> Y_N_vec;
    float * Y_N;

    CRC<int>& crc;
    const  std::vector<bool> &frozen_bits; // frozen bits

    bool fast_store;

    int check;

public:
    Decoder_polar_SCL_fast_CA_sys(const int& K, const int& N, const int& L, const std::vector<bool>& frozen_bits, CRC<int>& crc)
    : Decoder_polar(K, N),
        L(L),
        paths(L),
        metrics(L),
        l(L, std::vector<float>(N)),
        s(L, std::vector<int>(N)),
        metrics_vec(3, std::vector<float>()),
        dup_count(L, 0),
        bit_flips(4 * L),
        is_even(L),
        best_path(0),
        n_active_paths(1),
        n_array_ref(L, std::vector<int>(m)),
        path_2_array(L, std::vector<int>(m)),
        sorter(N),
        best_idx(L),
        l_tmp(N),
        U_test(N),
        Y_N_vec(N),
        Y_N(Y_N_vec.data()),
        crc(crc),
        frozen_bits(frozen_bits),
        fast_store(false),
        check(0)
    {
        metrics_vec[0].resize(L * 2);
        metrics_vec[1].resize(L * 4);
        metrics_vec[2].resize((L <= 2 ? 4 : 8) * L);
    };
    virtual ~Decoder_polar_SCL_fast_CA_sys() = default;

    int decode(llrvec &llr, bitvec &cw_est, bitvec &info_est)
    {
        // Copy the LLRs to the internal buffer
        this->_load(llr);

        this->init_buffers();

        // Call the decode function
        this->_decode(Y_N);
        this->select_best_path();


        // Store the decoded bits
        this->_store(cw_est, info_est);

        return check;
    }

protected:

    void print_llr()
    {
        for (auto l = 0; l < this->n_active_paths; l++)
        {
            std::cout << "l[" << l << "]: ";
            for (auto i = 0; i < this->N; i++)
            {
                std::cout << this->l[l][i] << " ";
            }
            std::cout << std::endl;
        }
    }
    void print_s()
    {
        for (auto l = 0; l < this->n_active_paths; l++)
        {
            std::cout << "s[" << l << "]: ";
            for (auto i = 0; i < this->N; i++)
            {
                std::cout << this->s[l][i] << " ";
            }
            std::cout << std::endl;
        }
    }
    void print_metrics()
    {
        for (auto l = 0; l < this->n_active_paths; l++)
            std::cout << "metrics[" << l << "]: " << metrics[l] << std::endl;
    }
    void print_paths()
    {
        std::cout << "paths: ";
        for (auto i = 0; i < this->n_active_paths; i++)
        {
            std::cout << this->paths[i] << " ";
        }
        std::cout << std::endl;
    }

            void set_name(const std::string& name)
            {
            }

            void _load(llrvec llr)
            {
                std::copy(llr.begin(), llr.end(), this->Y_N_vec.begin());
                std::fill(this->Y_N_vec.begin() + llr.size(), this->Y_N_vec.end(), +std::numeric_limits<float>::infinity());

                for (auto i = 0; i < L; i++)
                    std::fill(s[i].begin(), s[i].end(), 0);
            }

    virtual void _decode        (const float *Y_N){}
            void _store         (bitvec& cw_est, bitvec& info_est)
            {

                for (std::size_t i = 0; i < this->s[best_path].size(); i++)
                    this->s[best_path][i] = this->s[best_path][i] != 0 ? 1 : 0;


                auto k = 0;

                for (auto i = 0; i < this->N; i++)
                {
                    if (this->frozen_bits[i] == 0)
                        info_est[k++] = this->s[best_path][i];
                }
                std::copy(this->s[best_path].begin(), this->s[best_path].begin() + cw_est.size(), cw_est.begin());
            }

    template <int REV_D, int N_ELMTS> inline void update_paths_r0(const int off_l, const int off_s);
    template <int REV_D, int N_ELMTS> inline void update_paths_r1(const int off_l, const int off_s);
    template <int REV_D, int N_ELMTS> inline void update_paths_rep(const int off_l, const int off_s);
    template <int REV_D, int N_ELMTS> inline void update_paths_spc(const int off_l, const int off_s);

    virtual inline void init_buffers    (                             );
    inline void delete_path     (int path_id                  );
    virtual inline int  select_best_path(                             );
    inline int  up_ref_array_idx(const int path, const int r_d); // return the array

private:
    inline void flip_bits_r1 (const int old_path, const int new_path, const int dup, const int off_s, const int n_elmts);
    inline void flip_bits_spc(const int old_path, const int new_path, const int dup, const int off_s, const int n_elmts);

    inline void erase_bad_paths (                                                                        );
    inline int  duplicate_tree  (const int old_path, const int off_l, const int off_s, const int n_elmts ); // return the new_path
    inline bool crc_check       (std::vector<int> &s  );

};
}
}

#include "Decoder_polar_SCL_fast_CA_sys.hxx"

#endif /* DECODER_POLAR_SCL_FAST_CA_SYS_ */
