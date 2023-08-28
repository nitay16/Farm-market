//
// Created by ise on 1/3/22.
//

#include "ChickenFarm.h"
ChickenFarm::ChickenFarm():Farm() {
    for(int i=0;i<3;i++){
        this->farm_animal.push_back(new Chicken());
    }
}

void ChickenFarm::bury_animal(){
    vector<Animal*>::iterator it;
    for(it=this->farm_animal.begin();it!=this->farm_animal.end();){
        if((*it)->get_age()==age_of_death_Chicken){
            delete *it;
            it= this->farm_animal.erase(it);
        }
        else{
            ++it;
        }
    }
}
void ChickenFarm::add_farm(Farm * f) {
    for(int i=0;i<this->Farmkind.size();i++){
        if(this->Farmkind[i]->get_id()==f->get_id())
            return;
    }
    this->Farmkind.push_back(f);
    cout<<"Chicken farm("<<this->get_id()<<") Added Cow farm("<<f->get_id()<<") to his client list"<<endl;
}
int ChickenFarm::buy_from_chicken_farm() {
    return 0;
}
int ChickenFarm::buy_from_Cow_farm()  {
    return 0;
}
int ChickenFarm::buy_from_Sheep_farm() {
    return 1;
}
void ChickenFarm::add_cows(Farm * f) {
    if(f->buy_from_chicken_farm()==1)
        this->add_farm(f);
}
void ChickenFarm::add_Sheep(Farm * f) {
    return;
}
void ChickenFarm::add_chicken(Farm * f) {
    return;
}
void ChickenFarm::buy_animals() {
    int money_checking;//temp money
    int counter_animal=0;
    int total_price=0;
    while(this->Money>=0){
        money_checking= this->Money-price_Chicken;
        if (money_checking<0){
            break;
        }
        this->Money = this->Money-price_Chicken;
        this->farm_animal.push_back(new Chicken());//Chicken farm(3) bought 2 chickens for 6 dollars
        counter_animal++;
    }
    if(counter_animal==0){return;}
    total_price = counter_animal*price_Chicken;
    cout<<"Chicken farm("<<this->get_id()<<") bought "<<counter_animal<<" chickens for "<<total_price<<" dollars"<<endl;
}

int ChickenFarm::buy_product(Farm* f,int num_of_products){
    int success_buy=0;
    while(num_of_products>0){
        int temp_money= this->Money;
        temp_money= temp_money-price_wool;
        if(temp_money<0){
            break;
        }
        this->Money= this->Money-price_wool;
        this->other_product++;
        num_of_products--;
        success_buy++;
    }
    int amount = success_buy*price_wool;
    if(success_buy==0){ return 0;}
    cout<<"Chicken farm("<<this->get_id()<<") bought "<<success_buy<<" wool for "<<amount<<" dollars from Sheep farm("<<f->get_id()<<")"<<endl;
    return success_buy;

}

void ChickenFarm::sell_products() {
    for(int i=0;i<this->Farmkind.size();i++){
        if(this->my_product==0)
            break;
        while(this->my_product>0){
            int num_buyingproducts= this->Farmkind[i]->buy_product(this,this->my_product);
            if(num_buyingproducts==0){
                break;
            }
            this->my_product= this->my_product- num_buyingproducts;
            this->Money= this->Money+price_egg*num_buyingproducts;
        }
    }
}


void ChickenFarm::print_farm_info() {
    cout<<"Farm Id: "<<this->ID<<", type: Chicken Farm, Money: "<< this->Money<<", Animals: "<<this->farm_animal.size()<<
        " chickens, Products: Milk[0], Wool["<<this->other_product<<"], Eggs["<<this->my_product<<"]"<<endl;
}
ChickenFarm::~ChickenFarm(){

}