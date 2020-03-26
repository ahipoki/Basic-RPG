#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

//Player
char name[100];
int maxHP = 100;
int currentHP = 100;
int ATK = 10;
int Gold = 0;

char rooms[5][100] = { "Title", "Shop", "Test3", "Test4", "Test5"};

void strupper(char* str);
int wordlen(char*, int start);
//int directionToIndex(char* dir);
void shop();
Room* createRooms(vector<Room*> &rooms, vector<Item*> &items);
void deleteItem(Item* item, vector<Item*>* delFrom);

int main()
{
    vector<Item*> items;
    vector<Room*> cleanRooms;
    vector<Item*> cleanItems;
    Room* currentRoom = createRooms(cleanRooms, cleanItems);
    bool playing = true;
    char input[80];
    cout<<"What is your name?"<<endl;
    cin.getline(name, sizeof(name));
    cout<<"Welcome "<<name<<"!"<<endl;
    cout<<"Commands: INVENTORY, GO, HELP, QUIT"<<endl;
    cout<<"Commands are NOT case sensitive"<<endl;
    currentRoom->print();
    currentRoom->printExit();
    while (playing == true){
        while (cin.peek() == '\n'){
            cin.ignore();
        }
        cin.get(input, 100, '\n');
        int commandlen = wordlen(input, 0);
        char* command = new char[commandlen +1];
        command[commandlen] = '\0';
        strncpy(command, input, commandlen);
        strupper(command);
        
        if (strcmp(command, "QUIT")==0){
            playing = false;
        }
        else if (strcmp(command, "GO")==0){
            cout<<"Test"<<endl;
            int arglen = wordlen(input, commandlen+1);
            char* direction = new char[arglen+1];
            direction[arglen] = '\0';
            strncpy(direction, input+commandlen+1, arglen);
            strupper(direction);
            for (int i = 0; i < 5; i++){
                cout<<"Test2"<<endl;
                if (strcmp(direction, rooms[i])==0){
                    cout<<"Test3"<<endl;
                    currentRoom = currentRoom->rooms[i];
                    currentRoom->print();
                }
            }
            //int dirI = directionToIndex(direction);
            //if (dirI == -1){
                //cout<<"That's not a direction"<<endl;
            //}
            //else if (currentRoom->rooms.count(dirI) == 0){
                //cout<<"That's not an exit"<<endl;
            //}
            //else{
                //currentRoom = currentRoom->rooms[dirI];
                //currentRoom->print();
            //}
            delete[] direction;
        }
        else if (strcmp(command, "INVENTORY")==0){
            cout<<"Inventory: ";
            vector<Item*>::iterator it = items.begin();
            while (it != items.end()){
                cout<<((*it)->name)<<", ";
                it++;
            }
            cout<<endl;
        }
        else if (strcmp(command, "HELP")==0){
            cout<<"Commands: QUIT, GO, INVENTORY, HELP"<<endl;
            cout<<"Commands are NOT case sensitive"<<endl;
        }
        else{
            cout<<"That's an unrecognized command"<<endl;
        }
        delete[] command;
    }
    for (vector<Room*>::iterator i = cleanRooms.begin(); i != cleanRooms.end(); i++){
        delete (*i);
    }
    for (vector<Item*>::iterator i = cleanItems.begin(); i != cleanItems.end(); i++){
        delete (*i);
    }
    return 0;
}

void strupper(char* str){
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        str[i] = toupper(str[i]);
    }
}

int wordlen(char* array, int start){
    int index = start;
    int length = strlen(array);
    while (index < length && array[index] != ' '){
        index++;
    }
    return (index - start);
}

//int directionToIndex(char* direction){
    //strupper(direction);
    //for (int i = 0; i < 4; i++){
        //if (strcmp(direction, DIRS[i])==0){
            //return i;
        //}
        //return -1;
    //}
//}

Room* createRooms(vector<Room*> &rooms, vector<Item*> &items){
    Room* title = new Room();
    title->init("Title Screen", "The title screen");
    rooms.push_back(title);
    Room* shop = new Room();
    shop->init("Shop", "The shop");
    rooms.push_back(shop);
    
    /* Exits
     * 0 = NORTH
     * 1 = EAST
     * 2 = SOUTH
     * 3 = WEST
     */
     title->rooms[0] = shop;
     shop->rooms[2] = title;
}

void deleteItem(Item* item, vector<Item*>* delFrom){
    vector<Item*>::iterator it = delFrom->begin();
    while (it != delFrom->end()){
        if (*it == item){
            delFrom->erase(it);
            return;
        }
        it++;
    }
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
        else{
            cout<<"That's an invalid option"<<endl;
        }
    }
}
