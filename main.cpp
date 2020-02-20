#include <iostream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
#include "Mob.h"

using namespace std;

//Player
char name[80];
int maxHP = 100;
int currentHP = maxHP;
int ATK = 10;
int gold = 0;

//Enemies
string enemies[15] = {"caster minion", "melee minion", "cannon minion", "super minion", "gromp", "raptor", "wolf", "krug", "scuttle crab", "blue buff", "red buff", "dragon", "rift herald", "elder dragon", "baron nashor"};

//Shop
int choice;
int sword = 0;
int armor = 0;
int potion = 0;
int meat = 0;
int skin = 0;

void strupper(char* str);
void fight(vector<Mob*>* mListM);
void initEnemies(vector<Mob*>* mListM);
void shop();

int main()
{
    char input[80];
    vector<Mob*> mList;
    vector<Mob*>* mListM = &mList;
    bool running = true;
    initEnemies(mListM);
    cout<<"What is your name?"<<endl;
    cin.getline(name, sizeof(name));
    while (running == true){
        cout<<"Do you want to fight?"<<endl;
        cin.getline(input, 80);
        strupper(input);
        if (strcmp(input,"YES")==0){
            fight(mListM);
        }
        else if (strcmp(input,"NO")==0){
            cout<<"You don't fight!"<<endl;
        }
        else if (strcmp(input, "QUIT")==0){
            running = false;
        }
        else{
            cout<<"That's a false input"<<endl;
        }
    }
}

void strupper(char* str){
    int len = strlen(str);
    for (int i = 0;i<len;i++){
        str[i] = toupper(str[i]);
    }
}

void fight(vector<Mob*>* mListM){
    vector<Mob*>::iterator mListIt;
    for (mListIt = mListM->begin(); mListIt != mListM->end(); ++mListIt){
        cout<<"You fight a "<<(*mListIt)->getName()<<"!"<<endl;
    }
}

void initEnemies(vector<Mob*>* mListM){
    string tempName;
    for (int i = 0; i < 15; i++){
        tempName = enemies[i];
        int tempLevel = 5;
        string tempArea = "Summoner's Rift";
        int tempDifficulty = 2;
        mListM->push_back(new Mob(tempName, tempLevel, tempArea, tempDifficulty));
    }
}

void shop(){
    cout<<"\n Shop"<<endl;
    cout<<"\n Buy or sell?"<<endl;
    cout<<"\n 1. Buy"<<endl;
    cout<<"\n 2. Sell"<<endl;
    cout<<"\n 3. Go back"<<endl;
    cout<<"\n> ";
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"\n Shop, Buy"<<endl;
            cout<<"\n What do you want to buy?"<<endl;
            cout<<"\n 1. Sword    50 gold"<<endl;
            cout<<"\n 2. Armor    100 gold"<<endl;
            cout<<"\n 3. Potion   10 gold"<<endl;
            cout<<"\n 4. Go back"<<endl;
            cout<<"\n> ";
            cin>>choice;
            switch(choice){
                case 1:
                    if (gold<50){
                        cout<<"\n You don't have enough gold!"<<endl;
                        cout<<"\n ";
                        break;
                    }else{
                        gold = gold-50;
                        sword = sword+1;
                        cout<<"\n Item Added - Sword"<<endl;
                        cout<<"\n ";
                        break;
                    }
                case 2:
                    if (gold<100){
                        cout<<"\n You don't have enough gold!"<<endl;
                        cout<<"\n ";
                        break;
                    }else{
                        gold = gold-100;
                        armor = armor+1;
                        cout<< "\n Item Added - Armor"<<endl;
                        cout<<"\n ";
                        break;
                    }
                case 3:
                    if (gold<10){
                        cout<<"\n You don't have enough gold!"<<endl;
                        cout<<"\n ";
                        break;
                    }else{
                        gold = gold-10;
                        potion=potion+1;
                        cout<<"\n Item Added - Potion"<<endl;
                        cout<<"\n ";
                        break;
                    }
                case 4:
                    break;
            }
        case 2:
            cout<<"\n Shop, Sell"<<endl;
    }
}
