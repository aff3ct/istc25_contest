#ifndef POLAR_FUNCTIONS_HPP_
#define POLAR_FUNCTIONS_HPP_

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


template <int N_ELMTS>
inline static void f(const float* l_a,
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

    auto r = sum_l < 0 ? 1 : 0;
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
        s_a[i] = l_a[i] < 0 ? 1 : 0;
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
        s_a[cur_min_pos] = (s_a[cur_min_pos] == 0) ? 1 : 0; // correction
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

#endif // POLAR_FUNCTIONS_HPP_