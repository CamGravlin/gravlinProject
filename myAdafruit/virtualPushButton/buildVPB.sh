#!/bin/bash

config-pin p9.22 gpio
echo out > /sys/class/gpio/gpio2/direction
echo "Setting gpio2 direction to out"

g++ virtualPushButton.cpp -o virtualPushButton -lpaho-mqtt3c

