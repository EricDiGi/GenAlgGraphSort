/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: loader.hpp
  Assignment number: Project 3
**************************************************************/
#ifndef loader_HPP
#define loader_HPP

#include <string>
#include "graph.hpp"

class Load{
    private:
        const std::string filename = "distances.txt";
        int X, Y;
        Map graph;
        void putNext(double d);
    public:
        Map run();
};

#endif