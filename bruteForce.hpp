#ifndef bruteForce_HPP
#define bruteForce_HPP

#include <vector>
#include "graph.hpp"
#include "tracker.hpp"

class Brute{
    private:
        Map map;
        int n;
        Path min(std::vector<Path> trails);
        //Path force(Path &p, int loc, int dest, int count);
    public:
        void chart(Map m);
        Path Combo(int n);
        //Path force(int n);
};

#endif