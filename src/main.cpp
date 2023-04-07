#include <iostream>
#include "design.h"
#include "consumer.h"
#include "rand.h"
#include "facman.h"
#include <unistd.h>

int main() 
{
    RanD rand;
    Consumer* c = new Consumer();
    int timestep = 1;
    FacMan facman(c);
    while (timestep++)
    {
        std::cout<<"\t\tTimestep: " << timestep << "\n\n";

        std::cout<<"\tCurrent Demands: \n";
        c->printDemands();
        std::cout << "\n\n";

        int id = c->addDemand();
        rand.addDemand(c->getDemand(id));
        std::cout << "Created demand: "; c->getDemand(id).print();
        std::cout << "\n\n";

        rand.tryDesign(facman);

        if (facman.getActive1() != 0) 
        {
            std::cout << "Active Design 1: "; facman.getDesign(facman.getActive1()).printDesign();
        }
        if (facman.getActive2() != 0)
        {
            std::cout << "Active Design 2: "; facman.getDesign(facman.getActive2()).printDesign();
        }

        std::cout << "\n\n\tMachine Lines:\n";
        facman.printLines();
        facman.tickMachines();
        std::getchar();
        system("clear");
    }
    std::cout << "Press Enter to continue.\n";
    std::getchar();
    delete c;
    // std::cout << "Created design"
    return 0;
}