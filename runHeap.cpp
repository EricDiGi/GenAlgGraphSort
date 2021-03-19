/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: runHeap.cpp
  Assignment number: Project 3

  AIDS IN FINDING BEST GENETIC SOLUTION
**************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include "heap.hpp"
#include "statistics.hpp"

using namespace std;

int main(){
    Heap h;

    fstream file;
    file.open("geneData.txt", ios::in);
    while(!file.eof()){
        Stats s;
        int n;
        vector<double> entry;
        file >> n;
        double v;
        for(int i = 0; i < 11; i++){
            file >> v;
            entry.push_back(v);
        }
        s = Stats(n,0,0,0,entry,0,0);
        h.push(s);
    }
    file.close();
    h.pull();
    cout << h.top();
}