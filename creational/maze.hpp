// Example code that demonstrates the problem

enum Direction { North, South, East, West };

// Abstract class
class MapSite {
  public:
  // A basis for game operations
  virtual void enter() = 0;
};

class Room : public MapSite {
  public: 
  Room() = default;
  Room(int roomNumber): roomNum(roomNumber) {};

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
};

// Problem: hard-codes the maze layout
class MazeGame {
  public:
  MazeGame() = default;
  Maze * createMaze() {
    Maze* aMaze = new Maze;
    Room* r1 = new Room(1); 
    Room* r2 = new Room(2);
    Door* theDoor = new Door(r1, r2);

    aMaze->addRoom(r1);
    aMaze->addRoom(r2);

    // Can be moved into Room constructor
    r1->setSide(North, new Wall);
    r1->setSide(East, theDoor);
    r1->setSide(South, new Wall);
    r1->setSide(West, new Wall);

    r2->setSide(North, new Wall);
    r2->setSide(East, new Wall);
    r2->setSide(South, new Wall);
    r2->setSide(West, theDoor);

    return aMaze;
  }
};
