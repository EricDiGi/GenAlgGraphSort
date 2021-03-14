#include <iostream>
#include <fstream>
#include <string>
#include "graph.hpp"
#include "loader.hpp"
#include "tracker.hpp"
#include "component.hpp"
#include "bruteForce.hpp"
#include "statistics.hpp"

using namespace std;

int main(){
    fstream file;
    file.open("bruteData.txt", ios::out);
    LoadMap();
    for(int i = 10; i <= 20; i++){
        setN(i);
        double t = Timer(BruteForce_);
        file << Stats(i, 0,0,0,t,0);
    }
    file.close();
}

/*
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
        //cout << b.force(n);
    }
}*/