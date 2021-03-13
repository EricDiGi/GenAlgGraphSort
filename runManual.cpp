#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctime>
#include "component.hpp"

using namespace std;


int main(){
    LoadMap();
    while(1){
        ManualGeneticValues();
        runtime(Genetic_);
    }
}