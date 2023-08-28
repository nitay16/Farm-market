//
// Created by ise on 1/5/22.
//

#ifndef FARMMARKET_MARKET_H
#define FARMMARKET_MARKET_H
#include "Animal.h"
#include "Farm.h"
#include "SheepFarm.h"
#include "ChickenFarm.h"
#include "CowFarm.h"
#include "Farm_animal_Exceptions.h"
class Market{
protected:
    int year;
    vector<Farm*>farm;
public:
    Market();
    void create_new_farm();
    void day_of_sell();
    void nextYear();
    void fastForwardYears();
    int getYear();
    void printMarketFarms();


    ~Market();


    void add_to_client(Farm *to_add);
};
#endif //FARMMARKET_MARKET_H
