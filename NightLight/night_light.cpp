// Copyright (c) 2018 Paul Thomas.
//
// This file is part of stackfull/night_light.
//
#include "config.hpp"
#include "night_light.hpp"
#include "lights.hpp"
#include "comms.hpp"


void NightLight::motion() {
  switch (state) {
    case IDLE:
      commsSendEvent(MOTION);
      state = ACTIVE;
    case ACTIVE:
      lightsUpdate();
      break;
    case DAYTIME: break;
  }
}

void NightLight::stillness() {
  switch (state) {
    case ACTIVE:
      commsSendEvent(STILLNESS);
      state = IDLE;
    case IDLE:
    case DAYTIME:
      lightsOff();
      break;
  }
}

void NightLight::light() {
  switch (state) {
    case IDLE:
      commsSendEvent(LIGHT);
      state = DAYTIME;
    case DAYTIME:
      lightsOff();
      break;
    case ACTIVE: break;
  }
}

void NightLight::dark() {
  switch (state) {
    case IDLE: break;
    case ACTIVE: break;
    case DAYTIME:
      commsSendEvent(DARK);
      state = IDLE;
      break;
  }
}

