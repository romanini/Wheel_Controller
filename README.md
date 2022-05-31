# Summary

This repository contains an example on how to receive PyPilot commands over WiFi and process them on an Arduino Nano 33 Iot

Simply extract this repo and copy the contents to your Arduino/library directory, then restart Arduino IDE and you will be 
able to see the Wheel_Controller in the Examples directory.

# Running
 
- Edit the arduino_secrets.h and add in the SSID and PW for your WiFi.
- Once uploaded to the Arduino Nano 33 Iot, view the Serial Output.  
- Wait for it to be connected to your WiFi and display the IP address it obtained
- telnet to the IP shown port 23

You may now send it commands.  To see a list of valid commands send the command "HELP".

