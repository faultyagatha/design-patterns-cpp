# Null Object Pattern

- provides a safe and predictable way to deal with objects, functions, etc, whose references or pointers may be null
- can also be used to act as a stub for testing, if a certain feature such as a database is not available for testing.
- special case of a `state pattern` or `stategy pattern`

## Mechanism

Instead of using a null reference to convey absence of an object (for instance, a non-existent customer), one uses an object which implements the expected interface, but whose method body is empty. The advantage of this approach over a working default implementation is that a null object is very predictable and has no side effects: `it does nothing`.

For example, a function may retrieve a list of files in a folder and perform some action on each. In the case of an empty folder, one response may be to throw an exception or return a null reference rather than a list. Thus, the code which expects a list must verify that it in fact has one before continuing, which can complicate the design.

By returning a null object (i.e., an empty list) instead, there is no need to verify that the return value is in fact a list. The calling function may simply iterate the list as normal, effectively doing nothing. It is, however, still possible to check whether the return value is a null object (an empty list) and react differently if desired.
