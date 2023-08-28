//
// Created by ise on 12/29/21.
//

#ifndef FARMMARKET_PRODUCT_H
#define FARMMARKET_PRODUCT_H
#include <iostream>
#include <string>
using namespace std;
class product{
public:
    string name_product;
    int price;
    int amount;
    product(string name,int price,int amount);
    virtual ~product(){};
};
#endif //FARMMARKET_PRODUCT_H
