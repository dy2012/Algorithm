#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      res[i] = res[i & (i - 1)] + 1;
    }
    return res;
  }

  vector<int> countBits2(int n) {
    vector<int> res(n + 1);
    for (int i = 0; i <= n; ++i) {
      int count = 0;
      int n = i;
      while (n) {
        n = n & (n - 1);
        ++count;
      }
      res[i] = count;
    }
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  vector<int> nums = solution.countBits(10);
  for (int num : nums) {
    cout << num << endl;
  }
  return 0;
}
