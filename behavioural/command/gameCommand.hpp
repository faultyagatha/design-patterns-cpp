/*
// 1. Very simple implementation
class Command 
{
  public: 
  virtual ~Command() {}
  virtual void execute() = 0;
};

class JumpCommand: Command 
{
  public:
  virtual void execute() { jump(); }

  void jump() {}
};

class FireCommand: Command 
{
  public:
  virtual void execute() { fireGun(); }

  void fireGun() {}
};

enum KeyCodes 
{
  BUTTON_X,
  BUTTON_Y,
  BUTTON_A,
  BUTTON_B
};

class InputHandler 
{
  public: 
  bool isPressed(int keyCode) { return true;}
  // Input handling just delegates execution to corresponding command instance
  void handleInput()
  {
    
    // This assumes each button will have some command wired up to it.
    // If we want to support buttons that do nothing without having to explicitly check for NULL, 
    // we can define a command class whose execute() method does nothing. Then, instead of setting
    // a button handler to NULL, we point it to that object. This is a pattern called Null Object.
  
    if (isPressed(BUTTON_X)) buttonX ->execute(); 
    else if (isPressed(BUTTON_Y)) buttonY ->execute(); 
    else if (isPressed(BUTTON_A)) buttonA ->execute(); 
    else if (isPressed(BUTTON_B)) buttonB ->execute();
  }

  private:
  Command* buttonX;
  Command* buttonY;
  Command* buttonA;
  Command* buttonB;
};
*/

// 2. Implementation that adds a layer of indirection between the command and the actor -->
// lets the actor / player (e.g., AI) control any actor in the game 
// by changing the actor we execute the commands on.
class Actor 
{
  public: 
  Actor() = default;
  ~Actor() = default;

  void jump(){}
  void fireGun(){}
};

// Command is a reusable object that represents a thing that can be done.
class Command 
{
  public: 
  virtual ~Command() {}
  // Actor is a reference to the player’s character
  virtual void execute(Actor &actor) = 0;
};

class JumpCommand: Command 
{
  public:
  virtual void execute(Actor &actor) { actor.jump(); }

  void jump() {}
};

class FireCommand: Command 
{
  public:
  virtual void execute(Actor &actor) { actor.fireGun(); }

  void fireGun() {}
};

enum KeyCodes 
{
  BUTTON_X,
  BUTTON_Y,
  BUTTON_A,
  BUTTON_B
};

class InputHandler 
{
  public: 
  bool isPressed(int keyCode) { return true;}
  // Input handling just delegates execution to corresponding command instance
  Command* handleInput()
  {
    /**
     * This handle cannot execute command immediately since it doesn’t know what actor to pass in.
     * --> we can delay an execution.
    */
    if (isPressed(BUTTON_X)) return buttonX; 
    else if (isPressed(BUTTON_Y)) return buttonY; 
    else if (isPressed(BUTTON_A)) return buttonA; 
    else if (isPressed(BUTTON_B)) return buttonB;

    // Nothin is pressed
    return nullptr;
  }

  private:
  Command* buttonX;
  Command* buttonY;
  Command* buttonA;
  Command* buttonB;
};

int main() {
  Actor actor;
  InputHandler inputHandler;
  Command* command = inputHandler.handleInput();

  if (command)
  {
    /* 
    If we take these commands and make them serializable, we can send the stream of them over the network. 
    We can take the player’s input, push it over the network to another machine, and then replay it. 
    That’s one important piece of making a networked multi-player game.
    */
    command->execute(actor);
  }

  return 0;
}
