/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: bruteForce.cpp
  Assignment number: Project 3
**************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.hpp"
#include "bruteForce.hpp"
#include "tracker.hpp"

using namespace std;

void Brute::chart(Map m){
    this->map = m;
}


Path Brute::Combo(int n){
    vector<int> prime;
    for(int i = 1; i < n; i++){
        prime.push_back(i);
    }
    Path min = Path(100000);
    Path curr;
    do{
        vector<int> temp = prime;
        temp.insert(temp.begin(),0);
        temp.push_back(0);
        curr = Path(map,temp);
        min = (curr < min) ? curr : min;
    }while(next_permutation(prime.begin(), prime.end()));

    return min;
}

/******************************
BRUTE FORCE USING RECURSION
*******************************/

/*
Path Brute::force(int n){
    Path P;
    P.push(0);
    if(n <= 4 || n >= 20){
        return P;
    }
    P = force(P,0,0,n+1);
    return P;
}

Path Brute::force(Path &p, int loc, int dest, int count){
    //pass++;
    vector<Path> tracks;
    tracks.push_back(p);

    Path curr;
    for(int i = 0; i < count-1; i++){
        if(map.valid(loc,i) && !p.includes(i) && (i != loc) && p.size() <= count){
            curr = p;
            curr.push(i, map.get(loc,i));

            if(curr.size() == count && curr.loop()){
                return curr;
            }
            if(curr.size() < count){
                tracks.push_back(force(curr, i, dest,count));
            }
        }
    }
    vector<Path> refined;
    for(Path it: tracks){
        if(it.size() == count){
            refined.push_back(it);
        }
    }
    return min(refined);
}
*/