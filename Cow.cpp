//
// Created by ise on 12/29/21.
//

#include "Cow.h"
Cow::Cow():Animal(0,price_cow,age_of_death_cow) {

}
int Cow::get_price() {
    return this->price;
}
