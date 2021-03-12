#ifndef genetic_HPP
#define genetic_HPP

#include <iostream>
#include <vector>
#include "graph.hpp"
#include "tracker.hpp"

class Genetic{
    private:
        Map map;
        std::vector<Path> POP;
        Path BEST;
        Path best;
        Path next;
        int geneLen;
        int Gens;
        double mutProb;
        int worst();
        Path min();
        Path min2();
        bool hasRepeats(Path &p);
    public:
        Genetic();
        Genetic(Map m, int g, double M);
        Path Deep();
        Path main__();
        void final(Path p);
        void initialize(int n);
        void initialize(int n, int p); //n num cities p num pop
        //double fitness(Path &p);
        Path mostFit();
        void select();
        void crossover();
        void mutate();
        Path bestChild();
        void putFittest();

        friend std::ostream &operator<<(std::ostream &out, const Genetic &g){
            out << "Genetic Class:\nInitial Population:\n";
            for(Path it: g.POP){
                out << it;
            }
            return out;
        }

};

#endif