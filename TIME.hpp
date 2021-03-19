/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: TIME.hpp
  Assignment number: Project 3
**************************************************************/
#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <ctime>

double Timer(void func()){
    clock_t t;
    t = clock();
    func();
    t = clock() - t;
    double T = t/(double)CLOCKS_PER_SEC;
    return T;
}

#endif