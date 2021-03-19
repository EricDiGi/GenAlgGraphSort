/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: testgene.cpp
  Assignment number: Project 3
**************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "graph.hpp"
#include "loader.hpp"
#include "tracker.hpp"
#include "genetic.hpp"

using namespace std;

int main(){
    srand(time(0));
    Load l;
    Map m = l.run();
    int n = 0;
    Genetic g(m);
    cout << "Size: ";
    cin >> n;

    g.initialize(n);
    //cout << g;
    g.main__();
    cout << g;
}