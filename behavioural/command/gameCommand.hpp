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
    /**
     * This assumes each button will have some command wired up to it.
     * If we want to support buttons that do nothing without having to explicitly check for NULL, 
     * we can define a command class whose execute() method does nothing. Then, instead of setting
     * a button handler to NULL, we point it to that object. This is a pattern called Null Object.
    */
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