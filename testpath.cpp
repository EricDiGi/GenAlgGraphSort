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
    Path p;
    p.put(0);
    p.put(1,m.get(0,1));
    p.put(2,m.get(1,2));
    p.put(5,m.get(2,5));
    p.put(10, m.get(5,10));
    p.put(0,m.get(10,0));
    
}