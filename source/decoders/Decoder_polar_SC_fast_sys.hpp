/*!
 * \file
 * \brief Class module::Decoder_polar_SC_fast_sys.
 */
 #ifndef DECODER_POLAR_SC_FAST_SYS_
 #define DECODER_POLAR_SC_FAST_SYS_

 #include <vector>
 #include <cmath>

 namespace aff3ct
 {
 namespace module
 {

 class Decoder_polar_SC_fast_sys
 {

 protected:
     const int                m;            // graph depth
           std::vector<float> l;            // lambda, LR or LLR
           std::vector<int>  s;              // bits, partial sums
           std::vector<int>  s_bis;          // bits, partial sums
     const  std::vector<bool> &frozen_bits; // frozen bits

 public:
    Decoder_polar_SC_fast_sys(const int& K, const int& N, const std::vector<bool>& frozen_bits, const int n_frames = 1):
        m((int)std::log2(N)),
        l(N),
        s(N),
        s_bis(N),
        frozen_bits(frozen_bits)
    {
        // Constructor implementation
    };
    ~Decoder_polar_SC_fast_sys() = default;

    void decode()
    {
        // Call the decode function
        this->_decode();
    }

 protected:

             void _load          (const float *Y_N){}
     virtual void _decode        (){}
             void _store         (int *V_K){}

 };
 }
 }

//  #include "Decoder_polar_SC_fast_sys.hxx"

 #endif /* DECODER_POLAR_SC_FAST_SYS_ */
