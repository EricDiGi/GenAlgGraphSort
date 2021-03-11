#ifndef graph_HPP
#define graph_HPP

#include <vector>
#include <iostream>

class Map{
    private:
        friend class Brute;
        friend class Gene;
        friend class Load;
        const static int V = 20;
        const static int WIDTH = 20;
        const static int HEIGHT = 20;
        std::vector<std::vector<double>> adj;
    public:
        Map();
        void put(int x, int y, double d);
        double get(int x, int y);
        bool valid(int x, int y);
        friend std::ostream &operator<<(std::ostream &out, const Map &m){
            for(int i = 0; i < m.HEIGHT; i++){
                for(int j = 0; j < m.WIDTH; j++){
                    out << (m.adj[i][j] ) << " ";
                }
                out << std::endl;
            }
            return out;
        }

};

#endif