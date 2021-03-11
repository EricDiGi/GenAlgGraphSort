#ifndef tracker_HPP
#define tracker_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include "graph.hpp"

class Path{
    private:
        friend class Brute;
        std::vector<int> path;
        double cost;
    public:
        Path(){
            cost = 0;
        }
        Path(Map m,std::vector<int> p){
            cost = 0;
            path = p;
            for(int i = 0; i < (int)p.size()-1; i++){
                cost += m.get(p.at(i),p.at(i+1));
            }
        }
        void push(int city, double c){
            path.push_back(city);
            cost += c;
        }
        void push(int city){
            path.push_back(city);
        }
        bool includes(int n){
            if(size() > 0){
                auto it = std::find(path.begin(),path.end(),n);
                if(it-path.begin() == 0)
                    return false;
                return (it != path.end());
            }
            return false;
        }
        bool isStart(int n){
            return path.at(0) == n;
        }
        int size(){
            return this->path.size();
        }
        bool loop(){
            return path.at(0) == path.back();
        }
        void swap(int a,int b){
            swap(path.at(a), path.at(b));
        }
        friend std::ostream &operator<<(std::ostream &out, const Path &p){
            for(int i = 0; i < (int)p.path.size(); i++){
                out << p.path.at(i) << " ";
            }
            out << p.cost;
            out << std::endl;
            return out;
        }
};

#endif