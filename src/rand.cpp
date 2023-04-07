#include "rand.h"
#include <iostream>

RanD::RanD()
{

}

void RanD::addDemand(Demand toAdd)
{
    demands.push(toAdd);
}

void RanD::addDesign(Design toAdd)
{
    designs.push_back(toAdd);
}

Design RanD::getDesign(int designId)
{
    for (auto it = designs.begin(); it != designs.end(); ++it)
    {
        if (it->getId() == designId)
        {
            return *it;
        }
    }
}

void RanD::tryDesign(FacMan& man)
{
    Demand next = demands.front();
    Design d(next.getId());
    std::cout << "Trying: ";
    d.printDesign();
    if (d.getSum() >= next.getPricePoint())
    {
        std::cout << "Rejected.\n";
    }
    else 
    {
        std::cout << "Accepted!\n";
        demands.pop();
        man.addDesign(d);
    }
}