// File name: test_analog.cpp


#include<iostream>
#include "AnalogIn.h"

using namespace std;

float getTemperature(int adc_value) {
  float cur_voltage = adc_value * (1.80f/4096.0f);
  float diff_degreesC = (cur_voltage-0.75f)/0.01f;
  return (25.0f + diff_degreesC);
}

int main(){
  AnalogIn adc(0);
  int adc_value = adc.readAdcSample();
  if (adc_value != -1) {
    cout << "The ADC value is: " << adc_value << endl;
    float temperature = getTemperature(adc_value);
    float fahrenheit = 32 + ((temperature * 9) / 5);
    cout << "Temperature is " << temperature << "°C (" << fahrenheit << "°F)" <<
    endl;
  }
  return 0;
}
