// Copyright (c) 2018 Paul Thomas.
//
// This file is part of stackfull/night-light.
//

#include <Arduino.h>
#include "comms.hpp"
#include "config.hpp"

void commsSetup() {
#ifdef HAVE_HWSERIAL0
  Serial.begin(115200);
#endif
}

void commsSendEvent(Event event) {
  switch (event) {
    case MOTION:
      dbg("Motion detected!");
      break;
    case STILLNESS:
      dbg("Motion ended!");
      break;
    case LIGHT:
      dbg("Light!");
      break;
    case DARK:
      dbg("Dark!");
      break;
  }
}
