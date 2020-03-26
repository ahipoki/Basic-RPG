#include <iostream>
#include <cstring>

using namespace std;

//Player
char name[100];
int maxHP = 100;
int currentHP = 100;
int ATK = 10;
int Gold = 0;

void strupper(char* str);
void inventory();
void help();
void shop();

int main()
{
    bool running = true;
    cout<<"What is your name?"<<endl;
    cin.getline(name, sizeof(name));
    cout<<"Welcome "<<name<<"!"<<endl;
    cout<<"Your commands are: INVENTORY, HELP"<<endl;
    while (running == true){
        char input[80];
        cout<<"Do you want to go to the shop?"<<endl;
        cin.getline(input, sizeof(input));
        strupper(input);
        if (strcmp(input, "YES") == 0){
            shop();
        }
        else if (strcmp(input, "NO") == 0){
            running = false;
        }
        else if (strcmp(input, "INVENTORY") == 0){
            inventory();
        }
        else if (strcmp(input, "HELP") == 0){
            help();
        }
        else{
            cout<<"That's an invalid option"<<endl;
        }
    }
}

void strupper(char* str){
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        str[i] = toupper(str[i]);
    }
}

void inventory(){
    cout<<"Inventory:"<<endl;
}

void help(){
    cout<<"Your commands are:"<<endl;
    cout<<"INVENTORY: Check what you have in your inventory"<<endl;
    cout<<"HELP: Print out what commands you have"<<endl;
}

void shop(){
    char choice[80];
    bool browsing = true;
    cout<<"Welcome to the shop!"<<endl;
    while (browsing == true){
        cout<<"Your gold: "<<Gold<<endl;
        cout<<"Do you want to buy something, sell something, or go back?"<<endl;
        cin.getline(choice, sizeof(choice));
        strupper(choice);
        if (strcmp(choice, "BUY") == 0){
            char buy[80];
            cout<<"What do you want to buy?"<<endl;
            cin.getline(buy, sizeof(buy));
            strupper(buy);
            cout<<"You want to buy: "<<buy<<endl;
        }
        else if (strcmp(choice, "SELL") == 0){
            char sell[80];
            cout<<"What do you want to sell?"<<endl;
            cin.getline(sell, sizeof(sell));
            strupper(sell);
            cout<<"You want to sell: "<<sell<<endl;
        }
        else if (strcmp(choice, "BACK") == 0){
            browsing = false;
        }
        else if (strcmp(choice, "INVENTORY") == 0){
            inventory();
        }
        else if (strcmp(choice, "HELP") == 0){
            help();
        }
        else{
            cout<<"That's an invalid option"<<endl;
        }
    }
}
