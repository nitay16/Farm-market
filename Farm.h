//
// Created by ise on 12/29/21.
//

#ifndef FARMMARKET_FARM_H
#define FARMMARKET_FARM_H
#include "Animal.h"
#include<vector>
#include <iostream>
#include <string>
using namespace std;
class Farm{
protected:
     static int price_milk;
     static int  price_wool;
    static int price_egg;
    static int price_cow;
    static int price_sheep;
    static int price_Chicken;
    static int age_of_death_cow;
    static int age_of_death_sheep;
    static int age_of_death_Chicken;
    int ID;
    int Money;
    int my_product=0;
    int other_product=0;
    vector<Animal*>farm_animal;
    vector<Farm*>Farmkind;
    static int Farm_ID_counter;
public:
    Farm();
    virtual void buy_animals()=0;//buy animal
    virtual int  buy_product(Farm*,int num_supplier_product)=0;
    virtual void sell_products()=0;// buy animals
    virtual void print_farm_info()= 0;
    virtual int  buy_from_chicken_farm()=0;//return 0 or 1 if the farm wants me
    virtual int buy_from_Cow_farm()=0;
    virtual int buy_from_Sheep_farm()=0;
    virtual void capacity();
    virtual void  add_cows(Farm*)=0;
    virtual  void add_chicken(Farm*)=0;
    virtual  void add_Sheep(Farm*)=0;
    virtual  void add_farm(Farm*)=0;
    virtual void set_num_other_product(Farm*);
    void set_money_farm(int money);
    virtual int get_other_money(Farm*);
    virtual void set_other_money(Farm*,int other_money);
    virtual void set_animal_farm_age();
    virtual void bury_animal()=0;
    int get_id();

    virtual ~Farm();

};
#endif //FARMMARKET_FARM_H
