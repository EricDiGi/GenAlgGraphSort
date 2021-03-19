/***************************************************************
  Student Name: Eric DiGioacchino
  File Name: tracker.hpp
  Assignment number: Project 3
**************************************************************/
#ifndef tracker_HPP
#define tracker_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include "graph.hpp"

class Path{
    private:
        friend class Brute;
        friend class Genetic;
        std::vector<int> path;
        double cost;
    public:
        Path(){
            cost = 0;
        }
        Path(int len){
            cost = len;
        }
        Path(Map m,std::vector<int> p){
            cost = 0;
            path = p;
            for(int i = 0; i < (int)p.size()-1; i++){
                cost += m.get(p.at(i),p.at(i+1));
            }
        }
        void setPath(Map m){
            cost = 0;
            for(int i = 0; i < (int)path.size()-1; i++){
                cost += m.get(path.at(i),path.at(i+1));
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
        double getCost(){
            return cost;
        }

        void shuffle(){
            std::vector<int> sub;
            for(int i = 1; i < (int)path.size()-2; i++)
                sub.push_back(path.at(i));
            std::random_shuffle(sub.begin(),sub.end());
            for(int i = 1; i < (int)path.size()-2; i++)
                path.at(i) = sub.at(i-1);
        }

        friend bool operator==(const Path &P, const Path &p){
            return P.cost == p.cost;
        }
        friend bool operator!=(const Path &P, const Path &p){
            return P.cost != p.cost;
        }
        friend bool operator<(const Path &P, const Path &p){
            return P.cost < p.cost;
        }
        friend bool operator<=(const Path &P, const Path &p){
            return P.cost <= p.cost;
        }
        friend bool operator>(const Path &P, const Path &p){
            return P.cost > p.cost;
        }
        friend bool operator||(const Path &P, const Path &p){
            return (fabs(P.cost - p.cost)/P.cost) <= 0.1;
        }
        friend std::ostream &operator<<(std::ostream &out, const Path &p){
            for(int i = 0; i < (int)p.path.size(); i++){
                out << p.path.at(i) << " ";
            }
            out << "\t" << p.cost;
            out << "\t";
            return out;
        }
};

#endif