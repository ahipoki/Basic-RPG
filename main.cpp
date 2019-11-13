#include <iostream>
#include <cstring>
#include "Player.h"
#include "Mob.h"

int main()
{//Main Class
  char name[80];
  int option1;
  std::cout << "What is your name?" << std::endl;
  std::cin.getline(name, sizeof(name));
  char location[4] = {"in a hole", "in a cave", "in the mountains", "in a castle"};
  player account(name, location[0], 1, 0);
  std::cout << "\nWelcome " << account.getName() << " you find yourself " << account.getArea() << "\nand you are not sure how you ended up here\n" << std::endl;
}
