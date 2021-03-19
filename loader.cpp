#include <iostream>
#include <fstream>
#include "loader.hpp"

using namespace std;

/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: loader.cpp
  Assignment number: Project 3
**************************************************************/

Map Load::run(){
    X = Y = 0;
    double dat;

    fstream file;
    file.open(filename.c_str());
    while(!file.eof()){
        file >> dat;
        putNext(dat);
    }
    file.close();
    return this->graph;
}

void Load::putNext(double d){
    if(X == Y)
        X++;
    if(X%20 == 0){
        Y++; X=0;
    }
    graph.put(X,Y,d);
    X++;
}