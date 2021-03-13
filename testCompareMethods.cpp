#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "TIME.hpp"
#include "graph.hpp"
#include "loader.hpp"
#include "tracker.hpp"
#include "genetic.hpp"
#include "bruteForce.hpp"

using namespace std;

int n; int p; int g; double M;
Map m;


void runBruteForce(){
    Brute b;
    b.chart(m);
    Path cmb = b.Combo(n); //Combinatorial Brute Force
    cout << cmb;
}

void runGenetic(){
    Genetic G(m,g,M);
    G.initialize(n,p);
    //G.final(cmb);
    cout << G.Deep();
}

int main(){
    srand(time(0));
    Load l;
    m = l.run();

    while(1){
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
        Timer(runBruteForce);
        Timer(runGenetic);
/*
        Brute b;
        b.chart(m);
        Path cmb = b.Combo(n); //Combinatorial Brute Force
        cout << cmb;

        Genetic G(m,g,M);
        G.initialize(n,p);
        G.final(cmb);
        cout << G.Deep();*/
    }
}