#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
 int bulb_switch(int n) {
   return (int)sqrt(n);
 }
};

int main() {
    Solution solution;
  cout << solution.bulb_switch(10) << endl;
  return 0;
}
