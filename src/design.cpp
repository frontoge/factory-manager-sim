#include "design.h"
#include <random>
#include <iostream>

std::random_device generator;

Design::Design()
{

}

Design::Design(int id)
:id(id)
{
    regen();
}

Design::Design(const Design& other)
{
    id = other.id;
    numComponents = other.numComponents;
    components = new int[numComponents];
    for (int i = 0; i < numComponents; i++)
    {
        components[i] = other.components[i];
    }
    sum = other.sum;
}

void Design::printDesign()
{
    std::cout << id << " <" << components[0];
    for (int i = 1; i < numComponents; i++)
    {
        std::cout << ", " << components[i];
        
    }
    std::cout <<"> = " << sum << "\n";
}

void Design::regen() 
{
    if (components == nullptr) 
    {
        delete[] components;
    }
    sum = 0;

    std::uniform_int_distribution<int> sizeDist(2, 12);
    std::uniform_int_distribution<int> compDist(1, 12);
    numComponents = sizeDist(generator);
    components = new int[numComponents];
    for (int i = 0; i < numComponents; i++)
    {
        components[i] = compDist(generator);
        sum += components[i];
    }
    // std::cout << "Sum for design: " << sum << '\n';
}

const Design& Design::operator=(const Design& other)
{
    if (components == nullptr)
    {
        delete[] components;
    }

    id = other.id;
    numComponents = other.numComponents;
    components = new int[numComponents];
    for (int i = 0; i < numComponents; i++)
    {
        components[i] = other.components[i];
    }
    sum = other.sum;
    return *this;
}

std::vector<int> Design::unpack()
{
    std::vector<int> list;
    for (int i = 0; i < numComponents; i++)
    {
        list.push_back(components[i]);
    }
    return list;
}
