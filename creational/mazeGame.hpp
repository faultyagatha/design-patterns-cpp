#pragma once

#include "maze.hpp"
#include "abstract-factory/mazeFactory.hpp"
#include "builder/mazeBuilder.hpp"


class MazeGame {
  public:
  MazeGame() = default;

  // 1. Problem: hard-codes the maze layout
  Maze* createMaze() {
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

  // 2. Abstract Factory
  Maze* createMaze(MazeFactory &factory)
  {
    Maze* aMaze = factory.makeMaze();
    Room *r1 = factory.makeRoom(1);
    Room *r2 = factory.makeRoom(2);
    Door* aDoor = factory.makeDoor(r1, r2);

    aMaze->addRoom(r1);
    aMaze->addRoom(r2);

    r1->setSide(North, factory.makeWall());
    r1->setSide(East, aDoor);
    r1->setSide(South, factory.makeWall());
    r1->setSide(West, factory.makeWall());

    r2->setSide(North, factory.makeWall());
    r2->setSide(East, factory.makeWall());
    r2->setSide(South, factory.makeWall());
    r2->setSide(West, aDoor);

    return aMaze;
  }

  // 3. Builder
  Maze* createMaze(MazeBuilder& builder)
  {
    builder.buildMaze();

    builder.buildRoom(1);
    builder.buildRoom(2);
    builder.buildDoor(1, 2);
    
    return builder.getMaze();
  }
};