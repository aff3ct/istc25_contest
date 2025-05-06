CXX = g++
CXXFLAGS = -Wall -O3 -std=c++17
LDFLAGS =
SOURCES = enc_dec.cpp run_test.cpp polar.cpp argmin.cpp decoders/CRC.cpp Tools/Code/Polar/Pattern_polar_parser.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = run_test

all: $(EXECUTABLE)

run_test: enc_dec.o run_test.o argmin.o polar.o decoders/CRC.o Tools/Code/Polar/Pattern_polar_parser.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	rm -f $(OBJECTS) $(EXECUTABLE)
