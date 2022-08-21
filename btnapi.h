// Btnapi - library for connecting buttons to Arduino compaytible boards
// Copyright (C) 2022 WolodiaM

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
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
