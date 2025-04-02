CXX = g++
CXXFLAGS = -Wall -O3 -std=c++17
LDFLAGS =
SOURCES = enc_dec.cpp run_test.cpp polar.cpp test.cpp argmin.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = run_test test

all: $(EXECUTABLE)

run_test: enc_dec.o run_test.o argmin.o polar.o
	$(CXX) $(LDFLAGS) -o $@ $^

test: test.o ldpc.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	rm -f $(OBJECTS) $(EXECUTABLE)
