/*!
 * @file Wheel_Controller.cpp
 *
 * @mainpage 
 *
 * @section intro_sec Introduction
 *
 *
 * @section dependencies Dependencies
 *
 *
 * @section author Author
 *
 * Written by Marco Romanini
 *
 * @section license License
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */
#include "Wheel_Controller.h"
#include "HardwareSerial.h"
#include <limits.h>

/***************************************************************************
 PRIVATE FUNCTIONS
 ***************************************************************************/

/**************************************************************************/
/*!
    @brief  Initializes the hardware to a default state.

    @return True if the device was successfully initialized, otherwise false.
*/
/**************************************************************************/
bool Wheel_Controller::initialize() {

  return true;
}

/***************************************************************************
 CONSTRUCTOR
 ***************************************************************************/

/**************************************************************************/
/*!
    @brief  Instantiates a new FXOS8700 class, including assigning
            a unique ID to the accel and magnetometer for logging purposes.

    @param accelSensorID The unique ID to associate with the accelerometer.
    @param magSensorID The unique ID to associate with the magnetometer.
*/
/**************************************************************************/
Wheel_Controller::Wheel_Controller() {

}

void Wheel_Controller::print(char str[]) {
    if (printer) {
        printer->print(str);
    }
}

void Wheel_Controller::println(char str[]) {
    if (printer) {
        printer->println(str);
    }
}

/***************************************************************************
 DESTRUCTOR
 ***************************************************************************/
Wheel_Controller::~Wheel_Controller() {

}

/***************************************************************************
 PUBLIC FUNCTIONS
 ***************************************************************************/

/**************************************************************************/
/*!
    @brief  Initializes the hardware.

    @param  addr I2C address for the device.
    @param  wire Pointer to Wire instance

    @return True if the device was successfully initialized, otherwise false.
*/
/**************************************************************************/
bool Wheel_Controller::begin(HardwareSerial* hwSerial) {
  printer = hwSerial;
  
  println("Wheel Controller is initialized");

  return initialize();
}

char *Wheel_Controller::execute(char *commandStr) {
    COMMAND command = COMMAND_MAP()[commandStr];
    if (!command) {
            return "ERROR: Invalid command\n";
    }
    switch (command) {
        case P10:
            println("Turning 10 points to port");
            break;
        case P5:
            println("Turning 5 points to port");
            break;
        case P1:
            println("Turning 1 point to port");
            break;
        case S1:
            println("Turning 1 point to starbord");
            break;
        case S5:
            println("Turning 5 points to starbord");
            break;
        case S10:
            println("Turning 10 points to starbord");
            break;
        case HELP:
            displayHelp();
            break;
        default:
            return "ERROR: Invalid command\n";

    }
    return "OK\n";
}

void Wheel_Controller::displayHelp() {
    println("Valid Commands for Wheel Controller are:");
    println("");
    println("\tP10\tTurn 10 points to port");
    println("\tP5\tTurn 5 points to port");
    println("\tP1\tTurn 1 point to port");
    println("\tS1\tTurn 1 point to starbord");
    println("\tS5\tTurn 5 points to starbord");
    println("\tS10\tTurn 10 points to starbord");
    println("\tHELP\tThis help screen");
}