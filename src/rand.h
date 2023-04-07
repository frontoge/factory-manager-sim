#pragma once

#include <queue>

#include "demand.h"
#include "design.h"
#include "facman.h"

class RanD 
{
    public:
        RanD();
        void addDemand(Demand toadd);
        void addDesign(Design toAdd);
        Design getDesign(int designId);
        void tryDesign(FacMan& man);

        // void printDemands();
        
    private:
        std::queue<Demand> demands;
        std::vector<Design> designs;
};