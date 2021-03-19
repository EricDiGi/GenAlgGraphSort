/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: heap.hpp
  Assignment number: Project 3 (extra bits)

 HEAP NOT REQUISITE OF THIS PROJECT, JUST HELPED IN IDENTIFYING BEST SOLUTION
***************************************************************/

#ifndef heap_HPP
#define heap_HPP

#include <iostream>
#include "statistics.hpp"
#include <vector>


class Heap{
    private:
        std::vector<Stats> summit;
        int SIZE;
        bool doSwap(int P, int c);
    public:
        Heap();
        ~Heap();
        void push(Stats c);
        Stats pull();
        Stats top();
        void percolate(int i);
        int size();
        bool isEmpty();
};

#endif
