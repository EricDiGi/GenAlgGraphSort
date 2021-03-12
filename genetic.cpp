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

Path Genetic::Deep(){
    vector<Path> MAX;
    for(int i = 0; i < geneLen; i++)
        MAX.push_back(main__());
    POP = MAX;
    return main__();
}

Path Genetic::main__(){
    Path last = mostFit();
    int fitcount = 0;
    int GenCNT = this->Gens;
    while(GenCNT > 0){
        select();
        if(rand()%1000 <= 1000*(1.0-this->mutProb))
            crossover();
        if(rand()%1000 <= 1000*this->mutProb)
            mutate();
        putFittest();
        if(mostFit() == last)
            fitcount++;
        else
            fitcount = 0;
        last = mostFit();
        GenCNT--;
    }
    //cout << (BEST || last) << "\t";
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
    initialize(n, 3*n);
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
    if(rand()%this->geneLen <= this->geneLen*0.9)
        next = POP.at(rand()%((int)POP.size()));
    else
        next = min2();
}

void Genetic::crossover(){
    int R = (rand()%(this->geneLen-1));
    //cout << R << endl;
    for(int i = 1; i < R; i++){
        swap(best.path.at(i),next.path.at(i));
    }
    next.setPath(map);
    best.setPath(map);
}

void Genetic::mutate(){
    int R = (rand()%(this->geneLen-1));
    int P = 1+(rand()%(this->geneLen-1));
    int S = 1+(P+R)%(geneLen-1);
    if(P == 0)
        P+=1;
    if(R == 0)
        R+=1;
    //swap(best.path.at(P), best.path.at(S));
    best.shuffle();
    swap(next.path.at(R), next.path.at(P));
   // next.shuffle();
    best.setPath(map);
    next.setPath(map);
}

Path Genetic::bestChild(){
    Path m = (best < next) ? best : next;
    return m;
}

void Genetic::putFittest(){
    Path ABS = bestChild();
    if(!hasRepeats(ABS) && this->POP.at(worst()) > ABS)
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