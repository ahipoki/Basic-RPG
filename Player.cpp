#include <iostream>
#include <cstring>
#include "Player.h"

Player::player(char[] name, char[] area, int level = 1, int XP = 0)
{
  setName(name);
  setArea(area);
  setLevel(level);
  setXP(XP);
  setMaxHealth();
  setHealth(playerMaxHealth);
  setDamage();
  setXPReq();
}

void player::setName(char name[])
{
  playerName = name;
}

void player::setArea(char area[])
{
  playerArea = area;
}

void player::setLevel(int level)
{
  playerLevel = level;
}

void player::setXP(int XP)
{
  playerXP = XP;
}

void player::setHealth(int HP)
{
  playerHP = HP;
}

void player::setMaxHealth()
{
  playerMaxHP = (100 * getLevel());
}

void player::setDamage()
{
  playerDamage = (30 * getLevel());
}

char player::getName()
{
  return playerName;
}

char player::getArea()
{
  return playerArea;
}

int player::getLevel()
{
  return playerLevel;
}

int player::getHP()
{
  return playerHP;
}

int player::getMaxHP()
{
  return playerMaxHP;
}

int player::getDamage()
{
  return playerDamage;
}

int player::getXP()
{
  return XP;
}

void player::setXP(int _XP)
{
  XP = _XP;
}

int player::getXPReq()
{
  return XPReq;
}

void player::setXPReq()
{
  XPReq = 70 + ((getLevel() * getLeveL()) * 35);
}
