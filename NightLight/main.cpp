// Copyright (c) 2018 Paul Thomas.
//
// This file is part of stackfull/night_light.
//
#include <Arduino.h>
#include "config.hpp"
#include "lights.hpp"
#include "comms.hpp"
#include "night_light.hpp"

NightLight night_light;

void setup() {
  commsSetup();
  lightsSetup();
}


void loop() {

  if (digitalRead(DARK_PIN)) {
    night_light.dark();
  } else {
    night_light.light();
  }
  if (digitalRead(PIR_PIN)) {
    night_light.motion();
  } else {
    night_light.stillness();
  }
  delay(300);
}

