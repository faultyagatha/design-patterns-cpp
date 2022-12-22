#pragma once
#include "../maze.hpp"

/*
MazeFactory can create components of mazes. 
It builds rooms, walls, and doors between rooms. 
It might be used by a program that reads plans for 
mazes from a file and builds the corresponding maze. 
Or it might be used by a program that builds mazes randomly. 

Programs that build mazes take a MazeFactory as an argument 
so that the programmer can specify the classes of rooms, 
walls, and doors to construct.
*/
class MazeFactory 
{
  public:
  MazeFactory() = default;

  [[nodiscard]]
  virtual Maze* makeMaze() const 
  {
    // nodiscard will warn or error if no l-value is present
    return new Maze();
  }

  [[nodiscard]]
  virtual Wall* makeWall() const 
  {
    return new Wall();
  }

  [[nodiscard]]
  virtual Room* makeRoom(int roomNumber) const
  {
    return new Room(roomNumber);
  }

  [[nodiscard]]
  virtual Door* makeDoor(Room* r1, Room* r2) const
  { 
    return new Door(r1, r2); 
  }
};