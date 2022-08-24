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
#include "btnapi.h"  //including library
/*
    All functions
  Explain all functions of  the library
    Components
  Normal close button, attached to pin 7 and vcc;
  Resistor, conected from button pin too gnd;
  Wires;
  Arduino compatible boards;
  Breadboard.
  
    21.04.2022
    Created by WolodiaM.
*/
const int btnpin = 7; //Conect button to this pin

btnapi btn(btnpin, LOW_PULL, NORM_CLOSE);  //Initialising the button: pin, HIGH_PULL/LOW_PULL, NORM_CLOSE/NORM_OPEN
//btnpin - pin, to which you conect buttton/
//HIGH_PULL/LOW_PULL - to which pin button is pulled by resiston. HIGH_PULL say that button is pulled to vcc and LOW_PULL say, that button is pulled to gnd.
//NORM_CLOSE/NORM_OPEN - what type of button is. NORM_OPEN - pushing the button deactivaate it. NORM_CLOSE - pushing the button activate it.
//HIGH_PULL = 0x2, LOW_PULL = 0x0, NORM_CLOSE = 0, NORM_OPEN = 1.

//btnapi btn(btnpin);  //initialising button only with pin. HIGH_PULL and NORM_CLOSE types is standart.
//btnapi btn(btnpin, LOW_PULL);  //initialising button only with pin and pull type. NORM_CLOSE button type is standart.

void setup(){
  btn.debInt(20); //set button delay time to 20.
  btn.clkInt(400); //set interval betwen clicks for double click to 400.
}

void loop(){
  btn.tick();  //Tick function. Need call in loop for all buttons!
  bool click = btn.isClick(); //btn.click() check the clicks on buttons and we save this to var click.
  bool state = btn.state(); //btn.state() send a state of button (1 - pressed, 2 - released) and we save it to var state.
  byte clicks = btn.clicks();  //return number of clicks on button.
  bool clk = btn.clicking();  //return 1 if you clicking and 0 if don't
}
