#include "facman.h"
#include <iostream>

FacMan::FacMan()
{
    activeDesign2 = 0;
    activeDesign1 = 0;
}

FacMan::FacMan(Consumer* c)
{
    activeDesign1 = 0;
    activeDesign2 = 0;
    this->c = c;
    for (int i = 0; i < 12; i++)
    {
        machines[i/6][i%6] = {0, 0};
    }
}

void FacMan::addDesign(Design toAdd)
{
    designs.push_back(toAdd);
    if (!activeDesign1)
    {
        setDesignActive(toAdd.getId(), 1, 0);
        // std::cout << "Added in slot 1\n";
    }
    else if(!activeDesign2)
    {
        setDesignActive(toAdd.getId(), 2, 6);
        // std::cout << "Added in slot 2\n";
    }
    else if(isMoreProfitable(toAdd, getDesign(activeDesign1)) && isMoreProfitable(getDesign(activeDesign2), toAdd))
    {
        setDesignActive(toAdd.getId(), 1, 0);
        // std::cout << "Added in slot 1\n";
    }
    else if(isMoreProfitable(toAdd, getDesign(activeDesign2)) && isMoreProfitable(getDesign(activeDesign1), toAdd))
    {
        setDesignActive(toAdd.getId(), 2, 6);
        // std::cout << "Added in slot 2\n";
    }
    else if(isMoreProfitable(toAdd, getDesign(activeDesign1)) && isMoreProfitable(toAdd, getDesign(activeDesign2)))
    {
        if (isMoreProfitable(getDesign(activeDesign1), getDesign(activeDesign2)))
        {
            setDesignActive(toAdd.getId(), 2, 6);
            // std::cout << "Added in slot 2\n";
        }
        else
        {
            setDesignActive(toAdd.getId(), 1, 0);
            // std::cout << "Added in slot 1\n";
        }
    }
    else 
    {
        std::cout << "Not activated\n";
    }
}

Design FacMan::getDesign(int designId)
{
    for (auto it = designs.begin(); it != designs.end(); ++it)
    {
        if (it->getId() == designId)
        {
            return *it;
        }
    }
}

Machine FacMan::getMachine(int line, int slot)
{
    return machines[line][slot];
}

void FacMan::setDesignActive(int designId, int designSlot, int startingIndex)
{
    Design d;
    for (auto it = designs.begin(); it != designs.end(); ++it)
    {
        // std::cout << " Checking " << it->getId() << '\n';
        if (it->getId() == designId)
        {
            d = *it;
            break;
        }
    }
    int currentIndex = startingIndex;
    std::vector<int> components = d.unpack();
    // std::cout << "Setting up machines\n";
    for (int i : components)
    {
        machines[currentIndex/6][currentIndex%6] = {i, 0};
        currentIndex++;
    }
    if (designSlot == 1)
    {
        activeDesign1 = designId;
    }
    else
    {
        activeDesign2 = designId;
    }
}

bool FacMan::isMoreProfitable(Design d1, Design d2)
{
    int price1 = c->getDemand(d1.getId()).getPricePoint();
    int price2 = c->getDemand(d2.getId()).getPricePoint();
    return (price1 - d1.getSum() > price2 - d2.getSum());
}

void FacMan::printLines()
{
    for (int i =0; i < 2; i++)
    {
        for (int y = 0; y < 6; y++)
        {
            if (machines[i][y].id == 0)
            {
                std::cout << "_ ";
            }
            else
            {
                std::cout << machines[i][y].id << " ";
            }
        }
        std::cout << "\n";
    }
}

void FacMan::tickMachines()
{
    for (int i =0; i < 2; i++)
    {
        for (int y = 0; y < 6; y++)
        {
            if (machines[i][y].id != 0)
            {
                machines[i][y].uptime++; 
                std::cout << activeDesign1 << " [" << i << "][" << y << "] uptime = " << machines[i][y].uptime << " %\t" << getDesign(activeDesign1).getNumComponents() << "\n";
            }   
        }
    }
    if (activeDesign1 != 0 && machines[0][0].uptime % getDesign(activeDesign1).getNumComponents() == 0)
    {
        c->tickDemand(activeDesign1);
    }
    if (activeDesign2 != 0 && machines[1][0].uptime % getDesign(activeDesign2).getNumComponents() == 0)
    {
        c->tickDemand(activeDesign2);
    }
}