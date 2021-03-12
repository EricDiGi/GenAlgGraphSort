#include <iostream>
#include "TIME.hpp"

using namespace std;

void someFunc(){
    for(int j = 0; j < 10000; j++){
    int a = 0;
    for(int i = 0 ; i < 1000; i++){
        a += 1;
    }
    }
}

int main(){
    //someFunc();
    Timer(someFunc);
}