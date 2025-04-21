#ifndef POLAR_H
#define POLAR_H

#include "enc_dec.h"
#include <string>
#include <vector>
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

#include "decoders/Decoder_polar_ASCL_fast_CA_sys.hpp"

#include "decoders/generated/Decoder_polar_SC_fast_sys_N8_K4_SNR25.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N64_K32_SNR25.hpp"

#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K64_SNR48.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K68_SNR40.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N128_K64_SNR54.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N128_K68_SNR42.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N512_K128_SNR41.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K128_SNR48.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N1024_K256_SNR36.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N512_K256_SNR44.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N2048_K512_SNR30.hpp"
#include "decoders/generated/Decoder_polar_SC_fast_sys_N1024_K512_SNR38.hpp"



#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N8_K4_SNR25.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N8_K4_SNR26.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N256_K64_SNR40.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N256_K68_SNR40.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N128_K68_SNR42.hpp"

#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K136_SNR73.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N256_K136_SNR73.hpp"


#include "decoders/CRC.hpp"

using intvec = std::vector<int>;
using fltvec = std::vector<float>;


// Class for generating, encoding, and decoding binary low-density parity-check codes
class polar
{
    protected:
        int K; // number of information bits
        int N; // number of codeword bits
        int m; // log_2 of code length
        int N_polar; // polar code length (N = 2^m)
        std::vector<int> X_N_tmp; // temporary storage for codeword bits
        std::vector<int> U_K_crc; // information bits with CRC

        std::vector<float> Y_N; // received LLRs
        std::vector<float> l;            // lambda, LR or LLR
        std::vector<int> s;            // bits, partial sums
        std::vector<int> s_bis;        // bits, partial sums
        const  std::vector<bool> &frozen_bits; // frozen bits
        aff3ct::module::Decoder_polar *decoder; // decoder instance
        aff3ct::module::CRC<int> *crc;
    public:
        // Constructor
        polar(int K, int N, const std::vector<bool> &frozen_bits, aff3ct::module::Decoder_polar *decoder);
        polar(int K, int N, const std::vector<bool> &frozen_bits, aff3ct::module::Decoder_polar *decoder, aff3ct::module::CRC<int> *crc);

        // Destructor
        ~polar();

        void encode(bitvec &info, bitvec &cw);

        int decode(llrvec &llr, bitvec &cw_est, bitvec &info_est);

};

class factory
{
    public:
        // Factory method to create a polar code instance
        static polar* create(int K, int N)
        {
            std::cout << "Creating polar code with K = " << K << " and N = " << N << std::endl;
            int N_polar = (int)std::exp2(std::ceil(std::log2(N)));
            std::cout << "N_polar = " << N_polar << std::endl;
            if (K == 4 && N == 8)
            {
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "4-ITU");
                return new polar(K, N, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_8_4_25,
                    new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N8_K4_SNR25(K,N,2,*crc,1));
            }
            if (K == 4 && N == 7)
            {
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "1-PAR");
                return new polar(K, N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_8_4_26,
                    new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N8_K4_SNR26(K,N_polar,2,*crc,1), crc);
            }
            else if (K == 32 && N == 64)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_64_32_25,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N64_K32_SNR25(K,N,1));
            else if (K == 64 && N == 256)
            {
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "4-ITU");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N256_K68_SNR40(K + crc->get_size(),N,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N256_K68_SNR40(K + crc->get_size(),N,4,*crc,1);
                return new polar(K + crc->get_size(), N, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_256_68_40,
                                  new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            // else if (K == 64 && N == 80)
            // {
            //     aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "4-ITU");
            //     aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N128_K68_SNR42(K + crc->get_size(),N,1);
            //     aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N128_K68_SNR42(K + crc->get_size(),N,4,*crc,1);
            //     return new polar(K + crc->get_size(), N, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_128_68_42,
            //                       new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N, *decoder_SC, *decoder_CASCL, *crc), crc);
            // }
            else if (K == 64 && N == 80)
            {
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "4-ITU");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N128_K68_SNR42(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N128_K68_SNR42(K + crc->get_size(),N_polar,4,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_128_68_42,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }


            else if (K == 68 && N == 256)
            {
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "4-ITU");
                return new polar(K, N, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_256_68_40,
                                new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N256_K68_SNR40(K,N,4,*crc,1));
            }
            else if (K == 64 && N == 128)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_128_64_54,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N128_K64_SNR54(K,N,1));
            else if (K == 128 && N == 512)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_512_128_41,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N512_K128_SNR41(K,N,1));
            else if (K == 128 && N == 160)
            {
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "8-DVB-S2");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N256_K136_SNR73(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N256_K136_SNR73(K + crc->get_size(),N_polar,4,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_256_136_73,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 128 && N == 256)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_256_128_48,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N256_K128_SNR48(K,N,1));
            else if (K == 256 && N == 1024)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_1024_256_36,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N1024_K256_SNR36(K,N,1));
            else if (K == 256 && N == 512)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_512_256_44,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N512_K256_SNR44(K,N,1));
            else if (K == 512 && N == 2048)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_2048_512_30,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N2048_K512_SNR30(K,N,1));
            else if (K == 512 && N == 1024)
                return new polar(K, N, aff3ct::module::Decoder_polar_SC_fast_sys_fb_1024_512_38,
                                  new aff3ct::module::Decoder_polar_SC_fast_sys_N1024_K512_SNR38(K,N,1));
                        else
                throw std::invalid_argument("Unsupported polar code parameters");
        }
};


#endif // POLAR_H

