enum Image {
  STAND,
  JUMP,
  DUCK
};

class Character 
{
  public: 
  void handleInput(Input input) { state->handleInput(*this, input); }
  void update() { state->update(*this); }
  void setGraphics(Image image) { graphicsImage = image; }

  private: 
    int graphicsImage{0};
    CharacterState* state{nullptr};
};

enum Input {
  PRESS_DOWN,
  RELEASE_DOWN,
  PRESS_UP,
  RELEASE_UP
};

/** State interface */
class CharacterState {
  public:
    virtual ~CharacterState() {};
    virtual void handleInput(Character& character, Input input) {}
    virtual void update(Character& character) {}
};

/** Class for each state that implements State interface */
class DuckingState : public CharacterState {
  public: 
  virtual void handleInput(Character& character, Input& input) 
  {
    if (input == RELEASE_DOWN)
    {
      // Change to standing state
      character.setGraphics(STAND);
    }
  }

  virtual void update(Character& character) 
  {
    // Start charging time in the ducking state
    chargeTime++;
    if (chargeTime > max_charge)
    {
      // do something
    }
  }

  int getChargeTime() { return chargeTime; }

  private: 
  int chargeTime{0};
  int max_charge{10000};
};