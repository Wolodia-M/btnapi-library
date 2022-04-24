#include "btnapi.h"

/****************************init************************************/
btnapi::btnapi(int pin, int pull = HIGH_PULL, int open = NORM_CLOSE) {
  _pin = (byte)pin;
  _pull = (byte)pull;
  _open = (byte)open;
  pinMode(_pin, _pull);
}
/****************************set************************************/
void btnapi::debInt(int dint = 10) {
  interval = (byte)dint;
}

void btnapi::clkInt(int cint = 300){
  clkInterval = cint;
}

void btnapi::hInt(int hint = 300){
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
