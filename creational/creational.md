# Creational Patterns

- show how to make design more flexible, not necessarily smaller.
- abstract the instantiation process
- help to make a system independent of how its objects are created, composed, and represented
- `class creational patterns` use inheritance to vary the class that is instantiated
- `object creational patterns` delegate instantiation to another object
- become important as system evolves to depend more on object composition than class inheritance
- they shif the emphasis away from hard-coding a fixed set of behaviours towards defining a smaller set of fundamental behaviours that can be composed into any number of more complex ones. 
- 2 recurring themes:
    - 1) creational patterns all encapsulate knowledge about which concrete classes the system uses
    - 2) hide how instances of these classes are created and put together (`all the system knows about the objects is their interfaces`) -->
- give a lot of flexibility for the instantiation process

## Problem Statement 

- Example in Maze.hpp hard-codes the maze layout. 

- Changing the layoutmeans changing the member function `createMaze`, either by overriding it — which means reimplementing the whole thing — or by changing parts of it — which is error-prone and doesn't promote reuse.

Suppose you wanted to reuse an existing maze layout for a new game containing enchanted mazes. The enchanted maze game has new kinds of components, like DoorNeedingSpell, a door that can be locked and opened subsequently only with a spell; andEnchantedRoom, a room that can have unconventional items init, like magic keys or spells. How can you change CreateMazeeasily so that it creates mazes with these new classes of objects?

> `If CreateMaze calls virtual functions instead of constructor calls to create` the rooms, walls, and doors it requires, then you can change the classes that get instantiated by making a subclass of MazeGame and redefining those virtual functions. This approachis an example of the `Factory Method` pattern.

> `If CreateMaze is passed an object as a parameter to use to create` rooms, walls, and doors, then you can change the classes of rooms, walls, and doors by passing a different parameter. This is an example of the `Abstract Factory` pattern.

> `If CreateMaze is passed an object that can create a new maze in its entirety using operations for adding` rooms, doors, and walls to the maze it builds, then you can use inheritance to change parts of the maze or the way the maze is built. This is an example of the `Builder` pattern.

> `If CreateMaze is parameterized by various prototypical` room, door, and wall `objects`, which it then copies and adds to the maze, then you can change the maze's composition by replacing these prototypical objects with different ones. This is an example of the `Prototype` pattern.

## Relations

- `Abstract factory` is often implemented with `Factory` methods.
- `Factory` methods are usually called within `Template methods`.
- `Prototypes` often require an Initialise() operation on the Product class. Creator uses Initialise() to initialise the object. `Factory` method doesn't require Initialise().


