#include <string>
#include "Mob.h"

using namespace std;

Mob::Mob(string name,int level,string area,int difficulty){
    setName(name);
    setLevel(level);
    setArea(area);
    setDifficulty(difficulty);
    setATK();
    setMaxHP();
    setHP(mobMaxHP);
}

void Mob::setName(string name){
    mobName = name;
}

void Mob::setLevel(int level){
    mobLevel = level;
}

void Mob::setArea(string area){
    mobArea = area;
}

void Mob::setDifficulty(int difficulty){
    mobDifficulty = difficulty;
}

void Mob::setATK(){
    mobATK = (3*(getLevel())+((getDifficulty()*getLevel())/2));
}

void Mob::setHP(double HP){
    mobHP = HP;
}

void Mob::setMaxHP(){
    mobMaxHP = (15*(getDifficulty()+getLevel()));
}

string Mob::getName(){
    return mobName;
}

int Mob::getLevel(){
    return mobLevel;
}

string Mob::getArea(){
    return mobArea;
}

int Mob::getDifficulty(){
    return mobDifficulty;
}

int Mob::getATK(){
    return mobATK;
}

double Mob::getHP(){
    return mobHP;
}

double Mob::getMaxHP(){
    return mobMaxHP;
}
