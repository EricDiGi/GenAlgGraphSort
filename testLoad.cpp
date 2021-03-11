#include <iostream>
#include <string>
#include "graph.hpp"
#include "loader.hpp"

using namespace std;

int main(){
    Load l;
    Map m = l.run();
    cout << m;
}