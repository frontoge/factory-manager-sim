#pragma once

class Demand 
{
    public:
        Demand();
        Demand(int id);
        Demand(int id, int price, int market);
        Demand(const Demand& other);

        int getPricePoint();
        void setPricePoint(int value);

        int getId();

        int getMarket();
        void setMarket(int value);

        void tickMarket();

        void print();

        const Demand& operator=(const Demand& other);

        static int idCounter;
    private:
        int pricePoint;
        int id;
        int market;

};