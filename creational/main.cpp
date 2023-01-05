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

  Maze* maze2;
  MazeGame *mazeGame2 = new MazeGame();
  MazeFactory *factory = new MazeFactory();
  maze2 = mazeGame2->createMaze(*factory);

  // Clients use CreateMaze in conjunction with StandardMazeBuilder to create a maze
  Maze* maze3;
  MazeGame *mazeGame3 = new MazeGame();
  StandardMazeBuilder builder;
  maze3 = mazeGame3->createMaze(builder);

  return 0;
}