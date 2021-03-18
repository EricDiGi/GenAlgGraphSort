#include <iostream>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include "graph.hpp"
#include "tracker.hpp"
#include "genetic.hpp"

using namespace std;

Genetic::Genetic(){
    srand(time(0));
}

Genetic::Genetic(Map m, int g, double M){
    srand(time(0));
    this->map = m;
    this->Gens = g;
    this->mutProb = M;
}

void Genetic::final(Path p){
    this->BEST = p;
}

//Does second iteration using elites from each run
Path Genetic::Deep(){
    vector<Path> MAX;
    for(int i = 0; i < geneLen; i++)
        MAX.push_back(main__());
    POP = MAX;
    return main__();
}

Path Genetic::main__(){
    Path last = mostFit();
    int GenCNT = this->Gens;
    while(GenCNT > 0){
        select();
        if(rand()%11 <= 10*(1.0-this->mutProb))
            crossover();
        if(rand()%11 <= 10*this->mutProb)
            mutate();
        putFittest();
        last = mostFit();
        GenCNT--;
    }
    return mostFit();
}

void Genetic::initialize(int n, int p){ //n num cities p num pop
    this->geneLen = n;
    vector<int> primary;
    for(int i = 1; i < n; i++)
        primary.push_back(i);
    do{
        vector<int> fix(n+1);
        for(int i = 1; i < n; i++){
            fix.at(i) = primary.at(i-1);
        }
        this->POP.push_back(Path(map,fix));
        p--;
    }while(next_permutation(primary.begin(),primary.end()) && p > 0);
}

void Genetic::initialize(int n){
    initialize(n, 2*n);
}

int Genetic::worst(){
    int loc = 0;
    Path max = POP.at(0);
    for(int i = 0; i < (int)POP.size(); i++){
        if(max < POP.at(i)){
            loc = i;
            max = POP.at(i);
        }
    }
    return loc;
}

Path Genetic::min(){
    Path min = POP.at(0);
    for(int i = 0; i < (int)POP.size(); i++)
        if(!hasRepeats(POP.at(i)))
            min = (POP.at(i) < min) ? POP.at(i) : min;
    return min;
}

Path Genetic::min2(){
    Path MIN = min();
    Path min = POP.at(0);
    for(int i = 0; i < (int)POP.size(); i++){
        if((POP.at(i) < min && POP.at(i) != MIN) || (min == MIN)){
            if(!hasRepeats(POP.at(i)))
                min = POP.at(i);
        }
    }
    return min;
}

Path Genetic::mostFit(){
    return min();
}

void Genetic::select(){
    best = min();
    next = min2();
}

//Subject to generate repeats
void Genetic::crossover(){
    int R = (rand()%(this->geneLen-1));
    R += (R == 0) ? 1:0;
    for(int i = 1; i < R; i++)
        swap(best.path.at(i),next.path.at(i));
    next.setPath(map);
    best.setPath(map);
}

//shuffle is found in tracker.hpp
void Genetic::mutate(){
    next.shuffle();
    best.shuffle();
    best.setPath(map);
    next.setPath(map);
}

//best child should have no repeats
Path Genetic::bestChild(){
    Path m = Path();
    if(!hasRepeats(best) && !hasRepeats(next))
        m = (best <= next) ? best : next;
    return m;
}

//Replace worst case with best case
void Genetic::putFittest(){
    Path ABS = bestChild();
    if(ABS.getCost() == 0)
        return;
    if(this->POP.at(worst()) > ABS)
        this->POP.at(worst()) = ABS;
}

bool Genetic::hasRepeats(Path &p){
    vector<int> S = p.path;
    sort(S.begin(),S.end());
    int trans = 0;
    for(int i = 0; i < (int)S.size()-1; i++){
        if(S.at(i) != S.at(i+1))
            trans++;
    }
    return trans < geneLen-1;
}