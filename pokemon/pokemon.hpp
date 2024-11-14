//
//  pokemon.hpp
//  pokemon
//
//  Created by Stran Rasoul on 2023-12-07.
//

#ifndef Pokemon_hpp
#define Pokemon_hpp
#include <string>
#include "type.hpp"
#include "move.hpp"
#include <stdexcept>

using namespace std;
class Pokemon
{
private:
//    representerar olika typer av attacker som en pokemon kan utföra
    const Move* move1;
    const Move* move2;
    const Move* move3;
    const Move* move4;
    
    const string name;
    int health;
    int attack;
    int spAttack;
    int defense;
    int spDefense;
    
    
    
protected:
//    representerar typen av pokemon
    const Type type;
   
    
public:
    
    Pokemon(const string &name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health,  int attack, int spAttack, int defense, int spDefense);
    
//    virtuell destruktor som gör klassen abstrakt
    virtual ~Pokemon(){};
    
    void executeMove1(Pokemon* target);
    
    void executeMove2(Pokemon* target);
    
    void executeMove3(Pokemon* target);
    
    void executeMove4(Pokemon* target);
    
    void reduceHealth(int damage);
    
//    beräknar skademultiplikatiorn baserat på skadetyp
    virtual float calculateDamageMultiplier(Type damagetype);
    
    int getHealth()const{return health;}
    
    int getAttack()const{return attack;}
    
    
    int getSpecialAttack()const {return spAttack;}
    
    int getDefence()const {return defense;}
    
    int getSpecialDefence()const {return spDefense;}
    
    
    string getName()const {return name;}
    
};
class DualTypePokemon:public Pokemon{
private:
//    representerar typen av motståndar pokemon
    const Type secondType;
public:
    DualTypePokemon(const string& name, Type primaryType,Type secondType, const Move* move1,const Move* move2,const Move* move3,const Move* move4, int health, int attack, int spAttack,int defense, int spDefence);
    
//    destruktor för denna subklass
    virtual ~DualTypePokemon(){};
    
//    överskuggar metoden från den överordnade klassen för att hantera skademultiplikatiorn för en pokemon med dubbla typer
    float calculateDamageMultiplier(Type damagetype)override;
};


#endif /* Pokemon_hpp */
