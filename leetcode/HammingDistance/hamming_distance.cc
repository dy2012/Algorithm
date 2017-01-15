#include <iostream>

class Solution {
 public:
  int hammingDistance(int x, int y) {
    int sum = x ^ y;
    unsigned int count;
    for (count = 0; sum; ++count) {
      sum = sum & (sum - 1);
    }
    return count;
  }
};

int main() {
  Solution solution;
  std::cout << "The hamming distance between 2 and 4 is "
       << solution.hammingDistance(2, 4) << std::endl;
  return 0;
}
