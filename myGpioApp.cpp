// File name: myGpioApp.cpp

#include<iostream>
#include<unistd.h>
#include "myGpio.h"

int main() {
  
  MYGPIO gpioOut(60);
  gpioOut.setDirection(OUTPUT);

  gpioOut.setValue(HIGH);
  cout << "P9.12 (GPIO 60) set to HIGH. Value: " << gpioOut.getValue() << endl;
  sleep(3);
  gpioOut.setValue(LOW);
  cout << "P9.12 (GPIO 60) set to LOW. Value: " << gpioOut.getValue() << endl;

  MYGPIO gpioIn(46);
  gpioIn.setDirection(INPUT);
  cout << "P8.16 (GPIO 46) value is: " << gpioIn.getValue() << endl;

  return 0;
}
