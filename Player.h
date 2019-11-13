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
  void setHP(int);
  void setMaxHP();
  void setDamage();
  char getName();
  char getArea();
  int getLevel();
  int getHP();
  int getMaxHP();
  int getDamage();
  int getXP();
  void setXP(int);
  int getXPReq();
  void setXPReq();
private:
  char playerName;
  char playerArea;
  int playerLevel;
  double playerHP;
  double playerMaxHP;
  int playerDamage;
  int XP;
  int XPReq;
}
