#include <string>

class Mob{
  public:
    Mob(std::string,int,std::string,int);
    void setName(std::string);
    void setLevel(int);
    void setArea(std::string);
    void setATK();
    void setHP(double);
    void setMaxHP();
    void setDifficulty(int);
    std::string getName();
    int getLevel();
    std::string getArea();
    int getATK();
    double getHP();
    double getMaxHP();
    int getDifficulty();
  private:
    std::string mobName;
    std::string mobArea;
    int mobLevel;
    int mobATK;
    double mobHP;
    double mobMaxHP;
    int mobDifficulty;
};
