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

// K = 64, N = 80
#include "decoders/generated/Decoder_polar_SC_fast_sys_N128_K72_SNR59.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N128_K72_SNR59.hpp"

// K = 64, N = 128
#include "decoders/generated/Decoder_polar_SC_fast_sys_N128_K72_SNR46.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N128_K72_SNR46.hpp"

// K = 64, N = 256
#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K76_SNR33.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N256_K76_SNR33.hpp"

// K = 128, N = 160
#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K138_SNR58.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR58.hpp"

// K = 128, N = 256
#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K138_SNR34.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR34.hpp"

// K = 128, N = 512
#include "decoders/generated/Decoder_polar_SC_fast_sys_N512_K140_SNR29.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N512_K140_SNR29.hpp"

// K = 256, N = 320
#include "decoders/generated/Decoder_polar_SC_fast_sys_N512_K266_SNR50.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N512_K266_SNR50.hpp"

// K = 256, N = 512
#include "decoders/generated/Decoder_polar_SC_fast_sys_N512_K268_SNR31.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N512_K268_SNR31.hpp"

// K = 256, N = 1024
#include "decoders/generated/Decoder_polar_SC_fast_sys_N1024_K266_SNR25.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N1024_K266_SNR25.hpp"

// K = 512, N = 640
#include "decoders/generated/Decoder_polar_SC_fast_sys_N1024_K528_SNR47.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N1024_K528_SNR47.hpp"

// K = 512, N = 1024
#include "decoders/generated/Decoder_polar_SC_fast_sys_N1024_K528_SNR27.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N1024_K528_SNR27.hpp"

// K = 512, N = 2048
#include "decoders/generated/Decoder_polar_SC_fast_sys_N2048_K544_SNR18.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N2048_K544_SNR18.hpp"

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


            if (K == 64 && N == 80)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "8-DVB-S2");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N128_K72_SNR59(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N128_K72_SNR59(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_128_72_59,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 64 && N == 128)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "8-DVB-S2");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N128_K72_SNR46(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N128_K72_SNR46(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_128_72_46,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 64 && N == 256)
            {
                int L = 32;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "12-CDMA2000");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N256_K76_SNR33(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N256_K76_SNR33(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_256_76_33,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 128 && N == 160)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "10-CDMA2000");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N256_K138_SNR58(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR58(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_256_138_58,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 128 && N == 256)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "10-CDMA2000");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N256_K138_SNR34(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR34(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_256_138_34,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 128 && N == 512)
            {
                int L = 32;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "12-CDMA2000");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N512_K140_SNR29(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N512_K140_SNR29(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_512_140_29,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 256 && N == 320)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "10-CDMA2000");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N512_K266_SNR50(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N512_K266_SNR50(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_512_266_50,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 256 && N == 512)
            {
                int L = 32;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "12-CDMA2000");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N512_K268_SNR31(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N512_K268_SNR31(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_512_268_31,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 256 && N == 1024)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "10-CDMA2000");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N1024_K266_SNR25(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N1024_K266_SNR25(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_1024_266_25,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 512 && N == 640)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "16-5G");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N1024_K528_SNR47(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N1024_K528_SNR47(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_1024_528_47,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 512 && N == 1024)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "16-IBM");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N1024_K528_SNR27(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N1024_K528_SNR27(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_1024_528_27,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 512 && N == 2048)
            {
                int L = 32;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "32-GZIP");
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N2048_K544_SNR18(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N2048_K544_SNR18(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_2048_544_18,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else
                throw std::invalid_argument("Unsupported polar code parameters");
        }
};


#endif // POLAR_H

