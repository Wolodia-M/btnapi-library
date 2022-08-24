// btnapi library - library for connecting buttons to Arduino
// Copyright (C) 2022  WolodiaM

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
#include "btnapi.h"  //including library
/*
    Multiclicks test
  Explain how to use multiple clicks functions
    Components
  Normal close button, attached to pin 7 and vcc;
  Resistor, conected from button pin too gnd;
  Wires;
  Arduino compatible boards;
  Breadboard.
  
    23.04.2022
    Created by WolodiaM.
*/

const int btnpin = 7;
byte clicks = 0;

btnapi btn(btnpin, LOW_PULL, NORM_CLOSE);  //Initialising the button: pin, HIGH_PULL/LOW_PULL, NORM_CLOSE/NORM_OPEN

void setup() 
{
  Serial.begin(9600);  //Starting serial on 9600 baud
}

void loop()
{
  btn.tick();  //Tick function. Need call in loop for all buttons!

  if(btn.clicking())  //btn.clicking() return true when you clicking on the button
  {
    clicks = btn.clicks();  // variable clicks = number of clicks on the button
  }
  if(!btn.clicking())  //if you stop clicking on button.
  {
    //uncoment next line to use serial monitor.
//    serialMonitor();  //function for the serial monitor
  }
  //uncoment next line if you want use serial plotter
//  serialPlotter();  //function for the serial plotter
}

void serialPlotter()
{
  Serial.println(clicks);  //print number of clicks or zero - if you don't clicking
  clicks = btn.clicks();  //reset clicks variable.
}

void serialMonitor()
{
  if(clicks > 0)  //print only if you cliccked some times
    {
      Serial.println(clicks);  //print cclicks value
      clicks = 0;  //reset cliccks vaariable, beeccause of this you have only one line of clicks
    }
}
