#ifndef btnAPI_h
#define btnAPI_h
/*
It is a small and light button library for Arduino IDE compatible boards.
It can display button state (after debounce) and check button for a click.
All functions retturn bool (1 or 0).

Library created by WolodiaM.
*/
#include <Arduino.h>
#define HIGH_PULL 0x2 //use internal pullup resistor!
#define LOW_PULL 0x0 //need external pulldown resistor!
#define NORM_OPEN 1 //open when released
#define NORM_CLOSE 0  //open when pressed

class btnapi {
  public:
    btnapi(int pin, int pull = HIGH_PULL, int open = NORM_CLOSE);
    void debInt(int dint = 10);
    void clkInt(int cint = 300);
    void hInt(int hint = 300);
    void tick();
    bool isClick();
    bool isHold();
    bool state();
    byte clicks();
    bool clicking();
  private:
    byte interval = 10;
    int clkInterval = 300;
    int hInterval = 300;
    byte deb = 0;
    byte stateS = 0;
    byte stateC = 0;
    byte clicksC = 0;
    byte clicksF = 0;
    bool holdF = 0;
    byte _pin;
    byte _pull;
    byte lastState = 1;
    byte _open;
};

#endif
