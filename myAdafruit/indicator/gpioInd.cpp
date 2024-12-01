// File name: myGpio.cpp

#include<string>
#include<fstream>
#include<iostream>
#include<unistd.h>
#include "gpioInd.h"

using namespace std;


MYGPIO::MYGPIO(int number) : number(number) {
  path = "/sys/class/gpio/gpio" + to_string(number) + "/";
  write("/sys/class/gpio/", "export", number);
  usleep(100000);
}


void MYGPIO::write(string path, string filename, string value) {
  ofstream file(path + filename);
  file << value;
  file.close();
}

void MYGPIO::write(string path, string filename, int value) {
  write(path, filename, to_string(value));
}

string MYGPIO::read(string path, string filename) {
  ifstream file(path + filename);
  string value;
  file >> value;
  file.close();
  return value;
}

void MYGPIO::setDirection(GPIO_DIRECTION dir) {
  if (dir == INPUT) {
    write(path, "direction", "in");
  } else {
    write(path, "direction", "out");
  }
}

GPIO_DIRECTION MYGPIO::getDirection() {
  string direction = read(path, "direction");
  return (direction == "in") ? INPUT : OUTPUT;
}

void MYGPIO::setValue(GPIO_VALUE val) {
  write(path, "value", val);
}

GPIO_VALUE MYGPIO::getValue() {
  int value = stoi(read(path, "value"));
  return (value == 0) ? LOW : HIGH;
}

void MYGPIO::toggleOutput() {
  if (getDirection() == OUTPUT) {
    setValue(getValue() == LOW ? HIGH : LOW);
  }
}

MYGPIO::~MYGPIO() {
  write("/sys/class/gpio/", "unexport", number);
}


