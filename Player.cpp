#include <iostream>
#include <cstring>
#include "Player.h"

Player::player(std::string name, std::string area, int level = 1, int XP = 0)
{
  setName(name);
  setArea(area);
  setLevel(level);
  setXP(XP);
  setMaxHealth();
  
}
//Player Class
