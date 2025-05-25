// K = 64, N = 80
#include "decoders/generated/Decoder_polar_SC_fast_sys_N80_K64.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N80_K64.hpp"

// K = 64, N = 128
#include "decoders/generated/Decoder_polar_SC_fast_sys_N128_K72_SNR39.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N128_K72_SNR39.hpp"

// K = 64, N = 256
#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K76_SNR25.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N256_K76_SNR25.hpp"

// K = 128, N = 160
#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K138_SNR75.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR75.hpp"

// K = 128, N = 256
#include "decoders/generated/Decoder_polar_SC_fast_sys_N256_K138_SNR30.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR30.hpp"

// K = 128, N = 512
#include "decoders/generated/Decoder_polar_SC_fast_sys_N512_K140_SNR25.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N512_K140_SNR25.hpp"

// K = 256, N = 320
#include "decoders/generated/Decoder_polar_SC_fast_sys_N512_K266_SNR68.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N512_K266_SNR68.hpp"

// K = 256, N = 512
#include "decoders/generated/Decoder_polar_SC_fast_sys_N512_K268_SNR29.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N512_K268_SNR29.hpp"

// K = 256, N = 1024
#include "decoders/generated/Decoder_polar_SC_fast_sys_N1024_K266_SNR23.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N1024_K266_SNR23.hpp"

// K = 512, N = 640
#include "decoders/generated/Decoder_polar_SC_fast_sys_N1024_K528_SNR66.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N1024_K528_SNR66.hpp"

// K = 512, N = 1024
#include "decoders/generated/Decoder_polar_SC_fast_sys_N1024_K528_SNR25.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N1024_K528_SNR25.hpp"

// K = 512, N = 2048
#include "decoders/generated/Decoder_polar_SC_fast_sys_N2048_K536_SNR16.hpp"
#include "decoders/generated/Decoder_polar_SCL_fast_CA_sys_N2048_K536_SNR16.hpp"


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
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0xD5", 8);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N80_K64(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N80_K64(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_80_64,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 64 && N == 128)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0xD5", 8);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N128_K72_SNR39(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N128_K72_SNR39(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_128_72_39,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 64 && N == 256)
            {
                int L = 32;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0xF13", 12);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N256_K76_SNR25(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N256_K76_SNR25(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_256_76_25,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 128 && N == 160)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0x3D9", 10);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N256_K138_SNR75(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR75(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_256_138_75,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 128 && N == 256)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0x3D9", 10);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N256_K138_SNR30(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N256_K138_SNR30(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_256_138_30,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 128 && N == 512)
            {
                int L = 32;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0xF13", 12);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N512_K140_SNR25(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N512_K140_SNR25(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_512_140_25,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 256 && N == 320)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0x3D9", 10);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N512_K266_SNR68(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N512_K266_SNR68(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_512_266_68,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 256 && N == 512)
            {
                int L = 32;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0xF13", 12);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N512_K268_SNR29(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N512_K268_SNR29(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_512_268_29,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 256 && N == 1024)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0x3D9", 10);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N1024_K266_SNR23(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N1024_K266_SNR23(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_1024_266_23,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 512 && N == 640)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0x1023", 16);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N1024_K528_SNR66(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N1024_K528_SNR66(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_1024_528_66,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 512 && N == 1024)
            {
                int L = 16;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0x8005", 16);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N1024_K528_SNR25(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N1024_K528_SNR25(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_1024_528_25,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else if (K == 512 && N == 2048)
            {
                int L = 32;
                aff3ct::module::CRC<int>* crc = new aff3ct::module::CRC<int>(K, "0x864CFB", 24);
                aff3ct::module::Decoder_polar_SC_fast_sys* decoder_SC = new aff3ct::module::Decoder_polar_SC_fast_sys_N2048_K536_SNR16(K + crc->get_size(),N_polar,1);
                aff3ct::module::Decoder_polar_SCL_fast_CA_sys* decoder_CASCL = new aff3ct::module::Decoder_polar_SCL_fast_CA_sys_N2048_K536_SNR16(K + crc->get_size(),N_polar,L,*crc,1);
                return new polar(K + crc->get_size(), N_polar, aff3ct::module::Decoder_polar_SCL_fast_CA_sys_fb_2048_536_16,
                    new aff3ct::module::Decoder_polar_ASCL_fast_CA_sys(K + crc->get_size(), N_polar, *decoder_SC, *decoder_CASCL, *crc), crc);
            }
            else
                throw std::invalid_argument("Unsupported polar code parameters");
        }
};
