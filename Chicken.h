//
// Created by ise on 12/29/21.
//

#ifndef FARMMARKET_CHICKEN_H
#define FARMMARKET_CHICKEN_H
#include "Animal.h"
class Chicken:public Animal{
public:
    Chicken();
    virtual ~Chicken(){};
    virtual int get_price();
};
#endif //FARMMARKET_CHICKEN_H
