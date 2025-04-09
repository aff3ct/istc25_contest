#include "CRC.hpp"

#include <stdexcept>

using namespace aff3ct;
using namespace aff3ct::module;

template <typename B>
CRC<B>::CRC(const int K, const std::string& poly_key)
    : K(K)
    , size(CRC<B>::get_size(poly_key))
    , polynomial(0)
    , polynomial_packed(CRC<B>::get_value(poly_key))
    , buff_crc(0)
    , lut_crc32(256)
    , polynomial_packed_rev(0)
{
    polynomial.push_back(1);

    for (auto i = 0; i < size; i++)
        polynomial.push_back((polynomial_packed >> ((size - 1) - i)) & 1);
    buff_crc.resize(K + size);

    for (auto i = 0; i < (int)sizeof(polynomial_packed) * 8; i++)
    {
        polynomial_packed_rev <<= 1;
        polynomial_packed_rev |= (polynomial_packed >> i) & 1;
    }
    polynomial_packed_rev >>= (sizeof(polynomial_packed) * 8) - size;

    // precompute a lookup table for the v3 implementation of the CRC
    for (auto i = 0; i < 256; i++)
    {
        unsigned crc = i;
        for (unsigned int j = 0; j < 8; j++)
            crc = (crc >> 1) ^ (-int(crc & 1) & polynomial_packed_rev);
        lut_crc32[i] = crc;
    }
}


template <typename B>
std::string CRC<B>::get_name(const std::string& poly_key) const
{
    if (known_polynomials.find(poly_key) != known_polynomials.end())
        return poly_key;
    else
        throw std::invalid_argument("Polynomial not found");
}

template <typename B>
int CRC<B>::get_size(const std::string& poly_key) const
{
    if (known_polynomials.find(poly_key) != known_polynomials.end())
        return std::get<1>(known_polynomials.at(poly_key));
    else
        throw std::invalid_argument("Polynomial not found");
}

template <typename B>
unsigned CRC<B>::get_value(const std::string& poly_key) const
{
    if (known_polynomials.find(poly_key) != known_polynomials.end())
        return std::get<0>(known_polynomials.at(poly_key));
    else
        throw std::invalid_argument("Polynomial not found");
}

template <typename B>
unsigned
CRC<B>::compute_crc_v3(const void* data, const int n_bits)
{
    unsigned crc = 0;
    auto current = (unsigned char*)data;
    auto length = n_bits / 8;
    while (length--)
        crc = (crc >> 8) ^ lut_crc32[(crc & 0xFF) ^ *current++];
    auto rest = n_bits % 8;
    if (rest != 0)
    {
        auto cur = *current;
        cur <<= 8 - rest;
        cur >>= 8 - rest;

        crc ^= cur;
        for (auto j = 0; j < rest; j++)
            crc = (crc >> 1) ^ (-int(crc & 1) & polynomial_packed_rev);
    }
    return crc;
}

template <typename B>
void
CRC<B>::build(const B* U_K1, B* U_K2)
{
    const auto data = (unsigned char*)this->buff_crc.data();
    _pack(U_K1, data, this->K);
    const auto crc = this->compute_crc_v3((void*)data, this->K);
    std::copy(U_K1, U_K1 + this->K, U_K2);
    for (auto i = 0; i < this->size; i++)
        U_K2[this->K + i] = (crc >> i) & 1;
}

template <typename B>
bool
CRC<B>::check(const B* V_K)
{
    _pack(V_K, (unsigned char*)this->buff_crc.data(), this->K + this->size);
    return check_packed(this->buff_crc.data());
}

template <typename B>
bool
CRC<B>::check_packed(const B* V_K)
{
    const auto crc_size = this->size;
    const auto rest = this->K % 8;

    unsigned char* bytes = (unsigned char*)V_K;

    unsigned crc_invalid = 0;

    const auto data = bytes;
    const auto crc = this->compute_crc_v3((void*)data, this->K);

    auto n_bits_crc = crc_size;
    auto current = data + (this->K / 8);

    unsigned crc_ref = 0;
    if (rest)
    {
        auto cur = *current++;
        for (auto j = rest; j < 8 && n_bits_crc > 0; j++)
            crc_ref |= ((cur >> j) & 1) << (crc_size - n_bits_crc--);
    }
    while (n_bits_crc)
    {
        auto cur = *current++;
        for (auto j = 0; j < 8 && n_bits_crc > 0; j++)
            crc_ref |= ((cur >> j) & 1) << (crc_size - n_bits_crc--);
    }
    crc_invalid |= crc ^ crc_ref;
    return !crc_invalid;
}

template<typename B>
void
CRC<B>::extract(const B* V_K1, B* V_K2)
{
    std::copy(V_K1, V_K1 + this->K, V_K2);
}

template class aff3ct::module::CRC<int>;
