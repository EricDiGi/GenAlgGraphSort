#include <iostream>
#include <ctime>
#include "TIME.hpp"

using namespace std;

void Timer(void func()){
    clock_t t;
    t = clock();
    func();
    t = clock() - t;
    double T = t/(double)CLOCKS_PER_SEC;
    cout << T << "secs"<< endl;
}