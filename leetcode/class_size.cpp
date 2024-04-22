#include <iostream>

using namespace std;

class McQ {
 private:
  McQ() {
  }

  virtual ~McQ() {
  }
};

int main(int argc, char* argv[]) {
    cout << sizeof(McQ) << endl;
    return 0;
}
