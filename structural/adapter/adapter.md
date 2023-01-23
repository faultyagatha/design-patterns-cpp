# Adapter (aka Wrapper)

Convert the interface of a class into another interface clients expect. Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.

Often the adapter is responsible for functionality the adapted class doesn't provide.

## Application

Use the Adapter pattern when
- you want to use an existing class, and its interface does not match the one you need.
- you want to create a reusable class that cooperates with unrelated or unforeseen classes (classes that don't necessarily have compatible interfaces).
- (object adapter only) you need to use several existing subclasses, but it's impractical to adapt their interface by subclassing every one. An object adapter can adapt the interface of its parent class.


## Participants

1. `Target` 
- defines the domain-specific interface that Client uses.

2. `Client` 
- collaborates with objects conforming to the Target interface.

3. `Adaptee`
- defines an existing interface that needs adapting.

4. `Adapter`
- adapts the interface of Adaptee to the Target interface.

## Mechanism

Clients call operations on an Adapter instance. In turn, the adapter calls Adaptee operations that carry out the request.
