//
// Created by ise on 12/29/21.
//

#ifndef FARMMARKET_COWFARM_H
#define FARMMARKET_COWFARM_H

#include "Farm.h"
#include "Cow.h"
class cowfarm:public Farm{

public:
    cowfarm();
    virtual void buy_animals();//buy animal
    virtual void bury_animal();
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
    virtual ~cowfarm();
   // void buy_product(Farm&  f);
};
#endif //FARMMARKET_COWFARM_H
