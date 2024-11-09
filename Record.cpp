// File name: Record.cpp


#include "Record.h"

using namespace std;

Record::Record() {
}

Record::Record(string name, int number) : name(name), number(number) {
}

string Record::getName() {
  return name;
}

int Record::getNumber() {
  return number;
}

void Record::setName(string s) {
  name = s;
}

void Record::setNumber(int n) {
  number = n;
}

Record::~Record(){
}
