#include <iostream>
#include <cstring>

class player
{//Player.h file
public:
  player(char[], char[], int, int);
  void setName(char[]);
  void setArea(char[]);
  void setLevel(int);
  void setXP(double);
  void setHealth(int);
  void setMaxHealth();
  void setDamage();
  char getName();
  char getArea();
  int getLevel();
  int getHealth();
  int getMaxHealth();
  int getDamage();
  int getXP();
  void setXP(int);
  int getXPReq();
  void setXPReq();
private:
  char playerName;
  char playerArea;
  int playerLevel;
  double playerHealth;
  double playerMaxHealth;
  int playerDamage;
  int XP;
  int XPReq;
}
