//
// Created by ise on 12/29/21.
//

#ifndef FARMMARKET_COW_H
#define FARMMARKET_COW_H
#include "Animal.h"
class Cow:public Animal{
public:
    Cow();
    virtual int get_price();
    virtual ~Cow(){};

};
#endif //FARMMARKET_COW_H
