// Filename: test_all_App.cpp

#include<iostream>
#include"makeLEDs-MOD.cpp"
#include"AnalogIn.cpp"    // AnalogIn.h is included through AnalogIn.cpp
#include"GPIO.h" 

using namespace std;
using namespace exploringBB;

float getTemperature(int adc_value) {
  float cur_voltage = adc_value * (1.80f/4096.0f);
  float diff_degreesC = (cur_voltage-0.75f)/0.01f;
  return (25.0f + diff_degreesC);
}

int main() {

// LED - uses class in makeLEDs-MOD.cpp 
  LED led1(1);
  LED led2(2);
  LED led3(3);

  led1.turnOn();
  led3.turnOn();
  led2.flash("100");

// Temperature sensor - uses class in AnalogIn.h
  AnalogIn adc(0);
  int adc_value = adc.readAdcSample();
  if (adc_value != -1) {
    cout << "The ADC value is: " << adc_value << endl;
    float temperature = getTemperature(adc_value);
    float fahrenheit = 32 + ((temperature * 9) / 5);
    cout << "Temperature is " << temperature << "­°C (" << fahrenheit << "°F)"
    << endl;
  }

// Push buttons - uses class in GPIO.h
  GPIO button(46);
  GPIO led(60);

  button.setDirection(INPUT);
  led.setDirection(OUTPUT);

  while (true) {
    if (button.getValue() == HIGH) {
      led.setValue(HIGH);
    } else {
        led.setValue(LOW);
      }
  }
return 0;
}


