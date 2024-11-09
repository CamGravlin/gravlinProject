// File name: hw9-pushButtonLED.cpp
// GPIO46 Direction MUST be in
// GPIO60 Direction MUST be out
// Pin P9.12 MUST be set to gpio (output)
// Pin P8.16 MUST be set to gpio_pu (pull up resistor enabled)

#include<iostream>
#include<fstream>
using namespace std;

#define GPIO46_PATH_VALUE "/sys/class/gpio/gpio46/value"
#define GPIO60_PATH_VALUE "/sys/class/gpio/gpio60/value"

int main(){
for (;;) {      // Infinite Loop
  fstream fs;
  string value;
  fs.open(GPIO46_PATH_VALUE, fstream::in);
  fs >> value;  // Sets value to either 1 or 0

  if (value == "1") {   // Writes 1 to GPIO60
    fstream fs_act;
    fs_act.open(GPIO60_PATH_VALUE, fstream::out);
    fs_act << "1";
    fs_act.close();
    }
  else {
    fstream fs_act;     // Writes 0 to GPIO60
    fs_act.open(GPIO60_PATH_VALUE, fstream::out);
    fs_act << "0";
    fs_act.close();
  }
fs.close();
}

return 0;
}
