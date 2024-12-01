#!/bin/bash

config-pin p9.22 pwm

g++ -o slider PWM.cpp util.cpp slider.cpp -lpaho-mqtt3c
