#pragma once

// Example code that demonstrates the problem

enum Direction { North, South, East, West };

// Abstract class
class MapSite {
  public:
  // A basis for game operations
  virtual void enter() = 0;
  virtual ~MapSite() = default;
};

class Room : public MapSite {
  public: 
  Room() = default;
  Room(int roomNumber): roomNum(roomNumber) {};
  ~Room() override = default;

  MapSite * getSide(Direction dir) const { return sides[dir]; };
  void setSide(Direction dir, MapSite* ms) {};
  virtual void enter(){};

  private:
  MapSite * sides[4];
  int roomNum = 0;
};

class Wall : public MapSite {
  public: 
  Wall() = default;
  virtual void enter(){};
  ~Wall() override = default;
};

class Door : public MapSite {
  public: 
  Door() = default;
  Door(Room * roomFrom, Room * roomTo): r1(roomFrom), r2(roomTo) {};
  virtual void enter(){};
  Room * otherSideFrom(Room *r) {
    if (r1 == r) 
      return r2;
    else 
      return r1;
   };

  ~Door() override = default;

  private:
  Room * r1 = nullptr;
  Room * r2 = nullptr;
  bool isOpen = false;
};

class Maze {
  public: 
  Maze() = default;
  void addRoom(Room * r){};
  Room * getRoom(int roomNumber) const {};
  // ...

  ~Maze() = default;
};
