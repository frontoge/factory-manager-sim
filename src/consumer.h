#pragma once

#include "demand.h"

#include <vector>

class Consumer
{
    public:
        Consumer();

        int addDemand();
        void removeDemand(int demandId);
        Demand getDemand(int demandId);
        void tickDemand(int demandId);
        void printDemands();

    private:
    std::vector<Demand> demands;

};