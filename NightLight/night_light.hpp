// Copyright (c) 2018 Paul Thomas.
//
// This file is part of stackfull/night_light.
//
#ifndef NIGHT_LIGHT_NIGHT_LIGHT_HPP
#define NIGHT_LIGHT_NIGHT_LIGHT_HPP

///
///      +------+
///      |ACTIVE|
///      +^-----+
///       |   |stillness
/// motion|   |
///      +----v+
///      |IDLE |
///      +----^+
///  light|   |
///       |   |dark
///      +v------+
///      |DAYTIME|
///      +-------+
///
class NightLight {

  enum State {
    IDLE,
    DAYTIME,
    ACTIVE,
  };

  State state = IDLE;

public:
  void motion();
  void stillness();
  void light();
  void dark();
};

#endif //NIGHT_LIGHT_NIGHT_LIGHT_HPP
