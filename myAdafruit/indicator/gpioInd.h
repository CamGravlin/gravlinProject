// File name: myGpio.h

#include<string>
#include<fstream>

using namespace std;

enum GPIO_DIRECTION { INPUT, OUTPUT };
enum GPIO_VALUE { LOW = 0, HIGH = 1 };

class MYGPIO {
  private:
    int number;
    string name, path;
    ofstream stream;
    void write(string path, string filename, string value);
    void write(string path, string filename, int value);
    string read(string path, string filename);

  public:
    MYGPIO(int number);
    int getNumber();
    void setDirection(GPIO_DIRECTION dir);
    GPIO_DIRECTION getDirection();
    void setValue(GPIO_VALUE val);
    GPIO_VALUE getValue();
    void toggleOutput();
    ~MYGPIO();
};
