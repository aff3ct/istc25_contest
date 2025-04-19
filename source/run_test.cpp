#include <iostream>
#include <sys/resource.h>
#include <chrono>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
#include <random>
#include <array>
#include <fstream>
#include <sstream>
#include "enc_dec.h"
#include "ldpc.h"
#include "polar.h"
#include "argmin.h"

const int N_TEST = 12;

// Define structure for each test point, specifying code parameters and test conditions
struct test_point
{
  int k; // Number of information bits
  int n; // Number of codeword bits
  float esno;  // Array of SNR values for testing
  int n_block; // Array of block sizes for testing
  int opt_avg; // Flag to optimize average (versus max) decoding latency
};

// Define set of tests
test_point contest[N_TEST] =
{
  {4,8,8.0,2000,0},   // k=64 R=1/4
  {32,64,3.2,10000000,0},   // k=64 R=1/4
  // {64,256,1.0,2000,0},   // k=64 R=1/4
  // {128,512,0.1,2000,0},  // k=128 R=1/4
  {256,1024,0.1,2000,0}, // k=256 R=1/4
  {512,2048,0.1,2000,0}, // k=512 R=1/4
  {64,128,1.0,2000,0},   // k=64 R=1/2
  {128,256,1.0,2000,0},  // k=128 R=1/2
  {256,512,1.0,2000,0},  // k=256 R=1/2
  {512,1024,1.0,2000,0}, // k=512 R=1/2
  {64,80,3.0,2000,0},    // k=64 R=4/5
  {128,160,3.0,2000,0},  // k=128 R=4/5
  {256,320,3.0,2000,0},  // k=256 R=4/5
  {512,640,3.0,2000,0}   // k=512 R=4/5
};

// Global defaults
float default_esno = 0.0;
int default_nblock = 0;

// Define class to collect statistics
template <typename T,int N> class stats
{
  protected:
    std::vector<std::array<T, N>> data; // Store data

  public:
    // clear
    void clear() { data.clear(); }

    // collect stats
    void add_sample(const std::array<T, N>& sample) { data.push_back(sample); }

    // return number of samples
    int n_sample() { return data.size(); }

    // return sum
    std::array<int, N> sum()
    {
      std::array<int, N> sum = {0};
      for (const auto& sample : data) {
          for (int i = 0; i < N; ++i) {
              sum[i] += sample[i];
          }
      }
      return sum;
    }

    // stream output
    void print(std::ostream* sout)
    {
      for (const auto& sample : data) {
          for (int i = 0; i < N; ++i) {
              *sout << sample[i] << " ";
          }
          *sout << std::endl;
      }
    }
};

// Enumerate statistics to collect
enum dec_stat : int
{
  BLK = 1,
  BIT = 2,
  ENCT = 3,
  DECT = 4
};

// Setup for decoder stats
class decoder_stats : public stats<int,4>
{
  public:
    typedef std::array<int, 4> statvec;
    void update(int blk, int bit, int enc, int dec) {
        statvec dummy = {blk, bit, enc, dec};
        stats<int, 4>::add_sample(dummy);
    }
    //std::vector<std::array<int, 4>> get_data() const { return data; }
};

// Simulate BPSK transmission over an AWGN channel
void channel(const bitvec& cw, float esno, fltvec& llr_out) {
    llr_out.resize(cw.size());
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::normal_distribution<float> distribution(4*esno, std::sqrt(8*esno));

    for (size_t i = 0; i < cw.size(); ++i) {
        // BPSK modulation: 0 -> +1, 1 -> -1
        float modulated = (cw[i] == 0) ? 1.0f : -1.0f;
        // Add Gaussian noise
        llr_out[i] = modulated * distribution(generator);
    }
}

// Run all the tests in one round
void run_test(int k, int n, float esno, int n_block, int opt_avg, decoder_stats &stats)
{
  // Allocate variables
  bitvec info(k);
  bitvec cw(n);
  fltvec float_llr(n);
  llrvec llr(n);
  bitvec cw_est(n);
  bitvec info_est(n);

  // Setup binary RNG
  std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> distribution(0, 1);

  // Construct encoder-decoder
  enc_dec entry;

  // Init encoder and decoder for entry
  if (entry.init(k,n,opt_avg) != 0) {
    // This submission does not handle this code
    std::cout << "Handle exception" << std::endl;
  }

  // Setup
  stats.clear();
  auto blk_err = 0;
  // Run tests
  for (int i = 0; i < n_block; ++i)
  {
    // Generate random binary message of length test.k
    for (int j = 0; j < k; ++j) {
        // info[j] = distribution(generator); // Random binary message
        info[j] = 1; // AZCW
        //std::cout << info[j] << " ";
    }
    //std::cout << std::endl;

    // Encode message
    auto enc_start = std::chrono::high_resolution_clock::now();
    entry.encode(info, cw);
    auto enc_time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - enc_start).count();

    // Transmit message
    channel(cw, esno, float_llr);

    // Convert int llr format
    for (int j = 0; j < n; ++j) llr[j] = entry.llr2int(float_llr[j]);

    // Decode message
    auto dec_start = std::chrono::high_resolution_clock::now();
    int detect = entry.decode(llr, cw_est, info_est);
    auto dec_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - dec_start).count();

    // TODO remove
    for (auto i = 0; i < n; i++)
        cw_est[i] = (cw_est[i] == 0) ? 0 : 1;
    for (auto i = 0; i < k; i++)
        info_est[i] = (info_est[i] == 0) ? 0 : 1;

    // std::cout << "Decoded codeword: ";
    // for (auto i = 0; i < cw_est.size(); i++) {
    //     std::cout << cw_est[i] << " ";
    // }
    // std::cout << std::endl;

    // Count number of bit errors
    int bit_err = 0;
    for (int j = 0; j < k; ++j) {
        //std::cout << info_est[j] << " ";
        if (info[j] != info_est[j]) {
            ++bit_err;
        }
    }

    if (i % 1000 == 0) {
      std::cout << "\r" << "Processing Block " << i + 1 << " of " << n_block << std::flush;
    }

    if (bit_err > 0) {
      ++blk_err;
    }

    // Update statistics
    stats.update(1 - detect, bit_err, enc_time, dec_time);
    }

    // Ensure the final line ends cleanly after all blocks are processed
    std::cout << "\r" << "Processing Block " << n_block << " of " << n_block << " - Completed" << std::endl;
  std::cout << "blk_err = " << blk_err << std::endl;
}

// Run all the tests in one round
void run_test_number(int t, decoder_stats &stats)
{
  // Allocate variables
  test_point &test = contest[t];
  bitvec info(test.k);
  bitvec cw(test.n);
  fltvec float_llr(test.n);
  llrvec llr(test.n);
  bitvec cw_est(test.n);
  bitvec info_est(test.n);

  // Setup binary RNG
  std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> distribution(0, 1);

  // Construct encoder-decoder
  enc_dec entry;

  // Init encoder and decoder for entry
  if (entry.init(test.k,test.n,test.opt_avg) != 0) {
    // This submission does not handle this code
    std::cout << "Handle exception" << std::endl;
  }

  // Setup
  stats.clear();
  float esno = test.esno;
  int n_block = test.n_block;
  if (default_esno > 0.0) esno = default_esno;
  if (default_nblock > 0) n_block = default_nblock;

  run_test(test.k, test.n, esno, n_block, test.opt_avg, stats);
}


void run_single_test(int test_number) {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    decoder_stats run_stats;

    // Run the specified test and output results
    test_point &test = contest[test_number];
    run_test(test.k, test.n, test.esno, test.n_block, test.opt_avg, run_stats);
    int n_sample = run_stats.n_sample();
    auto sum = run_stats.sum();
    std::array<float, 4> mean;
    for (int i = 0; i < 4; ++i) {
        mean[i] = ((float)sum[i]) / n_sample;
    }
    //std::cout << n_sample << std::endl;
    std::cout << "Test " << test_number << ": "
              << "Block: " << sum[0] << "/" << n_sample << " = " << mean[0] << ", "
              << "Info Bit Errors: " << sum[1]  << "/" << n_sample*contest[test_number].k << " = " << contest[test_number].k*mean[1] << ", "
              << "Encoding Time (ns): " << sum[2]  << "/" << n_sample << " = " << mean[2] << ", "
              << "Decoding Time (\xC2\xB5s): " << sum[3]  << "/" << n_sample << " = " << mean[3] << ", " << std::endl;
}

void run_test_file(std::string filename, std::string output_filename) {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    decoder_stats run_stats;

    // Open test parameter file using filename
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Setup output
    std::ostream* outputStream;
    std::ofstream fileStream;
    fileStream.open(output_filename);
    if (fileStream.is_open()) {
      outputStream = &fileStream;
    }
    else {
      outputStream = &std::cout;
    }

    // Start line by line file read until no more lines
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int k, n, n_block, opt_avg;
        float esno;
        std::string crc_string;

        // For each line, read 4 parameters: int k, int n, float esno, int n_block
        if (!(iss >> k >> n >> esno >> n_block >> opt_avg)) {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }

        // Run test with given parameters
        run_test(k, n, esno, n_block, opt_avg, run_stats);

        // Process results
        int n_sample = run_stats.n_sample();
        auto sum = run_stats.sum();
        std::array<float, 4> mean;
        for (int i = 0; i < 4; ++i) {
            mean[i] = ((float)sum[i]) / n_sample;
        }

        // Report results
        *outputStream << "Test with parameters (k=" << k << ", n=" << n << ", esno=" << esno << ", n_block=" << n_block << "): "
                  << "Block: " << sum[0] << "/" << n_sample << " = " << mean[0] << ", "
                  << "Info Bit Errors: " << sum[1]  << "/" << n_sample*k << " = " << k*mean[1] << ", "
                  << "Encoding Time (ns): " << sum[2]  << "/" << n_sample << " = " << mean[2] << ", "
                  << "Decoding Time (\xC2\xB5s): " << sum[3]  << "/" << n_sample << " = " << mean[3] << ", " << std::endl;

        // Write stats
        if (!output_filename.empty()) {
          std::string suffix = std::to_string(k) + "_" + std::to_string(n) + "_" + std::to_string(n_block);
          std::ofstream statStream(output_filename + suffix);
          run_stats.print(&statStream);
        }
    }
    file.close();
}

// Setup option for argmin parsing
OptionSpec options[] = {
    {"-h", "--help",   false, "Show this help message"},
    {"-t", "--test",  true,  "Choose the test or use 'all'"},
    {"-s", "--esno",  true,  "Use this Es/N0"},
    {"-m", "--blocks",  true,  "Run this number of blocks"},
    {"-f", "--file",  true,  "Run tests as described in file"},
    {"-o", "--output",  true,  "Write output to a file with this filename"},
    {nullptr, nullptr, false, nullptr} // sentinel to mark end
};

int main(int argc, char* argv[])
{
    // Parse options
    int argmin_result;
    std::map<std::string,std::string> parsedOptions;
    argmin_result = argmin(options, argc, argv, parsedOptions);
    switch (argmin_result) {
      case 1:
        return 1;
      case 2:
        return 0;
    }

    // Declare test_file variable
    std::string output_file;
    std::string test_file;

    // Handle output file argument
    auto iter = parsedOptions.find("output");
    if (iter != parsedOptions.end()) {
        output_file = iter->second;
        std::cout << "Output file = " << output_file << std::endl;
    }
    // Handle input file argument
    iter = parsedOptions.find("file");
    if (iter != parsedOptions.end()) {
        test_file = iter->second;
        std::cout << "Input file = " << test_file << std::endl;
        run_test_file(test_file,output_file);
    }
    // Handle EsN0 and blocks parameters
    iter = parsedOptions.find("esno");
    if (iter != parsedOptions.end()) {
        default_esno = std::stof(iter->second);
        std::cout << "EsN0 = " << default_esno << std::endl;
    }
    iter = parsedOptions.find("blocks");
    if (iter != parsedOptions.end()) {
        default_nblock = std::stoi(iter->second);
        std::cout << "n_block = " << default_nblock << std::endl;
    }
    // Handle test argument
    iter = parsedOptions.find("test");
    if (iter != parsedOptions.end()) {
        if (iter->second == "all") {
            for (int i = 0; i < N_TEST; ++i) {
                run_single_test(i);
            }
        } else {
            int test_number = std::stoi(iter->second);
            if (test_number >= 0 && test_number < N_TEST) {
                run_single_test(test_number);
            } else {
                std::cerr << "Invalid test number: " << test_number << std::endl;
            }
        }
    }

    // Success
    return 0;
}
