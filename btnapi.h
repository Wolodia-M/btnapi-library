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
    /**
     * @brief Construct a new btnapi object
     * 
     * @param pin Pin forbutton
     * @param pull Pull of button (LOW_PULL / HIGH_PULL)
     * @param open NORM_OPEN / NORM_CLOE
     */
    btnapi(int pin, int pull = HIGH_PULL, int open = NORM_CLOSE);
    /**
     * @brief Set debounce interval
     * 
     * @param dint New interval
     */
    void debInt(int dint = 10);
    /**
     * @brief Set interval for clicks
     * 
     * @param cint New interval
     */
    void clkInt(int cint = 300);
    /**
     * @brief Set minimal interval for button holding
     * 
     * @param hint New interval
     */
    void hInt(int hint = 300);
    /**
     * @brief Main function, need to be called in loop for each button
     * 
     */
    void tick();
    /**
     * @brief Return click state
     * 
     * @return true button is clickked
     * @return false button not clicked
     */
    bool isClick();\
    /**
     * @brief Return hold state
     * 
     * @return true button  is holded
     * @return false button not holded
     */
    bool isHold();
    /**
     * @brief return raw state of button
     * 
     * @return true Pressed
     * @return false Released
     */
    bool state();
    /**
     * @brief Return clicks count on button
     * 
     * @return byte Count of clicks
     */
    byte clicks();
    /**
     * @brief Return clicking state
     * 
     * @return true clicking on button
     * @return false not clicking on buttton
     */
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
