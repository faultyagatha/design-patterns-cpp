# Design Patterns (based on "Design Patterns: Elements of Reusable Object-Oriented Software")

## Intro

- `Design patterns` are the descriptions of communicating objects and classes that are customised to solve a general design problem in a particular context.
- `Object Modeling Technique` (OMT) is real world based modeling approach for software modeling and designing. It was developed basically as a method to develop object-oriented systems and to support object-oriented programming. It describes the static structure of the system.
[OMT](https://www.geeksforgeeks.org/software-engineering-object-modeling-technique-omt)

## MVC (Model/View/Controller)

1. Model: 
- application object
- contains application's data

2. View: 
- model object's screen representation
- ensures that appearence reflects the state of the model
- can be nested

3. Controller:
- defined how user interface reacts to an input

This pattern works on the basis of `Observer pattern`:
- model notifies the view about the change of its state
- view updates itself in response

Views can be nested (`Composite pattern`):
- CompositeView class is a subclass of View
- CompositeView objects act like View objects but it also manages nested View objects
- Controllers also can have hierarchies based on how they response to the different kind of user inputs

The View-Controller relationship use `Strategy pattern`:
- a view uses an instance of a Controller subclass to implement a particular response strategy
- to implement different strategy, replace the instance with a different kind of controller





