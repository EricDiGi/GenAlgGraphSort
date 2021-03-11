CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS: .hpp=.o)

all: graph

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o Hash core main

graph: $(OBJECTS) testGraph.cpp graph.hpp graph.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

load: $(OBJECTS) testLoad.cpp loader.hpp loader.cpp graph.hpp graph.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

path: $(OBJECTS) testpath.cpp tracker.hpp loader.hpp loader.cpp graph.hpp graph.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

brute: $(OBJECTS) testbrute.cpp bruteForce.hpp bruteForce.cpp tracker.hpp loader.hpp loader.cpp graph.hpp graph.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^