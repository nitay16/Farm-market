#include <iostream>
#include "Animal.h"
#include "Farm.h"
#include "ChickenFarm.h"
#include "SheepFarm.h"
#include "CowFarm.h"
#include <iostream>
#include <string>
int main_1() {
    Farm *f1 = new cowfarm();
   f1->set_animal_farm_age();
  /* f1->print_farm_info();*/
   Farm *f2= new ChickenFarm();
   f2->set_animal_farm_age();
   f2->add_farm(f1);
   f2->sell_products();
   f2->print_farm_info();
   f1->print_farm_info();

    return 0;
}
