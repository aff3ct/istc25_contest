#ifndef POLAR_FUNCTIONS_HPP_
#define POLAR_FUNCTIONS_HPP_
#pragma GCC push_options
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,fma")

#include <immintrin.h>

template <typename B, typename R>
B sgn(R val)
{
	return (B)((R(0) < val) - (val < R(0)));
}

template <typename B>
constexpr B bit_init()
{
	return (B)(((B)1) << (sizeof(B) * 8 -1));
}

struct base_api_polar {

    template <int N_ELMTS>
    inline static void f(
        const float* l_a,
        const float* l_b,
        float* l_c,
        int n_elmts)
    {
        for (auto i = 0; i < N_ELMTS; i++)
        {
            auto sign_lambda_a_b = sgn<int, float>(l_a[i] * l_b[i]);
            auto abs_lambda_a = fabsf(l_a[i]);
            auto abs_lambda_b = fabsf(l_b[i]);
            l_c[i] = (float)sign_lambda_a_b * std::min(abs_lambda_a, abs_lambda_b);
        }
    }

    template <int N_ELMTS>
    inline static void f(std::vector<float>& l,
        const int off_l_a,
        const int off_l_b,
        const int off_l_c,
        int n_elmts)
    {
        const float* l_a = l.data() + off_l_a;
        const float* l_b = l.data() + off_l_b;
        float* l_c = l.data() + off_l_c;

        f<N_ELMTS>(l_a, l_b, l_c, n_elmts);
    }

    template <int N_ELMTS>
    inline static void g(const float* l_a,
            const float* l_b,
            const int* s_a,
            float* l_c,
            int n_elmts)
    {
        for (auto i = 0; i < N_ELMTS; i++)
            l_c[i] = ((s_a[i] == 0) ? l_a[i] : -l_a[i]) + l_b[i];
    }

    template <int N_ELMTS>
    inline static void g(std::vector<int>& s,
        std::vector<float>& l,
        const int off_l_a,
        const int off_l_b,
        const int off_s_a,
        const int off_l_c,
        int n_elmts)
    {
        const float* l_a = l.data() + off_l_a;
        const float* l_b = l.data() + off_l_b;
        const int* s_a = s.data() + off_s_a;
        float* l_c = l.data() + off_l_c;

        g<N_ELMTS>(l_a, l_b, s_a, l_c, n_elmts);
    }

    template <int N_ELMTS>
    inline static void g0(const float* l_a,
            const float* l_b,
            float* l_c,
            int n_elmts)
    {
        for (auto i = 0; i < N_ELMTS; i++)
            l_c[i] = l_a[i] + l_b[i];
    }

    template <int N_ELMTS>
    inline static void g0(std::vector<float>& l,
            const int off_l_a,
            const int off_l_b,
            const int off_l_c,
            int n_elmts)
    {
        const float* l_a = l.data() + off_l_a;
        const float* l_b = l.data() + off_l_b;
        float* l_c = l.data() + off_l_c;

        g0<N_ELMTS>(l_a, l_b, l_c, n_elmts);
    }

    template <int N_ELMTS>
    inline static void gr(const float* l_a,
            const float* l_b,
            const int* s_a,
            float* l_c,
            int n_elmts)
    {
        const auto u = s_a[0];

        for (auto i = 0; i < N_ELMTS; i++)
            l_c[i] = ((u == 0) ? l_a[i] : -l_a[i]) + l_b[i];
    }

    template <int N_ELMTS>
    inline static void gr(std::vector<int>& s,
            std::vector<float>& l,
            const int off_l_a,
            const int off_l_b,
            const int off_s_a,
            const int off_l_c,
            int n_elmts)
    {
        const float* l_a = l.data() + off_l_a;
        const float* l_b = l.data() + off_l_b;
        const int* s_a = s.data() + off_s_a;
        float* l_c = l.data() + off_l_c;

        gr<N_ELMTS>(l_a, l_b, s_a, l_c, n_elmts);
    }

    template <int N_ELMTS>
    inline static void h(const float* l_a,
            int* s_a,
            int n_elmts)
    {
        for (auto i = 0; i < N_ELMTS; i++)
            s_a[i] = (l_a[i] < 0) * bit_init<int>();
    }

    template <int N_ELMTS>
    inline static void h(std::vector<int>& s,
        const std::vector<float>& l,
        const int off_l_a,
        const int off_s_a,
        int n_elmts)
    {
        const float* l_a = l.data() + off_l_a;
        int* s_a = s.data() + off_s_a;

        h<N_ELMTS>(l_a, s_a, n_elmts);
    }

    template <int N_ELMTS>
    inline static void h0(int* s_a,
            int n_elmts)
    {
        std::fill(s_a, s_a + n_elmts, 0);
    }

    template <int N_ELMTS>
    inline static void h0(std::vector<int>& s,
            const int off_s_a,
            int n_elmts)
    {
        int* s_a = s.data() + off_s_a;

        h0<N_ELMTS>(s_a, n_elmts);
    }

    template <int N_ELMTS>
    inline static void rep(std::vector<int>& s,
            const std::vector<float>& l,
            const int off_l_a,
            const int off_s_a,
            int n_elmts)
    {
        const float* l_a = l.data() + off_l_a;
        int* s_a = s.data() + off_s_a;

        float sum_l = 0;
        for (auto i = 0; i < N_ELMTS; i++)
            sum_l += l_a[i];

        auto r = (sum_l < 0) * bit_init<int>();
        for (auto i = 0; i < N_ELMTS; i++)
            s_a[i] = r;
    }

    template <int N_ELMTS>
    inline static bool spc(std::vector<int>& s,
            const std::vector<float>& l,
            const int off_l_a,
            const int off_s_a,
            int n_elmts)
    {

        const float* l_a = l.data() + off_l_a;
        int* s_a = s.data() + off_s_a;

        auto cur_min_abs = std::numeric_limits<float>::max();
        auto cur_min_pos = -1;
        auto prod_sign = 1;
        for( auto i = 0; i < N_ELMTS; i++)
        {
            s_a[i] = l_a[i] < 0 ? bit_init<int>() : 0;
            auto sign = (s_a[i] == 0) ? 1 : -1;
            auto abs = (float)sign * l_a[i];

            if (cur_min_abs > abs)
            {
                cur_min_abs = abs;
                cur_min_pos = i;
            }

            prod_sign *= sign;
        }
        if (prod_sign < 0)
            s_a[cur_min_pos] = (s_a[cur_min_pos] == 0) ? bit_init<int>() : 0; // correction
        return (prod_sign < 0);
    }

    template <int N_ELMTS>
    inline static void xo(const int* s_a,
            const int* s_b,
            int* s_c,
            int n_elmts)
    {
        for (auto i = 0; i < N_ELMTS; i++)
            s_c[i] = s_a[i] ^ s_b[i];
    }

    template <int N_ELMTS>
    inline static void xo(std::vector<int>& s,
            const int off_s_a,
            const int off_s_b,
            const int off_s_c,
            int n_elmts)
    {
        const int* s_a = s.data() + off_s_a;
        const int* s_b = s.data() + off_s_b;
        int* s_c = s.data() + off_s_c;

        xo<N_ELMTS>(s_a, s_b, s_c, n_elmts);
    }

    template <int N_ELMTS>
    inline static void xo0(const int* s_b,
            int* s_c,
            int n_elmts)
    {
        for (auto i = 0; i < N_ELMTS; i++)
            s_c[i] = s_b[i];
    }

    template <int N_ELMTS>
    inline static void xo0(std::vector<int>& s,
            const int off_s_b,
            const int off_s_c,
            int n_elmts)
    {
        const int* s_b = s.data() + off_s_b;
        int* s_c = s.data() + off_s_c;

        xo0<N_ELMTS>(s_b, s_c, n_elmts);
    }
};

struct fast_api_polar : base_api_polar {
    template <int N_ELMTS>
    inline static void f(
        const float* l_a,
        const float* l_b,
        float* l_c,
        int n_elmts)
    {
        for (auto i = 0; i < N_ELMTS; i += 8)
        {
            const auto r_lambda_a = _mm256_loadu_ps(l_a + i);
            const auto r_lambda_b = _mm256_loadu_ps(l_b + i);

            const auto abs_mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x7FFFFFFF));
            const auto r_abs_lambda_a = _mm256_and_ps(r_lambda_a, abs_mask);
            const auto r_abs_lambda_b = _mm256_and_ps(r_lambda_b, abs_mask);
            const auto r_min_abs_lambda = _mm256_min_ps(r_abs_lambda_a, r_abs_lambda_b);
            const auto msb_mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
            const auto r_sign_lambda_a = _mm256_and_ps(r_lambda_a, msb_mask);
            const auto r_sign_lambda_b = _mm256_and_ps(r_lambda_b, msb_mask);
            const auto r_sign_lambda_c = _mm256_xor_ps(r_sign_lambda_a, r_sign_lambda_b);
            const auto r_lambda_c = _mm256_xor_ps(r_min_abs_lambda, _mm256_and_ps(r_sign_lambda_c, msb_mask));

            _mm256_storeu_ps(l_c + i, r_lambda_c);
        }
    }

    template <int N_ELMTS>
    inline static void f(std::vector<float>& l,
        const int off_l_a,
        const int off_l_b,
        const int off_l_c,
        int n_elmts)
    {
        const float* l_a = l.data() + off_l_a;
        const float* l_b = l.data() + off_l_b;
        float* l_c = l.data() + off_l_c;

        f<N_ELMTS>(l_a, l_b, l_c, n_elmts);
    }

    template <int N_ELMTS>
    inline static void g(const float* l_a,
            const float* l_b,
            const int* s_a,
            float* l_c,
            int n_elmts)
    {
        for (auto i = 0; i < N_ELMTS; i += 8)
        {
            const auto r_lambda_a = _mm256_loadu_ps(l_a + i);
            const auto r_lambda_b = _mm256_loadu_ps(l_b + i);
            const auto r_u = _mm256_loadu_ps((const float*)(s_a + i));
            const auto msb_mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
            const auto msb = _mm256_and_ps(r_u, msb_mask);
            auto r_lambda_c = _mm256_xor_ps(r_lambda_a, msb);
            r_lambda_c = _mm256_add_ps(r_lambda_c, r_lambda_b);
            _mm256_storeu_ps(l_c + i, r_lambda_c);
        }
    }

    template <int N_ELMTS>
    inline static void g(std::vector<int>& s,
        std::vector<float>& l,
        const int off_l_a,
        const int off_l_b,
        const int off_s_a,
        const int off_l_c,
        int n_elmts)
    {
        const float* l_a = l.data() + off_l_a;
        const float* l_b = l.data() + off_l_b;
        const int* s_a = s.data() + off_s_a;
        float* l_c = l.data() + off_l_c;

        g<N_ELMTS>(l_a, l_b, s_a, l_c, n_elmts);
    }


    template <int N_ELMTS>
    inline static void g0(const float* l_a,
            const float* l_b,
            float* l_c,
            int n_elmts)
    {
        for (auto i = 0; i < N_ELMTS; i += 8)
        {
            const auto r_lambda_a = _mm256_loadu_ps(l_a + i);
            const auto r_lambda_b = _mm256_loadu_ps(l_b + i);
            const auto r_lambda_c = _mm256_add_ps(r_lambda_a, r_lambda_b);
            _mm256_storeu_ps(l_c + i, r_lambda_c);
        }
    }

    template <int N_ELMTS>
    inline static void g0(std::vector<float>& l,
            const int off_l_a,
            const int off_l_b,
            const int off_l_c,
            int n_elmts)
    {
        const float* l_a = l.data() + off_l_a;
        const float* l_b = l.data() + off_l_b;
        float* l_c = l.data() + off_l_c;

        g0<N_ELMTS>(l_a, l_b, l_c, n_elmts);
    }


    template <int N_ELMTS>
    inline static void gr(const float* l_a,
            const float* l_b,
            const int* s_a,
            float* l_c,
            int n_elmts)
    {
        for (auto i = 0; i < N_ELMTS; i += 8)
        {
            const auto r_lambda_a = _mm256_loadu_ps(l_a + i);
            const auto r_lambda_b = _mm256_loadu_ps(l_b + i);
            const auto r_u = _mm256_loadu_ps((const float*)(s_a + i));
            const auto msb_mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
            const auto msb = _mm256_and_ps(r_u, msb_mask);
            auto r_lambda_c = _mm256_xor_ps(r_lambda_a, msb);
            r_lambda_c = _mm256_add_ps(r_lambda_c, r_lambda_b);
            _mm256_storeu_ps(l_c + i, r_lambda_c);
        }
    }

    template <int N_ELMTS>
    inline static void gr(std::vector<int>& s,
        std::vector<float>& l,
        const int off_l_a,
        const int off_l_b,
        const int off_s_a,
        const int off_l_c,
        int n_elmts)
    {
        const float* l_a = l.data() + off_l_a;
        const float* l_b = l.data() + off_l_b;
        const int* s_a = s.data() + off_s_a;
        float* l_c = l.data() + off_l_c;

        g<N_ELMTS>(l_a, l_b, s_a, l_c, n_elmts);
    }

    template <int N_ELMTS>
    inline static void h(const float* l_a,
            int* s_a,
            int n_elmts)
    {
        for (auto i = 0; i < N_ELMTS; i+=8)
        {
            const auto r_lambda_a = _mm256_loadu_ps(l_a + i);
            const auto msb_mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
            const auto r_u = _mm256_and_ps(r_lambda_a, msb_mask);
            _mm256_storeu_ps((float*)s_a + i, r_u);
        }
    }

    template <int N_ELMTS>
    inline static void h(std::vector<int>& s,
        const std::vector<float>& l,
        const int off_l_a,
        const int off_s_a,
        int n_elmts)
    {
        const float* l_a = l.data() + off_l_a;
        int* s_a = s.data() + off_s_a;

        h<N_ELMTS>(l_a, s_a, n_elmts);
    }


    template <int N_ELMTS>
    inline static void rep(std::vector<int>& s,
            const std::vector<float>& l,
            const int off_l_a,
            const int off_s_a,
            int n_elmts)
    {
        const auto stride = 8; // AVX2 processes 8 floats at a time

        auto r_sum_l = _mm256_setzero_ps();
        const float* l_a = l.data() + off_l_a;
        int* s_a = s.data() + off_s_a;

        for (auto i = 0; i < n_elmts; i += stride)
        {
            const auto r_lambda_a = _mm256_loadu_ps(l_a + i);
            r_sum_l = _mm256_add_ps(r_sum_l, r_lambda_a);
        }
        r_sum_l = _mm256_add_ps(r_sum_l, _mm256_permute2f128_ps(r_sum_l, r_sum_l, _MM_SHUFFLE(0, 0, 0, 1))); // horizontal sum
        r_sum_l = _mm256_add_ps(r_sum_l, _mm256_shuffle_ps(r_sum_l, r_sum_l, _MM_SHUFFLE(1, 0, 3, 2))); // horizontal sum
        r_sum_l = _mm256_add_ps(r_sum_l, _mm256_shuffle_ps(r_sum_l, r_sum_l, _MM_SHUFFLE(2, 3, 0, 1))); // horizontal sum
        const auto msb_mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
        const auto r_u = _mm256_and_ps(r_sum_l, msb_mask);

        for (auto i = 0; i < n_elmts; i += stride)
        {
            _mm256_storeu_ps((float*)(s_a + i), r_u);
        }
    }

    template <int N_ELMTS>
    inline static bool spc(std::vector<int>& s,
            const std::vector<float>& l,
            const int off_l_a,
            const int off_s_a,
            int n_elmts)
    {
        auto stride = 8; // AVX2 processes 8 floats at a time

        const float* l_a = l.data() + off_l_a;
        int* s_a = s.data() + off_s_a;

        auto r_cur_min_abs = _mm256_set1_ps(std::numeric_limits<float>::max());
        auto r_prod_sign = _mm256_set1_ps(1.0f);

        for (auto i = 0; i < N_ELMTS; i+= stride)
        {
            const auto r_lambda_a = _mm256_loadu_ps(l_a + i);
            const auto msb_mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
            const auto r_s_a = _mm256_and_ps(r_lambda_a, msb_mask);
            const auto r_sign = r_s_a;
            const auto abs_mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x7FFFFFFF));
            const auto r_abs_lambda_a = _mm256_and_ps(r_lambda_a, abs_mask);
            r_cur_min_abs = _mm256_min_ps(r_cur_min_abs, r_abs_lambda_a);
            r_prod_sign = _mm256_xor_ps(r_prod_sign, r_sign);
            _mm256_storeu_ps((float*)(s_a + i), r_s_a);
        }

        float cur_min_abs[8];
        _mm256_storeu_ps(cur_min_abs, r_cur_min_abs);
        float prod_sign[8];
        _mm256_storeu_ps(prod_sign, r_prod_sign);

        float s_cur_min_abs = std::numeric_limits<float>::max();
        float s_prod_sign = 1.0f;
        for (auto i = 0; i < 8; i += 1)
        {
            s_cur_min_abs = std::min(s_cur_min_abs, cur_min_abs[i]);
            s_prod_sign *= prod_sign[i];
        }

        if (s_prod_sign < 0) // make the correction
        {
            auto i = 0;
            // while (l_a[i] != s_cur_min_abs) i++;
            while (std::abs(l_a[i]) != s_cur_min_abs) i++;
            s_a[i] = (s_a[i] == 0) ? bit_init<int>() : 0;
        }

        return (s_prod_sign < 0);

    }
};

template <>
inline void fast_api_polar::f<4>(
    const float* l_a,
    const float* l_b,
    float* l_c,
    int n_elmts)
{
    for (auto i = 0; i < 4; i++)
    {
        auto sign_lambda_a_b = sgn<int, float>(l_a[i] * l_b[i]);
        auto abs_lambda_a = fabsf(l_a[i]);
        auto abs_lambda_b = fabsf(l_b[i]);
        l_c[i] = (float)sign_lambda_a_b * std::min(abs_lambda_a, abs_lambda_b);
    }
}

template <>
inline void fast_api_polar::f<2>(
    const float* l_a,
    const float* l_b,
    float* l_c,
    int n_elmts)
{
    for (auto i = 0; i < 2; i++)
    {
        auto sign_lambda_a_b = sgn<int, float>(l_a[i] * l_b[i]);
        auto abs_lambda_a = fabsf(l_a[i]);
        auto abs_lambda_b = fabsf(l_b[i]);
        l_c[i] = (float)sign_lambda_a_b * std::min(abs_lambda_a, abs_lambda_b);
    }
}

template <>
inline void fast_api_polar::g<4>(
        const float* l_a,
        const float* l_b,
        const int* s_a,
        float* l_c,
        int n_elmts)
{
    for (auto i = 0; i < 4; i++)
        l_c[i] = ((s_a[i] == 0) ? l_a[i] : -l_a[i]) + l_b[i];
}

template <>
inline void fast_api_polar::g<2>(
        const float* l_a,
        const float* l_b,
        const int* s_a,
        float* l_c,
        int n_elmts)
{
    for (auto i = 0; i < 2; i++)
        l_c[i] = ((s_a[i] == 0) ? l_a[i] : -l_a[i]) + l_b[i];
}


template <>
inline void fast_api_polar::g0<4>(
        const float* l_a,
        const float* l_b,
        float* l_c,
        int n_elmts)
{
    for (auto i = 0; i < 4; i++)
        l_c[i] = l_a[i] + l_b[i];
}

template <>
inline void fast_api_polar::g0<2>(
        const float* l_a,
        const float* l_b,
        float* l_c,
        int n_elmts)
{
    for (auto i = 0; i < 2; i++)
        l_c[i] = l_a[i] + l_b[i];
}

template <>
inline void fast_api_polar::gr<4>(
        const float* l_a,
        const float* l_b,
        const int* s_a,
        float* l_c,
        int n_elmts)
{
    const auto u = s_a[0];

    for (auto i = 0; i < 4; i++)
        l_c[i] = ((u == 0) ? l_a[i] : -l_a[i]) + l_b[i];
}

template <>
inline void fast_api_polar::gr<2>(
        const float* l_a,
        const float* l_b,
        const int* s_a,
        float* l_c,
        int n_elmts)
{
    const auto u = s_a[0];

    for (auto i = 0; i < 2; i++)
        l_c[i] = ((u == 0) ? l_a[i] : -l_a[i]) + l_b[i];
}

template <>
inline void fast_api_polar::h<4>(
    const float* l_a,
    int* s_a,
    int n_elmts)
{
    for (auto i = 0; i < 4; i++)
        s_a[i] = (l_a[i] < 0) * bit_init<int>();
}

template <>
inline void fast_api_polar::h<2>(
    const float* l_a,
    int* s_a,
    int n_elmts)
{
    for (auto i = 0; i < 2; i++)
        s_a[i] = (l_a[i] < 0) * bit_init<int>();
}

template <>
inline void fast_api_polar::rep<4>(std::vector<int>& s,
        const std::vector<float>& l,
        const int off_l_a,
        const int off_s_a,
        int n_elmts)
{
    const float* l_a = l.data() + off_l_a;
    int* s_a = s.data() + off_s_a;

    float sum_l = 0;
    for (auto i = 0; i < 4; i++)
        sum_l += l_a[i];

    auto r = (sum_l < 0) * bit_init<int>();
    for (auto i = 0; i < 4; i++)
        s_a[i] = r;
}

template <>
inline void fast_api_polar::rep<2>(std::vector<int>& s,
        const std::vector<float>& l,
        const int off_l_a,
        const int off_s_a,
        int n_elmts)
{
    const float* l_a = l.data() + off_l_a;
    int* s_a = s.data() + off_s_a;

    float sum_l = 0;
    for (auto i = 0; i < 2; i++)
        sum_l += l_a[i];

    auto r = (sum_l < 0) * bit_init<int>();
    for (auto i = 0; i < 2; i++)
        s_a[i] = r;
}

template <>
inline  bool fast_api_polar::spc<4>(std::vector<int>& s,
        const std::vector<float>& l,
        const int off_l_a,
        const int off_s_a,
        int n_elmts)
{

    const float* l_a = l.data() + off_l_a;
    int* s_a = s.data() + off_s_a;

    auto cur_min_abs = std::numeric_limits<float>::max();
    auto cur_min_pos = -1;
    auto prod_sign = 1;
    for( auto i = 0; i < 4; i++)
    {
        s_a[i] = l_a[i] < 0 ? bit_init<int>() : 0;
        auto sign = (s_a[i] == 0) ? 1 : -1;
        auto abs = (float)sign * l_a[i];

        if (cur_min_abs > abs)
        {
            cur_min_abs = abs;
            cur_min_pos = i;
        }

        prod_sign *= sign;
    }
    if (prod_sign < 0)
        s_a[cur_min_pos] = (s_a[cur_min_pos] == 0) ? bit_init<int>() : 0; // correction
    return (prod_sign < 0);
}


template <>
inline  bool fast_api_polar::spc<2>(std::vector<int>& s,
        const std::vector<float>& l,
        const int off_l_a,
        const int off_s_a,
        int n_elmts)
{

    const float* l_a = l.data() + off_l_a;
    int* s_a = s.data() + off_s_a;

    auto cur_min_abs = std::numeric_limits<float>::max();
    auto cur_min_pos = -1;
    auto prod_sign = 1;
    for( auto i = 0; i < 2; i++)
    {
        s_a[i] = l_a[i] < 0 ? bit_init<int>() : 0;
        auto sign = (s_a[i] == 0) ? 1 : -1;
        auto abs = (float)sign * l_a[i];

        if (cur_min_abs > abs)
        {
            cur_min_abs = abs;
            cur_min_pos = i;
        }

        prod_sign *= sign;
    }
    if (prod_sign < 0)
        s_a[cur_min_pos] = (s_a[cur_min_pos] == 0) ? bit_init<int>() : 0; // correction
    return (prod_sign < 0);
}

#endif // POLAR_FUNCTIONS_HPP_