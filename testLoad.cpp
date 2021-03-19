/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: testLoad.cpp
  Assignment number: Project 3
**************************************************************/
#include <iostream>
#include "graph.hpp"
#include "loader.hpp"

using namespace std;

int main(){
    Load l;
    Map m = l.run();
    cout << m;
}