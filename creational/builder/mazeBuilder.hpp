#pragma once
#include "../maze.hpp"
/*
This interface can create three things: 
(1) the maze, (2) rooms with a particular room number, 
and (3) doors between numbered rooms. 
The GetMaze operation returns the maze to the client. 
Subclasses of MazeBuilder will override this operation 
to return the maze that they build.

MazeBuilder does not create mazes itself; 
its main purpose is just to define an interface for creating mazes. 
It defines empty implementations primarily for convenience. 
Subclasses of MazeBuilder do the actual work.
*/

class MazeBuilder {
  public:
  // All the maze-building operations of MazeBuilder do nothing by default. 
  // They're not declared pure virtual to let derived classes 
  // override only those methods in which they're interested.
  virtual void buildMaze() {}
  virtual void buildRoom(int roomNumber) {}
  virtual void buildDoor(int roomFrom, int roomTo) {}

  [[nodiscard]]
  virtual Maze* getMaze() { return 0; }

  protected:
  MazeBuilder() = default;
};

class StandardMazeBuilder : public MazeBuilder {
  public:
  StandardMazeBuilder() = default;

  virtual void buildMaze() 
  {
    currentMaze = new Maze();
  }

  // Creates a room and builds the walls around it
  virtual void buildRoom(int roomNumber) 
  {
    if (!currentMaze->getRoom(roomNumber)) 
    {
      Room* room = new Room(roomNumber);
      currentMaze->addRoom(room);
      room->setSide(North, new Wall());
      room->setSide(South, new Wall());
      room->setSide(East, new Wall());
      room->setSide(West, new Wall());
    } 
  }

  virtual void buildDoor(int roomFrom, int roomTo) 
  {
    Room* r1 = currentMaze->getRoom(roomFrom);
    Room* r2 = currentMaze->getRoom(roomTo);
    Door* d = new Door(r1, r2);
    
    r1->setSide(commonWall(r1,r2), d);
    r2->setSide(commonWall(r2,r1), d);
  }

  [[nodiscard]]
  virtual Maze* getMaze() { return currentMaze; }

  private:
  Direction commonWall(Room* roomFrom, Room* roomTo) {};
  Maze* currentMaze = 0;
};