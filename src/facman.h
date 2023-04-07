#pragma once

#include "design.h"
#include <vector>
#include "consumer.h"

struct Machine
{
    int id;
    int uptime = 0;

};

class FacMan
{
    public:
        FacMan();
        FacMan(Consumer* c);
        void addDesign(Design toAdd);
        Design getDesign(int designId);
        Machine getMachine(int line, int slot);
        void setDesignActive(int designId, int designSlot, int startingIndex = 0);
        bool isMoreProfitable(Design d1, Design d2);
        void printLines();
        inline int getActive1() {return activeDesign1;};
        inline int getActive2() {return activeDesign2;};
        void tickMachines();

    private:
        int findFirstVacant();
        int activeDesign1;
        int activeDesign2;
        std::vector<Design> designs;
        Machine machines[2][6];
        Consumer* c;
};