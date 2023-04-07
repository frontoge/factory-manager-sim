#include "consumer.h"
#include <iostream>
#include <unistd.h>

Consumer::Consumer()
{
    
}

int Consumer::addDemand()
{
    Demand d;
    demands.push_back(d);
    return d.getId();
}

Demand Consumer::getDemand(int demandId)
{
    for(Demand d : demands)
    {
        if (d.getId() == demandId)
        {
            return d;
        }
    }
}

void Consumer::removeDemand(int demandId)
{
    for(auto it = demands.begin(); it != demands.end(); ++it)
    {
        if (it->getId() == demandId)
        {
            demands.erase(it);
        }
    }
}

void Consumer::printDemands()
{
    for (Demand d : demands) 
    {
        d.print();
        // sleep(1);
    }
}

void Consumer::tickDemand(int demandId)
{
    for(auto it = demands.begin(); it != demands.end(); ++it)
    {
        if (it->getId() == demandId)
        {
            it->setMarket(it->getMarket()-1);
        }
    }
}