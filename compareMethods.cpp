#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "graph.hpp"
#include "loader.hpp"
#include "tracker.hpp"
#include "genetic.hpp"
#include "bruteForce.hpp"

using namespace std;

int main(){
    srand(time(0));
    Load l;
    Map m = l.run();

    Brute b;
    b.chart(m);
    while(1){
        int n = 0;
        cout << "Size: ";
        cin >> n;

        Path cmb = b.Combo(n);
        cout << cmb;

        Genetic g(m);
        g.initialize(n);
        g.final(cmb);
        //cout << g.main__();
        cout << g.Deep();
    }
}