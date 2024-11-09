// File name: PhoneBook.cpp

#include<iostream>
#include "PhoneBook.h"

using namespace std;

PhoneBook::PhoneBook() : num_records(0) {
}

PhoneBook::PhoneBook(string s) : bookName(s), num_records(0) {
}

string PhoneBook::getPhoneBookName() {
  return bookName;
}

int PhoneBook::getNumberofRecords() {
  return num_records;
}

void PhoneBook::insert(string name, int number) {
  if (num_records < MAXSIZE) {
    list[num_records] = Record(name, number);
    num_records++;
  } else {
      cout << "PhoneBook is full.\n";
  }
}

void PhoneBook::displayPhoneBook() {
  for (int i = 0; i < num_records; i++) {
    cout << "Name: " << list[i].getName() << ", Number: " << list[i].getNumber()
    << "\n";
  }
}

void PhoneBook::removeName(string s) {
  int index = findName(s);
  if (index != 99) {
    for (int i = index; i < num_records - 1; i++) {
      list[i] = list[i+1];
    }
    num_records--;
    cout << s << " has been removed.\n";
  } else {
    cout << "Name not found. \n";
  }
}

int PhoneBook::getPhoneNumber(string s) {
  int index = findName(s);
  if (index != 99) {
    return list[index].getNumber();
  } else {
    cout << "Name not found.\n";
    return -1;
  }
}

int PhoneBook::findName(string s) {
  for (int i = 0; i < num_records; i++) {
    if (list[i].getName() == s) {
      return i;
    }
  }

return 0;
}
