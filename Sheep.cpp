//
// Created by ise on 12/29/21.
//
#include "Sheep.h"
Sheep::Sheep():Animal(0,price_sheep,age_of_death_sheep) {

}

int Sheep::get_price() {
    return this->price;
}