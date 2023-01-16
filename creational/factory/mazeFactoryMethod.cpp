#pragma once
#include "../maze.hpp"

/*
The function CreateMaze() in mazeGame.hpp builds and returns a maze. 
One problem with this function is that it hard-codes the classes 
of maze, rooms, doors, and walls. 
Below are the factory methods to let subclasses choose these components.

Each factory method returns a maze component of a given type. 
MazeGame provides default implementations that return the 
simplest kinds of maze, rooms, walls, and doors.
*/

class MazeGame {
  public: 
  Maze* CreateMaze();

  // factory methods:
  [[nodiscard]]
  virtual Maze* makeMaze() const { return new Maze; }

  [[nodiscard]]
  virtual Room* makeRoom(int n) const { return new Room(n); }

  [[nodiscard]]
  virtual Wall* makeWall() const { return new Wall; }

  [[nodiscard]]
  virtual Door* makeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

Maze* MazeGame::CreateMaze () {
  Maze* aMaze = makeMaze();
  Room* r1 = makeRoom(1);
  Room* r2 = makeRoom(2);
  Door* theDoor = makeDoor(r1, r2);
  aMaze->addRoom(r1);
  aMaze->addRoom(r2);
  r1->setSide(North, makeWall());
  r1->setSide(East, theDoor);
  r1->setSide(South, makeWall());
  r1->setSide(West, makeWall());
  r2->setSide(North, makeWall());
  r2->setSide(East, makeWall());
  r2->setSide(South, makeWall());
  r2->setSide(West, theDoor);
  return aMaze;
  }

/*
// We can redefine some or all the factory methods 
// to specify variations in products:

  class BombedMazeGame : public MazeGame {
  public:
    BombedMazeGame();
    virtual Wall* MakeWall() const
    { return new BombedWall; }
    virtual Room* MakeRoom(int n) const
    { return new RoomWithABomb(n); }
};
*/