// Example code that demonstrates the problem

enum Direction {North, South, East, West};

// Abstract class
class MapSite {
  public:
  // A basis for game operations
  virtual void enter() = 0;
};

class Room : public MapSite {
  public: 
  Room(int nRooms) {};

  MapSite * getSide(Direction dir) const {};
  void setSite(Direction dir, MapSite* ms) {};
  virtual void enter(){};

  private:
  MapSite * sides[4];
  int nRooms = 0;
};

class Wall : public MapSite {
  public: 
  Wall(){};
  virtual void enter(){};
};

class Door : public MapSite {
  public: 
  Door(Room * r1, Room * r2) {};
  virtual void enter(){};
  Room * otherSidrFrom(Room *r) {};

  private:
  Room * r1 = nullptr;
  Room * r2 = nullptr;
  bool isOpen = false;
};

class Maze {
  public: 
  Maze() {};
  void addRoom(Room * r){};
  Room * getRoom(int nRoom) const {};
  // ...

};
