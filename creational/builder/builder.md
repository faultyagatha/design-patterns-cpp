# Builder

## Application

Use the Builder pattern when
- the algorithm for creating a complex object should be independent of the parts that make up the object and how they're assembled.
- the construction process must allow different representations for the object that's constructed.

## Participants

1. `Builder`
- specifies an abstract interface for operations that create parts of abstract product objects

2. `ConcreteBuilder`
- constructs and assembles parts of the product by implementing the Builder interface
- defines and keeps track of the representation it creates
- provides an interface for retrieving the product

3. `Director`
- constructs an object using the Builder interface

4. `Product`
- represents the complex object under construction. `ConcreteBuilder` builds the product's internal representation and defines the process by which it's assembled.
- includes classes that define the constituent parts, including interfaces for assembling the parts into the final result.

## Mechanism

- the client creates the `Director object` and configures it with the desired `Builder object`
- Director notifies the builder whenever a part of the product should be built
- Builder handles requests from the director and adds parts to the product
- the client retrieves the product from the builder.


