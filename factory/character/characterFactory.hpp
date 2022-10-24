#include "character.hpp"
#include <vector>

class CharacterFactory
{
public:
  virtual ~CharacterFactory() {}
  virtual Character *create() = 0;
};

class CartmanFactory : public CharacterFactory
{
public:
  Character *create()
  {
    return new Cartman;
  }
  int num{5};
  void createPack(std::vector<Character *> &out_pack)
  {
    for (int i = 0; i < num; i++)
    {
      out_pack.push_back(new Cartman());
    }
  }
};

class StanFactory : public CharacterFactory
{
public:
  Character *create()
  {
    return new Stan();
  }
};

class KyleFactory : public CharacterFactory
{
public:
  Character *create()
  {
    return new Kyle();
  }
};

class KennyFactory : public CharacterFactory
{
public:
  Character *create()
  {
    return new Kenny();
  }
};