#pragma once

#include <vector>

class Design
{
    public:
        Design();
        Design(int id);
        Design(const Design& other);

        void printDesign();
        void regen();
        std::vector<int> unpack();
        inline int getSum(){return sum;};
        inline int getId(){return id;};
        inline int getNumComponents(){return numComponents;};

        const Design& operator=(const Design& other);
    
    private:
        int* components;
        int numComponents;
        int id;
        int sum;
};