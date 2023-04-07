#include "demand.h"

#include <random>
#include <iostream>

int Demand::idCounter = 100;

std::random_device gen;

int genUniformNumber(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

int genNormalNumber(double mean, double stddev) 
{
    std::normal_distribution<double> distribution(mean, stddev);
    return int(distribution(gen)+0.5);
}

Demand::Demand()
:Demand(idCounter++)
{
}

Demand::Demand(int id)
:id(id), pricePoint(genUniformNumber(8,50)), market(genNormalNumber(50.0, 15.0))
{
    // std::cout << "[DEBUG] Created demand with id " << id << "\n"; 
    // pricePoint = getRandomNum(8, 50);
}

Demand::Demand(int id, int price, int market)
:id(id), pricePoint(price), market(market)
{
    
}

//Copy constructor to keep the static var coutner from increasing
Demand::Demand(const Demand& other)
{
    this->id = other.id;
    this->pricePoint = other.pricePoint;
    this->market = other.market;
}

int Demand::getId()
{
    return this->id;
}

int Demand::getPricePoint()
{
    return this->pricePoint;
}

int Demand::getMarket()
{
    return this->market;
}

void Demand::setPricePoint(int value)
{
    pricePoint = value;
}

void Demand::setMarket(int value)
{
    market = value;
}

void Demand::tickMarket()
{
    market--;
}

const Demand& Demand::operator=(const Demand& other)
{
    this->id = other.id;
    this->pricePoint = other.pricePoint;
    this->market = other.market;
}

void Demand::print()
{
    std::cout << "Demand #" << id << " Price: $" << pricePoint << " Market: " << market << "\n";
}