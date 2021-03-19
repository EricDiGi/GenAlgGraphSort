/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: testbrute.cpp
  Assignment number: Project 3
**************************************************************/

#include <iostream>
#include "graph.hpp"
#include "loader.hpp"
#include "bruteForce.hpp"

using namespace std;

int main(){
    Load l;
    Map m = l.run();
    Brute b;
    b.chart(m);
    int n = 0;
    while(1){
        cout << "Size: ";
        cin >> n;
        cout << b.Combo(n);
    }
}

/**************************************
Run to get all brute forced values.
**************************************/
/*
void write(int i,double t){
    fstream file;
    file.open("bruteData.txt", ios::app);
    file << i << "\t" << t << "\t" << BRUTE.back().getCost() << endl;
    file.close();
}

int main(){
    
    LoadMap();
    for(int i = 10; i <= 20; i++){
        setN(i);
        double t = Timer(BruteForce_);
        cout << i << " ";
        write(i,t);
    }
}
*/