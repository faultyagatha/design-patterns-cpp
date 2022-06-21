#include "character.hpp"

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