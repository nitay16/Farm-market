//
// Created by ise on 1/3/22.
//

#ifndef FARMMARKET_CHICKENFARM_H
#define FARMMARKET_CHICKENFARM_H
#include "Farm.h"
#include "Chicken.h"
/*#include "SheepFarm.h"*/
class ChickenFarm:public Farm{

public:
   ChickenFarm();
    virtual void bury_animal();
    virtual void buy_animals();//buy animal
    virtual int  buy_product(Farm*,int num_of_products);
    virtual void sell_products();// buy animals
    virtual void print_farm_info();
    virtual int  buy_from_chicken_farm();//return 0 or 1 if the farm wants me
    virtual int buy_from_Cow_farm();
    virtual int buy_from_Sheep_farm();
    virtual void  add_cows(Farm*);
    virtual  void add_chicken(Farm*);
    virtual  void add_Sheep(Farm*);
    virtual  void add_farm(Farm*);
    virtual ~ChickenFarm();
};
#endif //FARMMARKET_CHICKENFARM_H
