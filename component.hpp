#ifndef component_HPP
#define component_HPP

#include <iostream>
#include <fstream>
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

bool STOP_AUTO = false; //For really big runs

const int MAX_GEN_ITER = 5;
const int MAX_MUTE_ITER = 9;
const int MAX_POP_ITER = 7;
const int MAX_PATH = 10;

//WILL OUTPUT 378 COMBINATIONS
int Generations[] = {250,500,1000,2000,4000};
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
}



void write(Stats s){
    fstream file;
    file.open("geneData.txt", ios::app);
    file << s << endl;
    file.close();
}

void unloadFileContents(){
    fstream file;
    file.open("geneData.txt", ios::trunc);
    if(file.is_open()){
        file.close();
    }
}

/********************************************
Run all listed variants and record data
********************************************/
void runFullAuto(){
    /* EST RUN TIME 3 Months*/
    /*cout << "BRUTE FORCE\n";
    for(int d = 0; d < MAX_PATH || STOP_AUTO; d++){
        n = d+MAX_PATH;
        runtime(BruteForce_);
        Stats s = Stats(n,0,0,0.0,modeTime, 0.0);
        cout << s;
        cout << ((double)d/(double)MAX_PATH)*100 << "% complete\n";
        BASE.push_back(s);
    }*/
    unloadFileContents();
    int entry = 0;
    double Tmax; double Ttime;
    cout << "GENETIC ALGORITHM\n";
    for(int a = 0; a < MAX_MUTE_ITER || STOP_AUTO; a++){
        M = Mute[a];
        for(int b = 0; b < MAX_GEN_ITER || STOP_AUTO; b++){
            g = Generations[b];
            for(int c = 0; c < MAX_POP_ITER || STOP_AUTO; c++){
                //Tcost = 0;
                Ttime = 0;
                Tdev = 0;
                Tmax = 0;
                vector<double> runs;
                for(int d = 0; d <= MAX_PATH || STOP_AUTO; d++){
                    n = d+MAX_PATH;
                    p = n*PopAlter[c];
                    runtime(Genetic_);
                    //Tcost += GENE.getCost();
                    Ttime += modeTime;
                    Tmax = (modeTime > Tmax) ? modeTime : Tmax;
                    runs.push_back(GENE.getCost());
                }
                //double acost = Tcost/(double)MAX_PATH; //avg path cost
                double aTime = Ttime/(double)MAX_PATH; //avg time to run
                Stats s = Stats(entry,PopAlter[c],g,M,runs,aTime,Tmax);
                write(s); //Ran overnight to build geneData.txt
                cout << s << endl;
                entry++;
            }
        }
    }
}

//Worst case 2n best case 1
void sort_put(vector<Stats> &mound, Stats S){
    int s = mound.size()-1;
    for(int i = 0; i <= s; i++){
        if(mound.at(i)>S){
            mound.insert(mound.begin()+i, S);
            return;
        }
    }
    mound.push_back(S);
}


Stats bestMakeUp(){
    vector<Stats> MOUND;
    int entry; double pop; int gens; double mute; double aCost; double aTime; double maxT;

    fstream file;
    file.open("geneData.txt", ios::in);
    cout << "open\n";
    while(!file.eof()){
        file >> entry >> pop >> gens >> mute >> aCost >> aTime >> maxT;
        Stats s = Stats(entry, pop, gens, mute, aCost, aTime, maxT);
        sort_put(MOUND,s);
    }
    file.close();

    cout << "\nBest case:" << endl;
    cout << MOUND.at(0) << endl;
    cout << "Worst case" << endl;
    cout << MOUND.back() << endl;
    return MOUND.at(0);
}

void runBest(){
    fstream FILE;

    Stats best = bestMakeUp();
    p = best.get(POPULATION_SIZE);
    g = best.get(NUM_GENERATIONS);
    M = best.get(PROB_MUTATION);

    LoadMap();

    FILE.open("comparison.txt", ios::out);
    for(int i = 0; i <= MAX_PATH; i++){
        n = i+10;
        FILE << "G:\t" << n << "\t";
        runtime(Genetic_);
        FILE << modeTime << "\t";
        FILE << GENE << endl;
        if(n <= 12){
            FILE << "B:\t" << n << "\t";
            runtime(BruteForce_);
            FILE << modeTime << "\t";
            FILE << BRUTE.back() << endl;
        }
        cout << i*10 << "% complete\n";
    }
    FILE.close();
}

#endif