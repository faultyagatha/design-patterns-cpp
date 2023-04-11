# State

- complex branching and mutable state fields that change over time are two types of error-prone code

`Finite State Machine`
- you have a fixes set of states that the machine can be in (e.g., standing, ducking, jumping, diving)
- the machine can be in one state at a time
- a sequence of input events is sent to a machine
- each state has a set of transitions, each associated with an input and pointing to a state
- when an input comes in, if it matches a transition for a current state, the machine changes to the state that transition points to

> When you have a handful of flags where only one is true, what you need is enum.