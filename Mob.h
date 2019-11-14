#include <iostream>
#include <cstring>

class classMob
{//Mob.h file
public:
  classMob(char[], int, char[], int);
  void setName(char[]);
  void setLevel(int);
  void setArea(char[]);
  void setDamage();
  void setHP(double);
  void setMaxHP();
  
private:
  char mobName[80];
  
}
