#include <iostream>
#include <vector>
#include "graph.hpp"

using namespace std;

Map::Map(){
    vector<double> mono(this->WIDTH,0.0);
    for(int i = 0; i < this->HEIGHT; i++)
        adj.push_back(mono);
}

void Map::put(int x, int y, double d){
    if(x != y)
        this->adj[y][x] = d;
}

double Map::get(int x, int y){
    return this->adj[y][x];
}

bool Map::valid(int x, int y){
    return (get(x,y) > 0);
}