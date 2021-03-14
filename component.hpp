#ifndef component_HPP
#define component_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include "TIME.hpp"
#include "graph.hpp"
#include "loader.hpp"
#include "tracker.hpp"
#include "genetic.hpp"
#include "bruteForce.hpp"
#include "statistics.hpp"

using namespace std;

Path GENE;
Map MAP;
int n; int p; int g; double M;
double modeTime = 0.0;

double Tcost = 0.0;
double Tdev = 0.0;

bool STOP_AUTO = false;

const int MAX_GEN_ITER = 6;
const int MAX_MUTE_ITER = 9;
const int MAX_POP_ITER = 7;
const int MAX_PATH = 10;

int Generations[] = {250,500,1000,2000,4000,5000};
double PopAlter[] = {0.5,0.75,1.0,1.5,2.0,3.0,3.5};
double Mute[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.9, 1.0};

vector<Stats> BASE;
vector<Path> BRUTE;
vector<Stats> CUMMULATIVE;

void LoadMap(){
    Load l;
    MAP = l.run();
}

void setN(int num){
    n = num;
}

void BruteForce_(){
    modeTime = 0;
    srand(time(0));
    Brute b;
    b.chart(MAP);
    Path cmb = b.Combo(n); //Combinatorial Brute Force
    BRUTE.push_back(cmb);
}

void ManualGeneticValues(){
    n =  p = g = M = 0;
    while(n < 10 || n > 20){
        cout << "Cities: ";
        cin >> n;
    }
    while(p < 3){
        cout << "Population: ";
        cin >> p;
    }
    while(g < 1){
        cout << "Generations: ";
        cin >> g;
    }
    double M = 0;
    while(M < 0.100 || M > 1.1){
        cout << "Percent Chance to mutate: ";
        cin >> M;
    }
}


void Genetic_(){
    modeTime = 0;
    srand(time(0));
    Genetic G(MAP,g,M);
    G.initialize(n,p);
    Path gen = G.Deep();
    GENE = gen;
}

void runtime(void func()){
    double t = Timer(func);
    modeTime = t;
    if(t/60 > 5)
        STOP_AUTO = true;
    //cout << GENE << t << "\n";
}

void runFullAuto(){
    /*cout << "BRUTE FORCE\n";
    for(int d = 0; d < MAX_PATH || STOP_AUTO; d++){
        n = d+MAX_PATH;
        runtime(BruteForce_);
        Stats s = Stats(n,0,0,0.0,modeTime, 0.0);
        cout << s;
        cout << ((double)d/(double)MAX_PATH)*100 << "% complete\n";
        BASE.push_back(s);
    }*/
    cout << "GENETIC ALGORITHM\n";
    for(int a = 0; a < MAX_MUTE_ITER || STOP_AUTO; a++){
        M = Mute[a];
        for(int b = 0; b < MAX_GEN_ITER || STOP_AUTO; b++){
            g = Generations[b];
            for(int c = 0; c < MAX_POP_ITER || STOP_AUTO; c++){
                Tcost = 0;
                Tdev = 0;
                for(int d = 0; d < MAX_PATH || STOP_AUTO; d++){
                    n = d+MAX_PATH;
                    p = n*PopAlter[c];
                    runtime(Genetic_);
                    Tcost += modeTime;
                    Tdev += fabs(GENE.getCost()-BRUTE.at(d).getCost())/BRUTE.at(d).getCost();
                }
                double acost = Tcost/(double)MAX_PATH;
                double adev = Tdev/(double)MAX_PATH;
                Stats s = Stats(n,p,g,M,acost, adev);
                CUMMULATIVE.push_back(s);
            }
        }
    }
    cout << "Best Form:\n" << Best(CUMMULATIVE);
}


#endif