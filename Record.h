// File name: Record.h

#include <string>

using namespace std;

class Record {
  private:
    string name;
    int number;

  public:
    Record();   // Default constructor; empty
    Record(string name, int number);  //Constructor with parameters

    // Getters
    string getName();
    int getNumber();

    // Setters
    void setName(string s);
    void setNumber(int n);

    ~Record();    // Deconstructor
};
