//
// Created by ise on 1/5/22.
//
#include "Market.h"
Market::Market()  {
    this->year=0;
}
void Market::add_to_client(Farm* to_add){
    for(int i=0;i<this->farm.size();i++){
        to_add->add_Sheep(this->farm[i]);
        to_add->add_cows(this->farm[i]);
        to_add->add_chicken(this->farm[i]);
        this->farm[i]->add_Sheep(to_add);
        this->farm[i]->add_cows(to_add);
        this->farm[i]->add_chicken(to_add);

    }
}
void Market::create_new_farm() {
    int cow_animal;
    int sheep_animal;
    int Chicken_Animal;
    int counter_for_string=0;
//    cout<<"----Creating new farms----"<<endl;
    cout<<"How many new cow farms will be added this year?"<<endl;
    scanf("%d",&cow_animal);
    if(cow_animal<0) {
       try{
           throw cow_farm_exception();
       }
       catch(exception &e){
           cout<<e.what()<<endl;
       }
        Market::create_new_farm();
        return;
    }
    cout<<"How many new sheep farms will be added this year?"<<endl;
    scanf("%d",&sheep_animal);
    if(sheep_animal<0){
        try{
            throw sheep_farm_exception();
        }
        catch(exception &e){
            cout<<e.what()<<endl;
        }
      Market::create_new_farm();
        return;
    }

    cout<<"How many new chicken farms will be added this year?"<<endl;
    scanf("%d",&Chicken_Animal);
    if(Chicken_Animal<0){
        try{
            throw Chicken_farm_exception();
        }
        catch(exception &e){
            cout<<e.what()<<endl;
        }
        Market::create_new_farm();
        return;
    }
    cout<<"----Adding new farms to market----"<<endl;
    for(int i=0;i<cow_animal;i++) {
        Farm *cow_me = new cowfarm();
        this->farm.push_back(cow_me);
        this->add_to_client(cow_me);
    }

    for(int i=0;i<sheep_animal;i++) {
        Farm *sheep_me = new Sheepfarm();
        this->farm.push_back(sheep_me);
        this->add_to_client(sheep_me);
    }
    for(int i=0;i<Chicken_Animal;i++) {
        Farm* Chicken_me = new ChickenFarm();
        this->farm.push_back(Chicken_me);
        this->add_to_client(Chicken_me);
    }



}

void Market::day_of_sell() {
    //sell products
    cout<<"----Begin Market----"<<endl;
    for(int i=0;i<this->farm.size();i++){
        this->farm[i]->sell_products();
    }
    cout<<"----Buy Animals----"<<endl;
    //buy animals
    for(int i=0;i<this->farm.size();i++){
        this->farm[i]->buy_animals();
    }
    for(int i=0;i<this->farm.size();i++){
        this->farm[i]->set_animal_farm_age();
        this->farm[i]->set_money_farm(10);
        this->farm[i]->bury_animal();
    }
this->year++;
}

void Market::nextYear() {
    cout<<"----Creating new farms----"<<endl;
    this->create_new_farm();

    for(int i=0;i<this->farm.size();i++){
        this->farm[i]->capacity();
    }
    this->day_of_sell();
    for(int i=0;i<this->farm.size();i++){
       this->farm[i]->bury_animal();
    }

}
void Market::fastForwardYears() {
    int how_many_years=0;//todo condition if the year of the market different from 0
    cout<<"How many years to fast forward?"<<endl;
    scanf("%d",&how_many_years);
    /*for(int i=0;i<how_many_years;i++){
        for(int j=0;i<this->farm.size();j++){
             this->farm[j]->capacity();
        }*/
    for(int i=0;i<how_many_years;i++){
        for(int j=0;j<this->farm.size();j++){
            this->farm[j]->capacity();

        }
        this->day_of_sell();
        for(int k=0;k<this->farm.size();k++) {
            this->farm[k]->bury_animal();
        }

    }
}
int Market::getYear() {
    return this->year;
}

void Market::printMarketFarms(){
    cout<<"----Market Farms----"<<endl;
    for(int i=0;i<this->farm.size();i++)
        this->farm[i]->print_farm_info();
}
Market::~Market() {
    vector<Farm*>::iterator it;
    for(it=this->farm.begin();it!=this->farm.end();++it){
        delete *it;
    }
}