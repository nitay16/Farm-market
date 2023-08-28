//
// Created by ise on 12/29/21.
//
#include "CowFarm.h"
cowfarm::cowfarm():Farm() {
    for(int i=0;i<3;i++){
        this->farm_animal.push_back(new Cow());
    }

}
void cowfarm::bury_animal(){
    vector<Animal*>::iterator it;
    for(it=this->farm_animal.begin();it!=this->farm_animal.end();){
        if((*it)->get_age()==age_of_death_cow){
            delete *it;
            it= this->farm_animal.erase(it);
        }
        else{
            ++it;
        }
    }
}

void cowfarm::add_farm(Farm * f) {
    for(int i=0;i<this->Farmkind.size();i++){
        if(this->Farmkind[i]->get_id()==f->get_id())
            return;
    }
    this->Farmkind.push_back(f);//Cow farm(1) Added Sheep farm(2) to his client list
    cout<<"Cow farm("<<this->get_id()<<") Added Sheep farm("<<f->get_id()<<") to his client list"<<endl;
}
int cowfarm::buy_from_chicken_farm() {
    return 1;
}
int cowfarm::buy_from_Cow_farm()  {
    return 0;
}
int cowfarm::buy_from_Sheep_farm() {
    return 0;
}
void cowfarm::add_cows(Farm * f) {
    return;
}
void cowfarm::add_Sheep(Farm * f) {
    if(f->buy_from_Cow_farm()==1)
        this->add_farm(f);

}
void cowfarm::add_chicken(Farm * f) {
        return;
}


void cowfarm::buy_animals() {
    int money_checking;//temp money
    int total_price=0;
    int counter_animal=0;
    while(this->Money>=0){
        money_checking= this->Money-price_cow;
        if (money_checking<0){
            break;
        }
        this->Money = this->Money-price_cow;
        this->farm_animal.push_back(new Cow());
        counter_animal++;
    }
    if(counter_animal==0){return;}
    total_price = counter_animal*price_cow;
    cout<<"Cow farm("<<this->get_id()<<") bought "<<counter_animal<<" cows for "<<total_price<<" dollars"<<endl;
}
int cowfarm::buy_product(Farm* f,int num_of_products){
    int success_buy=0;
    while(num_of_products>0){
        int temp_money= this->Money;
        temp_money= temp_money-price_egg;
        if(temp_money<0){
            break;
        }
        this->Money= this->Money-price_egg;
        this->other_product++;
        num_of_products--;
        success_buy++;
    }
    if(success_buy==0){ return 0;}
    int amount = success_buy*price_egg;
    cout<<"Cow farm("<<this->get_id()<<") bought "<<success_buy<<" eggs for "<<amount<<" dollars from Chicken farm("<<f->get_id()<<")"<<endl;
    return success_buy;

}
void cowfarm::sell_products() {
    for(int i=0;i<this->Farmkind.size();i++){
        if(this->my_product==0)
            break;
        while(this->my_product>0){
            int num_buyingproducts= this->Farmkind[i]->buy_product(this,this->my_product);
            if(num_buyingproducts==0){
                break;
            }
           this->my_product= this->my_product- num_buyingproducts;
           this->Money= this->Money+price_milk*num_buyingproducts;
        }
    }
}
void cowfarm::print_farm_info() {
    cout<<"Farm Id: "<<this->ID<<", type: Cow farm, Money: "<< this->Money<<", Animals: "<<this->farm_animal.size()<<
    " cows, Products: Milk["<<this->my_product<<"], Wool[0], Eggs["<<this->other_product<<"]"<<endl;
}
cowfarm::~cowfarm(){

}


