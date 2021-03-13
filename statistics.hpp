#ifndef statistics_HPP
#define statistics_HPP

#include <iostream>
#include <vector>

using namespace std;

const int PATH_LENGTH = 0;
const int POPULATION_SIZE = 1;
const int NUM_GENERATIONS = 2;
const int PROB_MUTATION = 3;
const int AVG_TIME = 4;
const int AVG_DEV = 5;

class Stats{
    private:
        int n;
        int p;
        int g;
        double M;
        double avgCost;
        double avgDev;
    public:
        Stats(){
            n = p = g = 0;
            M = 0;
            avgCost = 0;
            avgDev = 0;
        }
        Stats(int N,int P,int G,double m,double aC,double aD){
            n = N; 
            p = P; 
            g = G; 
            M = m; 
            avgCost = aC; 
            avgDev = aD;
        }
        double get(int v){
            switch(v){
                case 0:
                    return n;
                case 1:
                    return p;
                case 2:
                    return g;
                case 3:
                    return M;
                case 4:
                    return avgCost;
                case 5:
                    return avgDev;
            }
            return 0;
        }
        friend ostream &operator<<(ostream &out, const Stats &s){
            out << s.n << " - " << s.p << " - " << s.g << " - " << s.M << " - " << s.avgCost << " - " << s.avgDev << endl;
            return out;
        }

};

Stats Best(vector<Stats> STATS){
    Stats min = STATS.at(0);
    for(Stats it: STATS){
        if(it.get(AVG_DEV) < min.get(AVG_DEV))
            min = it;
    }
    return min;
}

#endif