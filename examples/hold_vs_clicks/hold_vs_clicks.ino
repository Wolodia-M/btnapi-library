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
    Hold vs clicks
  See diferent with holding and clicking.
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


void loop() {
  btn.tick();  //tick function. Need for all buttons.
  Serial.print(btn.isClick() + 2);  //Send data for clicks diagram. +2 need to separate  2 diagrams.
  Serial.print(" ");  //Separator for two diagrams.
  Serial.println(btn.isHold());  //Send data for button hold diagram.
}
