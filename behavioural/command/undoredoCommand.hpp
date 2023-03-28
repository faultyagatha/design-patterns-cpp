/**
 * Example with moving a unit on the screen
*/

// Command is a thing that can be done at a specific point in time.
class Command
{
  public:
  Command() = default;

  virtual void execute() = 0;
  virtual void undo() = 0;
  virtual void redo() = 0;
};

class Unit
{
  public:
  Unit() = default;
  
  void moveTo(int x, int y) {}
  int getX() { return x; }
  int getY() { return y; }

  private:
  int x = 0;
  int y = 0;
};

// Bind command to the unit being moved.
class MoveUnitCommand : public Command
{
  public:
  MoveUnitCommand(Unit* unit, int x, int y): u(unit), x(x), y(y) {}

  virtual void execute() { u->moveTo(x, y); }
  private:
  Unit* u;
  int x = 0;
  int y = 0;
};

enum KeyCodes 
{
  BUTTON_UP,
  BUTTON_DOWN,
  BUTTON_LEFT,
  BUTTON_RIGHT
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
    if (isPressed(BUTTON_UP)) return buttonUp; 
    else if (isPressed(BUTTON_DOWN)) return buttonDown; 
    else if (isPressed(BUTTON_LEFT)) return buttonLeft; 
    else if (isPressed(BUTTON_RIGHT)) return buttonRight;

    // Nothin is pressed
    return nullptr;
  }

  private:
  Command* buttonUp;
  Command* buttonDown;
  Command* buttonLeft;
  Command* buttonRight;
};

int main() {
  Unit unit;
  InputHandler inputHandler;
  Command* command = inputHandler.handleInput();

  if (command)
  {
    /* 
    If we take these commands and make them serializable, we can send the stream of them over the network. 
    We can take the player’s input, push it over the network to another machine, and then replay it. 
    That’s one important piece of making a networked multi-player game.
    */
    command->execute();
  }

  return 0;
}
