#ifndef bruteForce_HPP
#define bruteForce_HPP

#include <vector>
#include "graph.hpp"
#include "tracker.hpp"

class Brute{
    private:
        Map map;
        int n;
        //Path force(Path &p, int loc, int dest, int count);
        Path min(std::vector<Path> trails);
    public:
        void chart(Map m);
        //Path force(int n);
        Path Combo(int n);
};

#endif