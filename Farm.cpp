//
// Created by ise on 12/29/21.
//
#include "Farm.h"
int Farm::Farm_ID_counter=0;
int Farm::price_egg =1;
int Farm::price_milk=3;
int  Farm::price_wool=2;
int Farm::age_of_death_cow=10;
int Farm::age_of_death_sheep=5;
int Farm::age_of_death_Chicken=3;
int Farm::price_cow =10;
int Farm::price_sheep=5;
int Farm::price_Chicken=3;

Farm::Farm() {
    this->Money=10;
    this->ID=++Farm_ID_counter;
}
int Farm::get_id() {
    return this->ID;
}
void Farm::set_money_farm(int money) {
    this->Money= this->Money+money;
}
void Farm::set_num_other_product(Farm *f) {
    f->other_product++;
}
int Farm::get_other_money(Farm *f) {
    return f->Money;
}
void Farm::set_other_money(Farm* f,int other_money) {
    f->Money = other_money;
}
void Farm::set_animal_farm_age(){
    for(int i=0;i<this->farm_animal.size();i++){
        this->farm_animal[i]->set_age();
    }
}
void Farm::capacity() {
    for(int i=0;i<this->farm_animal.size();i++){
        this->my_product= this->my_product+this->farm_animal[i]->get_age();
    }
    return;
}
Farm::~Farm() {
    vector<Animal*>::iterator it;
    for(it=this->farm_animal.begin();it!=this->farm_animal.end();++it){
        delete *it;
    }
}