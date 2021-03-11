#ifndef path_HPP
#define path_HPP

class Path{
    private:
        friend class Map;
        double cost;
    public:
        Path(){
            cost = 0;
        }
        Path(double d){
            cost = d;
        }
};

#endif