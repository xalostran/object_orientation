//
//  pokemon.cpp
//  pokemon
//
//  Created by Stran Rasoul on 2023-12-07.
//

#include "pokemon.hpp"

//initialiserar medlemsvariabler med angivna värden.
Pokemon::Pokemon(const string &name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health, int attack, int spAttack, int defense, int spDefense) : name(name), type(type), move1(move1), move2(move2), move3(move3), move4(move4), health(health), attack(attack), spAttack(spAttack), defense(defense), spDefense(spDefense)
{
    if (health <=0 || attack<=0 || spAttack<=0 || defense<=0 || spDefense <=0) {
        throw runtime_error("Invalid value must be a positive");
    }
}

//minskar hälsan baserat på angiven skada och hälsan får inte bli negativ.
void Pokemon::reduceHealth(int damage){
    health-=damage;
    if (health<0) {
        health=0;
    }
}

//använder typechart för att få reda på skademultiplikatorn för given skadetyp i förhållande till pokemon typ
float Pokemon::calculateDamageMultiplier(Type damagetype){
    return TypeChart::getDamageMultiplier(damagetype, type) ;
    
}
//anropar perform för att utföra en attack på given pokemon
void Pokemon::executeMove1(Pokemon* target){
    move1->perform(this, target);
}

void Pokemon::executeMove2(Pokemon* target){
    move2->perform(this, target);
}

void Pokemon::executeMove3(Pokemon* target){
    move3->perform(this, target);
}

void Pokemon::executeMove4(Pokemon* target){
    move4->perform(this, target);
}


//använder medlemslistan för att initialisera medlemsvariablerna och kallar även på basens (Pokemon)
//konstruktor med motsvarande värden.
DualTypePokemon::DualTypePokemon(const string& name, Type primaryType,Type secondType, const Move* move1,const Move* move2,const Move* move3,const Move* move4, int health, int attack, int spAttack,int defense, int spDefence) : Pokemon(name, primaryType, move1, move2, move3, move4, health, attack, spAttack, defense, spDefence),secondType(secondType){}


//Överskuggar metoden i Pokemon för att hantera skademultiplikatorn för Pokémon med dubbla typer. Den
//multiplicerar multiplikatorerna för de två typerna för att få det totala värdet.
float DualTypePokemon::calculateDamageMultiplier(Type damagetype){
    float multiplier1 = TypeChart::getDamageMultiplier(damagetype, type);
    float multiplier2 = TypeChart::getDamageMultiplier(damagetype, secondType);
    return multiplier1 * multiplier2;
}
