//
// Created by ise on 12/29/21.
//

#ifndef FARMMARKET_ANIMAL_H
#define FARMMARKET_ANIMAL_H
#include <iostream>
#include <string>
using namespace std;
class Animal {
protected:
    int age;
    int price;
    static int price_cow;
    static int price_sheep;
    static int price_Chicken;
    static int age_of_death_cow;
    static int age_of_death_sheep;
    static int age_of_death_Chicken;
public:
    Animal();
    Animal(int age,int price ,int age_death);
    virtual  int get_age();
    virtual void set_age();
    virtual int get_price()=0;

    virtual ~Animal(){};


};

#endif //FARMMARKET_ANIMAL_H
