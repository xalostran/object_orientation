//
//  Item.hpp
//  Labb1_RPG
//
//  Created by Stran Rasoul on 2023-11-30.
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Item {
private:
    float weight;
    string name;
public:
    
    Item(float weightInput ,const string & nameInput);
    
    float getWeight()const;
    
    string getName()const;
};

#endif /* Item_hpp */
