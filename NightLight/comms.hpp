// Copyright (c) 2018 Paul Thomas.
//
// This file is part of stackfull/night_light.
//
#ifndef NIGHT_LIGHT_COMMS_HPP
#define NIGHT_LIGHT_COMMS_HPP

enum Event {
  MOTION,
  STILLNESS,
  LIGHT,
  DARK
};

extern void commsSetup();
extern void commsSendEvent(Event event);

#endif //NIGHT_LIGHT_COMMS_HPP
