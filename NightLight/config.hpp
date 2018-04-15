// Copyright (c) 2018 Paul Thomas.
//
// This file is part of stackfull/night_light.
//
#ifndef NIGHT_LIGHT_CONFIG_HPP
#define NIGHT_LIGHT_CONFIG_HPP

#ifdef __AVR_ATtinyX4__

// ATTiny84 pins: A=ADC, ~=PWM, 1=arduino pin no.
//
//                              +---+
//                         VCC -+   +- GND
//                           0 -+   +- 10  A      colour IN(ADC)
//                           1 -+   +- 9   A      pir    IN(digital)
//                      ¬RESET -+   +- 8   A      light  IN(digital)
//  green OUT(PWM)         ~ 2 -+   +- 7   A
//   blue OUT(PWM)       A ~ 3 -+   +- 6   A SCL  I2C
//    I2C            SDA A ~ 4 -+   +- 5 ~ A      red    OUT(PWM)
//                              +---+

#define COLOUR_PIN A0
#define PIR_PIN    9
#define DARK_PIN   8

#define RED_PIN    5
#define GREEN_PIN  2
#define BLUE_PIN   3

#elif defined(__AVR_ATtiny84__)

// ATTiny84 pins: A=ADC, ~=PWM, 1=arduino pin no.
//
//                              +---+
//                         VCC -+   +- GND
//                          10 -+   +- 0   A      colour IN(ADC)
//                           9 -+   +- 1   A      pir    IN(digital)
//                      ¬RESET -+   +- 2   A      light  IN(digital)
//  green OUT(PWM)         ~ 8 -+   +- 3   A
//   blue OUT(PWM)       A ~ 7 -+   +- 4   A SCL  I2C
//    I2C            SDA A ~ 6 -+   +- 5 ~ A      red    OUT(PWM)
//                              +---+

#define COLOUR_PIN A0
#define PIR_PIN    1
#define DARK_PIN   2

#define RED_PIN    5
#define GREEN_PIN  8
#define BLUE_PIN   7

#elif defined(__AVR_ATmega328P__)

// Uno
//                                      +-----+
//         +----[PWR]-------------------| USB |--+
//         |                            +-----+  |
//         |         GND/RST2  [ ][ ]            |
//         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |
//         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |
//         |                             AREF[ ] |
//         |                              GND[ ] |
//         | [ ]N/C                    SCK/13[ ] |
//         | [ ]IOREF                 MISO/12[ ] |
//         | [ ]RST                   MOSI/11[ ]~|      blue
//         | [ ]3V3    +---+               10[ ]~|      green
//         | [ ]5v    -| A |-               9[ ]~|      red
//         | [ ]GND   -| R |-               8[ ] |
//         | [ ]GND   -| D |-                    |
//         | [ ]Vin   -| U |-               7[ ] |      pir
//         |          -| I |-               6[ ]~|      light
// colour  | [ ]A0    -| N |-               5[ ]~|
//         | [ ]A1    -| O |-               4[ ] |
//         | [ ]A2     +---+           INT1/3[ ]~|
//         | [ ]A3                     INT0/2[ ] |
//         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |
//         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |
//         |            [ ] [ ] [ ]              |
//         |  UNO_R3    GND MOSI 5V  ____________/
//          \_______________________/

#define COLOUR_PIN A0
#define PIR_PIN 7
#define DARK_PIN 6

#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

#else
#error "Unable to determine pins to use"
#endif

#if defined(DEBUG) && defined(HAVE_HWSERIAL0)
#define dbg(x) Serial.println(x)
#else
#define dbg(x)
#endif

#endif //NIGHT_LIGHT_CONFIG_HPP
