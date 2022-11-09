# Design Patterns (based on "Design Patterns: Elements of Reusable Object-Oriented Software")

## Intro

- `Design patterns` are the descriptions of communicating objects and classes that are customised to solve a general design problem in a particular context.
- `Object Modeling Technique` (OMT) is real world based modeling approach for software modeling and designing. It was developed basically as a method to develop object-oriented systems and to support object-oriented programming. It describes the static structure of the system.
[OMT](https://www.geeksforgeeks.org/software-engineering-object-modeling-technique-omt)

### Classification

1. By purpose:
- creational
- structural
- behavioural

2. By scope:
- patterns applied to classes (`via inheritance`, `static-fixed at compile-time`)
- patterns applied to objects (`via object relationships`, `run-time`)

The most of patterns are in the object scope.

3. Whether the patterns are used together, e.g., composite often used with iterator and visitor.

### Class inheritance vs Object composition

1. Class inheritance: 
- `white-box reuse`: the internals of parent classes are visible to subclasses (breaks encapsulation)
- defined at compile-time, inherited implementation cannot be changed at run-time
- allows for dynamic binding (`polymorphism: let's you substitute objects that have identical interfaces for each other at run-time`)
- makes it easier to modify the implementation being reused
- every change in parent would force the changes in children (inherit only from abstract classes!!)

2. Object composition:
- `black-box reuse`: no internal details of objects are visible (does not break encapsulation)
- assembling or composing objects to get more complex functionality
- defined dynamically at run-time via objects acquiring references to other objects

> `Program to an interface, not an implementation`. Do not declare variables to be instances of particular concrete classes. Instead, commit only to an interface defined by an abstract class. Use creational patterns for object instantiation.

`Delegation` is a process when an object delegates operations to its delegate. It makes it easy to compose behaviours at run-time and to change the way they are composed. `State`, `Strategy`, `Visitor` use delegation.

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


## Memento

- describes how to encapsulate and save the internal state of an object so that the object can be restored to that state later


