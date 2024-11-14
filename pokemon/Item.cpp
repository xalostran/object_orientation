//
//  Item.cpp
//  Labb1_RPG
//
//  Created by Stran Rasoul on 2023-11-30.
//

#include "Item.hpp"

Item::Item(float weightInput ,const string & nameInput)
: weight(weightInput),name(nameInput)
{

    if (weightInput<=0) {
        throw runtime_error("Item weight must be positive");
    }
}

float Item::getWeight()const{
    return weight;
}
string Item::getName()const{
    return name;
}

