#include <iostream>

using namespace std;

int add(int num1, int num2) {
    int sum, carry = 0;
    do {
      sum = num1 ^ num2;
      carry = (num1 & num2) << 1;
      num1 = sum;
      num2 = carry;
    } while (num2 != 0);
    return num1;
}

int main(int argc, char* argv[]) {
    cout << add(10, 12) << endl;
    return 0;
}
