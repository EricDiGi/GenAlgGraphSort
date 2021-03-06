CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS: .hpp=.o)

all: manual auto

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

gene: $(OBJECTS) testgene.cpp genetic.hpp genetic.cpp tracker.hpp loader.hpp loader.cpp graph.hpp graph.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

manual: $(OBJECTS) runManual.cpp component.hpp bruteForce.hpp bruteForce.cpp genetic.hpp genetic.cpp tracker.hpp loader.hpp loader.cpp graph.hpp graph.cpp TIME.hpp heap.hpp heap.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

auto: $(OBJECTS) runAuto.cpp component.hpp bruteForce.hpp bruteForce.cpp genetic.hpp genetic.cpp tracker.hpp loader.hpp loader.cpp graph.hpp graph.cpp TIME.hpp statistics.hpp heap.hpp heap.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

time: $(OBJECTS) testTimer.cpp TIME.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^

hopper: $(OBJECTS) runHeap.cpp heap.cpp heap.hpp statistics.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^