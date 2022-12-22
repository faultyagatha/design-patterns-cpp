#include <iostream>

class Character
{
public:
  Character() = default;
  virtual ~Character();

  int getHitPoints() { return hitPoints; }
  int getSpeed() { return speed; }
  int getAttack() { return attack; }

protected:
  int hitPoints{0};
  int speed{0};
  int attack{0};
};

class Cartman : public Character
{
public:
  Cartman()
  {
    hitPoints = 10;
    speed = 1;
    attack = 10;
  };
  void sayAuthority()
  {
    std::cout << "Respect my authority!" << std::endl;
  }
};

class Stan : public Character
{
public:
  Stan()
  {
    hitPoints = 7;
    speed = 5;
    attack = 2;
  };
  void sayOmg()
  {
    std::cout << "Omg, they killed Kenny!" << std::endl;
  }
};

class Kyle : public Character
{
public:
  Kyle()
  {
    hitPoints = 7;
    speed = 5;
    attack = 0;
  };
  void sayMorals()
  {
    std::cout << "Guys, I've learned something today!" << std::endl;
  }
};

class Kenny : public Character
{
public:
  Kenny()
  {
    hitPoints = 1;
    speed = 10;
    attack = 2;
  };
  void sayDude()
  {
    std::cout << "Dude!" << std::endl;
  }
};
