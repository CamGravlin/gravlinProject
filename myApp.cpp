// Filename: myApp.cpp
// Application file for Record.h Reord.cpp PhoneBook.h PhoneBook.cpp

#include<iostream>
#include "PhoneBook.h"

using namespace std;

int main() {
  PhoneBook phoneBook("My PhoneBook");
  int choice;
  string name;
  int number;

do {
  cout << "\n1. Insert a name and number. \n";
  cout << "2. Get a number for a person. \n";
  cout << "3. Display phone book. \n";
  cout << "4. Remove a person from the phone book.\n";
  cout << "5. Quit.\n";
  cout << "Enter your choice: ";
  cin >> choice;

  switch (choice) {
    case 1:
      cout << "Enter name: ";
      cin >> name;
      cout << "Enter number: ";
      cin >> number;
      phoneBook.insert(name, number);
      break;
    case 2:
      cout << "Enter name: ";
      cin >> name;
      number = phoneBook.getPhoneNumber(name);
      if (number != -1) {
        cout << "Number: " << number << "\n";
      }
      break;
    case 3:
      phoneBook.displayPhoneBook();
      break;
    case 4:
      cout << "Enter name: ";
      cin >> name;
      phoneBook.removeName(name);
      break;
    case 5:
      cout << "Goodbye!\n";
      break;
    default:
      cout << "Invalid choice. Try again.\n";
      break;
    }
  } while (choice != 5);

return 0;
}
