//
// Created by ise on 12/29/21.
//
#include "Animal.h"
int Animal::age_of_death_cow=10;
 int Animal::age_of_death_sheep=5;
 int Animal::age_of_death_Chicken=3;
 int Animal::price_cow =10;
 int Animal::price_sheep=5;
 int Animal::price_Chicken=3;

Animal::Animal() {
    this->age = 0;
    this->age_of_death = 0;
    this->price = 0;
}
Animal::Animal(int age, int price, int age_death) {
    this->age = age;
    this->price = price;
    this->age_of_death = age_death;

}

void Animal::set_age() {
    this->age++;
}
int  Animal::get_age() {
    return this->age;

}

