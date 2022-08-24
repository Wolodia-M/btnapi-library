// Example code for btnapi library
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
    Button test
  Simple sketch to chech the library.
    Components
  Normal close button, attached to pin 7;
  Resistor, conected from button pin too ground;
  Wires;
  Arduino compatible boards;
  Breadboard.
  
    21.04.2022
    Created by WolodiaM.
*/
const int btnpin = 7; //Conect button to this pin

btnapi btn(btnpin, LOW_PULL, NORM_CLOSE);  //Initialising the button: pin, HIGH_PULL/LOW_PULL, NORM_CLOSE/NORM_OPEN

void setup()
{
  Serial.begin(9600); //Starting serial on 9600 baud
}

void loop()
{
  btn.tick();  //Tick function. Need call in loop for all buttons!
  bool click = btn.click(); //btn.click() check the clicks on buttons and we save this to var click.
  bool state = btn.state(); //btn.state() send a state of button (1 - pressed, 2 - released) and we save it to var state.
  if(click = 1) //Send a serial message when button is clicked.
  {          
    Serial.println("btnpress");
  }  
//Uncoment next line if you want see button state in serial plotter
//  Serial.println(state);  //For serial plotter. Send button state (1 - pushed, 2 - released).
}
