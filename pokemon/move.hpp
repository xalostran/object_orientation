//
//  Move.hpp
//  pokemon
//
//  Created by Stran Rasoul on 2023-12-07.
//

#ifndef Move_hpp
#define Move_hpp
#include <string>
#include "type.hpp"
#include <iostream>

using namespace std;

class Pokemon;

class Move
{
protected:
//    representerar namn, typ och kraft i en attack
    const string name;
    const Type type;
    const int power;
//ren virtuell funktion som måste implementeras av alla härledda(sekundära) klasser.
    virtual void execute(Pokemon *, Pokemon *) const = 0;

public:
    Move(const string& name, const Type type, const int power);
    

    virtual ~Move(){};
    
    void perform(Pokemon* attacker, Pokemon* defender) const;
};

//implementerar den abstrakta metoden execute för en fysisk attack
class PhysicalMove:public Move{
public:
    PhysicalMove(const string& name,const Type type, const int power);
    
    virtual void execute(Pokemon *, Pokemon *) const override;
};

//samma som physical move, men används för en speciell attack
class SpecialMove:public Move {
public:
    SpecialMove(const string& name,const Type type, const int power);
   
    virtual void execute(Pokemon *, Pokemon *) const override;
};



#endif /* Move_hpp */
