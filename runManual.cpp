/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: runManual.cpp
  Assignment number: Project 3
**************************************************************/
#include <iostream>
#include "component.hpp"

using namespace std;


int main(){
    LoadMap();
    while(1){
        ManualGeneticValues();
        runtime(Genetic_);
        cout << modeTime << " \t";
        cout << GENE << endl;
        if(n<=12){
            runtime(BruteForce_);
            cout << modeTime << " \t";
            cout << BRUTE.back() << endl;
        }
    }
}