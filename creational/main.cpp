#include "maze.hpp"
#include "mazeGame.hpp"
#include "abstract-factory/mazeFactory.hpp"

int main()
{
  // Builds a maze consisting of two rooms with a door between them. 
  // CreateMaze() hard-codes the class names, 
  // making it difficult to create mazes with different components.
  MazeGame *mazeGame1 = new MazeGame();
  mazeGame1->createMaze();

  MazeGame *mazeGame2 = new MazeGame();
  MazeFactory *factory = new MazeFactory();
  mazeGame2->createMaze(*factory);

  return 0;
}