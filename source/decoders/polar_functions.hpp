template <typename B, typename R>
B sgn(R val)
{
	return (B)((R(0) < val) - (val < R(0)));
}


template <int N_ELMTS>
static void f(std::vector<float>& l,
       const int off_l_a,
       const int off_l_b,
       const int off_l_c,
       int n_elmts)
{
    const float* l_a = l.data() + off_l_a;
    const float* l_b = l.data() + off_l_b;
    float* l_c = l.data() + off_l_c;

    for (auto i = 0; i < N_ELMTS; i++)
    {
        auto sign_lambda_a_b = sgn<int, float>(l_a[i] * l_b[i]);
        auto abs_lambda_a = fabsf(l_a[i]);
        auto abs_lambda_b = fabsf(l_b[i]);
        l_c[i] = (float)sign_lambda_a_b * std::min(abs_lambda_a, abs_lambda_b);
    }
}

template <int N_ELMTS>
static void g(std::vector<int>& s,
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

    for (auto i = 0; i < N_ELMTS; i++)
        l_c[i] = ((s_a[i] == 0) ? l_a[i] : -l_a[i]) + l_b[i];
}

template <int N_ELMTS>
static void g0(std::vector<float>& l,
        const int off_l_a,
        const int off_l_b,
        const int off_l_c,
        int n_elmts)
{
    const float* l_a = l.data() + off_l_a;
    const float* l_b = l.data() + off_l_b;
    float* l_c = l.data() + off_l_c;

    for (auto i = 0; i < N_ELMTS; i++)
        l_c[i] = l_a[i] + l_b[i];

}

template <int N_ELMTS>
static void gr(std::vector<int>& s,
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
    const auto u = s_a[0];

    for (auto i = 0; i < N_ELMTS; i++)
        l_c[i] = ((u == 0) ? l_a[i] : -l_a[i]) + l_b[i];
}

template <int N_ELMTS>
static void h(std::vector<int>& s,
       const std::vector<float>& l,
       const int off_l_a,
       const int off_s_a,
       int n_elmts)
{
    const float* l_a = l.data() + off_l_a;
    int* s_a = s.data() + off_s_a;

    for (auto i = 0; i < N_ELMTS; i++)
        s_a[i] = l_a[i] < 0;
}

template <int N_ELMTS>
static void h0(std::vector<int>& s,
        const int off_s_a,
        int n_elmts)
{
    std::fill(s.begin() + off_s_a, s.begin() + off_s_a + n_elmts, 0);
}

template <int N_ELMTS>
static void rep(std::vector<int>& s,
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
static bool spc(std::vector<int>& s,
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
static void xo(std::vector<int>& s,
        const int off_s_a,
        const int off_s_b,
        const int off_s_c,
        int n_elmts)
{
    const int* s_a = s.data() + off_s_a;
    const int* s_b = s.data() + off_s_b;
    int* s_c = s.data() + off_s_c;

    for (auto i = 0; i < N_ELMTS; i++)
        s_c[i] = s_a[i] ^ s_b[i];
}

template <int N_ELMTS>
static void xo0(std::vector<int>& s,
        const int off_s_b,
        const int off_s_c,
        int n_elmts)
{
    const int* s_b = s.data() + off_s_b;
    int* s_c = s.data() + off_s_c;

    std::copy(s_b, s_b + N_ELMTS, s_c);
}

