/*!
 * @file Wheel_Controller.h
 *
 *
 * Written by Marco Romanini
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */
/** \file Wheel_Controller.h */
#ifndef __WHEEL_CONTROLLER_H__
#define __WHEEL_CONTROLLER_H__

#include <Arduino.h>
#include <map>
#include <string>

enum COMMAND { P10, P5, P1, S1, S5, S10, HELP };

// String switch paridgam   
struct COMMAND_MAP : public std::map<std::string, COMMAND>
{
    COMMAND_MAP()
    {
        this->operator[]("P10") =  P10;
        this->operator[]("P5") =  P5;
        this->operator[]("P1") =  P1;
        this->operator[]("S1") =  S1;
        this->operator[]("S5") =  S5;
        this->operator[]("S10") =  S10;
        this->operator[]("HELP") =  HELP;
    };
    ~COMMAND_MAP(){}
};

/**************************************************************************/
/*!
    @brief  Unified sensor driver for the Adafruit FXOS8700 breakout.
*/
/**************************************************************************/
class Wheel_Controller {
public:
  Wheel_Controller();
  ~Wheel_Controller();
  bool begin(HardwareSerial* hwSerial);
  char *execute(char *commandStr);

private:
  bool initialize();
  void print(char str[]);
  void println(char str[]);
  void displayHelp();

  HardwareSerial* printer;
};

#endif
