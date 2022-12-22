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

  virtual Maze* makeMaze() const 
  {
    return new Maze();
  }

  virtual Wall* makeWall() const 
  {
    return new Wall();
  }

  virtual Room* makeRoom(int roomNumber) const
  {
    return new Room(roomNumber);
  }

  virtual Door* MakeDoor(Room* r1, Room* r2) const
  { 
    return new Door(r1, r2); 
  }
};