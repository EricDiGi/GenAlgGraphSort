/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: statistics.hpp
  Assignment number: Project 3
**************************************************************/
#ifndef statistics_HPP
#define statistics_HPP

#include <iostream>
#include <vector>

using namespace std;

const int PATH_LENGTH = 0;
const int POPULATION_SIZE = 1;
const int NUM_GENERATIONS = 2;
const int PROB_MUTATION = 3;
const int AVG_COST = 4;
const int AVG_TIME = 5;
const int MAX_TIME = 6;

class Stats{
    private:
        friend class Heap;
        int n;
        double p;
        int g;
        double M;
        double avgCost;
        vector<double> runs;
        double aTime;
        double Tmax;
    public:
        Stats(){
            n = p = g = 0;
            M = 0;
            avgCost = 0;
            aTime = 0;
            Tmax = 0;
        }
        Stats(int N,double P,int G,double m,double aC, double aT,double tm){
            n = N; 
            p = P; 
            g = G; 
            M = m; 
            avgCost = aC; 
            aTime = aT;
            Tmax = tm;
        }
        Stats(int N,double P,int G,double m,vector<double> aC, double aT,double tm){
            n = N; 
            p = P; 
            g = G; 
            M = m; 
            runs = aC; 
            aTime = aT;
            Tmax = tm;
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
                    return aTime;
                case 6:
                    return Tmax;
            }
            return 0;
        }
        vector<double> getRuns(){
            return runs;
        }
        friend ostream &operator<<(ostream &out, const Stats &s){
            if((int)s.runs.size() > 0){
                out << s.n;
                for(int i = 0; i < (int)s.runs.size(); i++){
                    out << " " << s.runs.at(i);
                }
            }
            else{
                out << s.n << " " << s.p << " " << s.g << " " << s.M << " " << s.runs.size() << " " << s.avgCost << " " << s.aTime << " " << s.Tmax;
            }
            return out;
        }

        friend bool operator<(const Stats &S, const Stats &s){
            return (S.avgCost < s.avgCost);
        }

        friend bool operator<=(const Stats &S, const Stats &s){
            return (S.avgCost <= s.avgCost);
        }

        friend bool operator>(const Stats &S, const Stats &s){
            return (S.avgCost > s.avgCost);
        }

        friend Stats operator+(const Stats &S, const Stats &s){
            Stats R;
            R.n = -1;
            R.p = S.p + s.p;
            R.g = S.g + s.g;
            R.M = S.M + s.M;
            R.avgCost = S.avgCost + s.avgCost;
            R.aTime = S.aTime + s.aTime;
            R.Tmax = S.Tmax + s.Tmax;
            return R;
        }
        friend Stats operator/(const Stats &R, const double &i){
            Stats r;
            r.n = R.n/i;
            r.p = R.p/i;
            r.g = R.g/i;
            r.M = R.M/i;
            r.avgCost = R.avgCost/i;
            r.aTime = R.aTime/i;
            r.Tmax = R.Tmax/i;
            return r;
        }
};


#endif