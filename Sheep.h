//
// Created by ise on 12/29/21.
//

#ifndef FARMMARKET_SHEEP_H
#define FARMMARKET_SHEEP_H
#include "Animal.h"
class Sheep:public Animal{
public:
    Sheep();
    virtual int get_price();
    virtual ~Sheep(){};
};
#endif //FARMMARKET_SHEEP_H
