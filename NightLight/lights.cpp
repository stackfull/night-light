// Copyright (c) 2018 Paul Thomas.
//
// This file is part of stackfull/night_light.
//
#include <Arduino.h>
#include "config.hpp"
#include "lights.hpp"

static double hue2rgb(double p, double q, double t);


void lightsSetup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(COLOUR_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
}

void lightsOff() {
  analogWrite(RED_PIN,  0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);
}

void lightsUpdate() {
  int sensorValue = analogRead(COLOUR_PIN);

  double h = sensorValue / 1024.0L;
  double s = 0.3L;
  double l = 0.5L;

  double q = l < 0.5 ? l * (1 + s) : l + s - l * s;
  double p = 2 * l - q;
  double r, g, b;

  r = hue2rgb(p, q, h + 1/3.0);
  g = hue2rgb(p, q, h);
  b = hue2rgb(p, q, h - 1/3.0);

#ifdef HAVE_HWSERIAL0
  String msg = "S = ";
  msg = msg + sensorValue + ": h = " + h + ", p = " + p + ", q = " + q + ", r = " + r + ", g = " + g + ", b = " + b;
  Serial.println(msg);
#endif
  analogWrite(RED_PIN,  r * 255);
  analogWrite(GREEN_PIN, g * 255);
  analogWrite(BLUE_PIN, b * 255);
}


static double hue2rgb(double p, double q, double t) {
  if(t < 0) t += 1;
  if(t > 1) t -= 1;
  if(t < 1/6.0) return p + (q - p) * 6 * t;
  if(t < 1/2.0) return q;
  if(t < 2/3.0) return p + (q - p) * (2/3.0 - t) * 6;
  return p;
}

