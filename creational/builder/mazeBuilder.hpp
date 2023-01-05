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