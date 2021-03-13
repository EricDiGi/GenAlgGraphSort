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

Path Brute::min(vector<Path> trails){
    Path min;
    if(trails.size() > 0){
        min = trails.at(0);
        for(int i = 0; i < (int)trails.size(); i++){
            if(trails.at(i).cost < min.cost)
                min = trails.at(i);
        }
    }
    return min;
}

Path Brute::Combo(int n){
    vector<int> prime;
    vector<vector<int>> set;
    for(int i = 0; i <= n; i++){
        if(i == n){
            prime.push_back(0);
        }
        else{
            prime.push_back(i);
        }
    }
    Path min = Path(map,prime);
    do{
        vector<int> temp = prime;
        bool zeros = false;
        for(int i = 0; i < (int)temp.size()-2; i++){
            if(temp.at(i+1) == 0){
                zeros = true;
                break;
            }
        }
        if(!zeros && temp.at(0) == 0){
            temp.at(n) = 0;
            Path p = Path(map, temp);
            if(p.cost < min.cost)
                min = p;
        }

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