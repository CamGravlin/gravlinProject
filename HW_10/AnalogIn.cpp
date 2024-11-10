// Filename: AnalogIn.cpp


#include<iostream>
#include<sstream>
#include<fstream>
#include "AnalogIn.h"

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define ADC 0

using namespace std;

AnalogIn::AnalogIn() : number(0) {
}

AnalogIn::AnalogIn(unsigned int n) : number(n) {
}

void AnalogIn::setNumber(unsigned int n) {
  number = n;
}

int AnalogIn::readAdcSample() {
  stringstream ss;
  ss << ADC_PATH << number << "_raw";
  fstream fs;
  int adc_value;
  fs.open(ss.str().c_str(), fstream::in);
  fs >> adc_value;
  fs.close();
  return adc_value;
}

AnalogIn::~AnalogIn() {
}

