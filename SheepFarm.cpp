//
// Created by ise on 1/3/22.
//

#include "SheepFarm.h"
Sheepfarm::Sheepfarm():Farm(){
    for(int i=0;i<3;i++){
        this->farm_animal.push_back(new Sheep());
    }
}

 void Sheepfarm::bury_animal(){
     vector<Animal*>::iterator it;
     for(it=this->farm_animal.begin();it!=this->farm_animal.end();){
         if((*it)->get_age()==age_of_death_sheep){
             delete *it;
             it= this->farm_animal.erase(it);
         }
         else{
             ++it;
         }
     }
}
void Sheepfarm::add_farm(Farm * f) {
    for(int i=0;i<this->Farmkind.size();i++){
        if(this->Farmkind[i]->get_id()==f->get_id())
            return;
    }
    this->Farmkind.push_back(f);
    cout<<"Sheep farm("<<this->get_id()<<") Added Chicken farm("<<f->get_id()<<") to his client list"<<endl;
}
int Sheepfarm::buy_from_chicken_farm() {
    return 0;
}
int Sheepfarm::buy_from_Cow_farm()  {
    return 1;
}
int Sheepfarm::buy_from_Sheep_farm() {
    return 0;
}
void Sheepfarm::add_cows(Farm * f) {
    return;
}
void Sheepfarm::add_Sheep(Farm * f) {
    return;
}
void Sheepfarm::add_chicken(Farm * f) {
    if(f->buy_from_Sheep_farm()==1)
        this->add_farm(f);
}

void Sheepfarm::buy_animals() {
    int money_checking;//temp money
    int total_price=0;
    int counter_animal=0;
    while(this->Money>=0){
        money_checking= this->Money-price_sheep;
        if (money_checking<0){
            break;
        }
        this->Money = this->Money-price_sheep;
        this->farm_animal.push_back(new Sheep());
        counter_animal++;
    }
    if(counter_animal==0){return;}
    total_price = counter_animal*price_sheep;
    cout<<"Sheep farm("<<this->get_id()<<") bought "<<counter_animal<<" sheeps for "<<total_price<<" dollars"<<endl;
}

int Sheepfarm::buy_product(Farm* f,int num_of_products){
    int success_buy=0;
    while(num_of_products>0){
        int temp_money= this->Money;
        temp_money= temp_money-price_milk;
        if(temp_money<0){
            break;
        }
        this->Money= this->Money-price_milk;
        this->other_product++;
        num_of_products--;
        success_buy++;
    }
    if(success_buy==0){ return 0;}
    int amount = success_buy*price_milk;
    cout<<"Sheep farm("<<this->get_id()<<") bought "<<success_buy<<" milk for "<<amount<<" dollars from Cow farm("<<f->get_id()<<")"<<endl;
    return success_buy;

}
void Sheepfarm::sell_products() {
    for(int i=0;i<this->Farmkind.size();i++){
        if(this->my_product<=0)
            break;
        while(this->my_product>0){
            int num_buyingproducts= this->Farmkind[i]->buy_product(this,this->my_product);
            if(num_buyingproducts==0){
                break;
            }
            this->my_product= this->my_product- num_buyingproducts;
            this->Money= this->Money+price_wool*num_buyingproducts;
        }
    }
}
void Sheepfarm::print_farm_info() {
    cout<<"Farm Id: "<<this->ID<<", type: Sheep farm, Money: "<< this->Money<<", Animals: "<<this->farm_animal.size()<<
        " sheep, Products: Milk["<<this->other_product<<"], Wool["<<this->my_product<<"], Eggs[0]"<<endl;
}
Sheepfarm::~Sheepfarm(){

}