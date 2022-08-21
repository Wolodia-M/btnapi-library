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
#include "btnapi.h"
/****************************init************************************/
btnapi::btnapi(int pin, int pull, int open) {
  _pin = (byte)pin;
  _pull = (byte)pull;
  _open = (byte)open;
  if(_pull == HIGH_PULL){
    pinMode(_pin, INPUT_PULLUP);
  }else if(_pull == LOW_PULL){
    pinMode(_pin, INPUT);
  }
}
/****************************set************************************/
void btnapi::debInt(int dint) {
  interval = (byte)dint;
}

void btnapi::clkInt(int cint){
  clkInterval = cint;
}

void btnapi::hInt(int hint){
  hInterval = hint;
}
/****************************tick************************************/
void btnapi::tick() {
  unsigned long currentMillis = millis();
  static unsigned long previousMillis, clkMillis, holdMillis;
  if (digitalRead(_pin) == 0 && _pull == LOW_PULL || digitalRead(_pin) == 1 && _pull == HIGH_PULL) {
    lastState = 1;
    stateS = 0;
    stateC = 0;
  }
  if (digitalRead(_pin) == 1 && _pull == LOW_PULL && lastState || digitalRead(_pin) == 0 && _pull == HIGH_PULL && lastState) {
    if (!deb) {
      deb = 1;
      previousMillis = currentMillis;
    }
    lastState = 0;
  }
  if (deb && currentMillis - previousMillis >= interval) {
    stateC = 1;
    stateS = 1;
    deb = 0;
    clicksC++;
    clicksF = 1;
    clkMillis = currentMillis;
    holdMillis = currentMillis;
  } else if (deb && lastState && currentMillis - previousMillis < interval) {
    deb = 0;
  }
  if (clicksC > 0 && currentMillis - clkMillis > clkInterval) {
    clicksC = 0;
    clicksF = 0;
  } else if (clicksC > 0) {
    clicksF = 1;
  } else if (clicksC == 0) {
    clicksF = 0;
  }
  if(btnapi::state() && currentMillis - holdMillis > hInterval){
    holdF = 1;
  }else if(!btnapi::state()){
    holdF = 0;
  }
}
/*****************************is*************************************/
bool btnapi::isClick() {
  bool stc = (bool)stateC;
  stateC = 0;
  return stc;
}

bool btnapi::state() {
  return stateS;
}

byte btnapi::clicks() {
  return stateC;
}

bool btnapi::clicking() {
  return clicksF;
}

bool btnapi::isHold(){
  return holdF;
}
