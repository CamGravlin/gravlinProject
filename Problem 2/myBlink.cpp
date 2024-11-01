/*  File name: myBlink.cpp

*/

#include<iostream>
#include "derek_LED2.h"
using namespace std;

int main(int argc, char* argv[]) {
  if(argc>3 || argc==1){
    cout << "Usage is myBlink <command>" << endl;
    cout << " command is one of: on, offm flash or status" << endl;
    cout << " e.g. myApp flash" << endl;
  }
cout << "Starting the myApp program" << endl;
string cmd(argv[1]);
LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
      for(int i=0; i<=3; i++){
        if(cmd=="on")leds[i].turnOn();
        else if(cmd=="off")leds[i].turnOff();
        else if(cmd=="flash")leds[i].flash("100");
        else if(cmd=="status")leds[i].outputState();
        else if(cmd=="blink")
      if (stoi(argv[2]) == 0)
        leds[0].blink(stoi(argv[2]));
      else if (stoi(argv[2]) == 1)
        leds[1].blink(stoi(argv[2]));
      else if (stoi(argv[2]) == 2)
        leds[2].blink(stoi(argv[2]));
      else if (stoi(argv[2]) == 3)
        leds[3].blink(stoi(argv[2]));
    else{ cout << "Invalid command!" << endl; }
  }
cout << "Finished the myBlink program" << endl;

return 0;
}
