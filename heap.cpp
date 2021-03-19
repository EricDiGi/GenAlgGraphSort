/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: heap.hpp
  Assignment number: Project 3 (extra bits)

 HEAP NOT REQUISITE OF THIS PROJECT, JUST HELPED IN IDENTIFYING BEST SOLUTION
***************************************************************/

#include <iostream>
#include <vector>
#include "statistics.hpp"
#include "heap.hpp"

using namespace std;

Heap::Heap(){
    this->summit.push_back(Stats());
    this->SIZE = 0;
}

Heap::~Heap(){}

void Heap::push(Stats c){
    this->summit.push_back(c);
    this->SIZE++;
    percolate(this->SIZE);
}
Stats Heap::top(){
    return this->summit.at(0);
}

Stats Heap::pull(){
    if(this->summit.size() < 0){
        return Stats();
    }
    Stats s = this->summit[0];
    this->summit.erase(this->summit.begin());
    this->SIZE--;
    percolate(this->SIZE);
    return s;
}

void Heap::percolate(int i){
    while(i/2 > 0){
        if(doSwap(i,i/2))
            swap(this->summit.at(i),this->summit.at(i/2));
        i = i/2;
    }
}
bool Heap::doSwap(int P, int c){
    vector<double> PARENT = this->summit.at(P).runs;
    vector<double> CHILD = this->summit.at(c).runs;
    int cntP = 0; int cntC = 0;
    for(int i = 0; i < (int)PARENT.size(); i++){
        cntP += (PARENT.at(i) < CHILD.at(i)) ? 1 : 0;
        cntC += (PARENT.at(i) > CHILD.at(i)) ? 1 : 0;
    }
    return cntP > cntC;
}

int Heap::size(){
    return (int)this->summit.size();
}

bool Heap::isEmpty(){
    return this->summit.size() == 0;
}