#!/bin/bash

echo "Turning LED on"
./led-hw4.sh on

echo "Turning LED off"
./led-hw4.sh off

echo "Reading LED stauts"
./led-hw4.sh status

echo "Flashing LED"
./led-hw4.sh flash

echo "Blinking LED 3 times"
./led-hw4.sh blink 2
