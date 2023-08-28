//
// Created by ise on 1/9/22.
//

#ifndef FARM_MARKET_FARM_ANIMAL_EXCEPTIONS_H
#define FARM_MARKET_FARM_ANIMAL_EXCEPTIONS_H
#include <iostream>
#include <exception>
using namespace std;
class cow_farm_exception:public exception{
    virtual const char* what() const throw(){
        return "Insert valid number of cow farms";
    }
};
class sheep_farm_exception:public exception{
    virtual const char* what() const throw(){
        return "Insert valid number of sheep farms";
    }
};
class Chicken_farm_exception:public exception{
virtual const char* what() const throw(){
    return "Insert valid number of chicken farms";
}
};

#endif //FARM_MARKET_FARM_ANIMAL_EXCEPTIONS_H
