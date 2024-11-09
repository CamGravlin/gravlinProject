// File name: PhoneBook.h

#include<string>
#include "Record.h"

using namespace std;

const int MAXSIZE = 100;

class PhoneBook {
  private:
    Record list[MAXSIZE];
    string bookName;
    int num_records;

    int findName(string s);   // Returns name if it exists, returns 99 if not

  public:
    PhoneBook();    // Default constructor; empty
    PhoneBook(string s);    // Constructor with parameters

    // Getters
    string getPhoneBookName();
    int getNumberofRecords();
    int getPhoneNumber(string s);

    void insert(string name, int number);   // Insert new record
    void displayPhoneBook();    // Display PhoneBook contents
    void removeName(string s);  // Remove record by name
};
