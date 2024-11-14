//
//  move.cpp
//  pokemon
//
//  Created by Stran Rasoul on 2023-12-07.
//

#include "pokemon.hpp"
#include "move.hpp"

//skapar ett move objekt
//sparar de angivna värdena i objektets medlemsvariabler
Move::Move(const string& name, const Type type, const int power)
: type(type), name(name), power(power)
{
    if (power<0) {
    throw invalid_argument("Not valid power for this move");
    }
}
//utför ett 'move' från en attackerande pokemon på en försvarande pokemon
void Move::perform(Pokemon *attacker, Pokemon *defender)const{
    
       
       if (attacker->getHealth() == 0)
       {
           cout << attacker->getName() << " is in a fainted state and can’t move." << endl;
           return;
       }

       else if (defender->getHealth() <= 0)
       {
           cout << attacker->getName() << " cannot perform a move, " << defender->getName() << " has already fainted." << endl;
           return;
       }
//    fortsätt ifall varken attacker eller defenders hälsa är större än 0
       else{
           execute(attacker, defender);
       }

       
//
//       if (defender->getHealth() <= 0)
//       {
//           cout << defender->getName() << " has fainted." << endl;
//       }
}

//utför fysisk attack från en attackerande pokemon på en försvarande pokemon
PhysicalMove::PhysicalMove(const string& name,const Type type, const int power)
: Move(name,type, power){}

void PhysicalMove::execute(Pokemon * attacker, Pokemon * defender) const {
    
    //Beräkningen grundar sig på att skada reduceras baserat på försvararens hälsa
    float basedDamage = (float)power * (attacker->getAttack()/(float)defender->getDefence()/5.f);
    
    //Beräknar en skade-multiplikator baserad på försvararens typ
    float multiplier=defender->calculateDamageMultiplier(type);
    float totalDamage = basedDamage*multiplier;
    cout << attacker->getName() << " used " << name << endl;
    defender->reduceHealth(totalDamage);

    //skriver ut information om attackens effektivitet
    if (multiplier == 0) {
        cout<<"It doesn’t affect "<<defender->getName()<< endl;
    }else if (multiplier <1 && multiplier!=0){
        
        cout<<"It’s not very effective..."<< endl;
    }else if (multiplier>1){
        cout<<"It’s super effective!"<< endl;
        
    }
    
    
}

//konstruktor för en spAttack
//anropar basklassens konstruktor
SpecialMove::SpecialMove(const string& name, const Type type, const int power)
:Move(name, type, power){}

//utför en speciell attack från en attackerande pokemon på en försvarande pokemon.
void SpecialMove::execute(Pokemon * specialAttack, Pokemon *specialDefender)const{
    
//    Beräkningen grundar sig på att skada reduceras baserat på försvararens hälsa.
    float baseDamage =(float)power * (specialAttack->getSpecialAttack()/(float)specialDefender->getSpecialDefence()/5.f);
    float multiplier = specialDefender->calculateDamageMultiplier(type);
    //cout<<type<< endl;
    //cout<<multiplier<<endl;
    
    //Beräknar en skade-multiplikator baserad på försvararens typ.
    float totalDamage = baseDamage*multiplier;
    std::cout << specialAttack->getName() << " used " << name << std::endl;
    specialDefender->reduceHealth(totalDamage);
    
    //skriver ut info om attacken
    if (multiplier == 0) {
        cout<<"It doesn’t affect "<<specialDefender->getName()<< endl;
    }else if (multiplier <1 && multiplier !=0){
        
        cout<<"It’s not very effective..."<< endl;
    }else if (multiplier>1){
        cout<<"It’s super effective!"<< endl;
        
    }
}
