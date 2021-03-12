#include <iostream>
#include <string>
#include "graph.hpp"
#include "loader.hpp"
#include "bruteForce.hpp"
#include "tracker.hpp"

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
        //cout << b.force(n);
    }
}