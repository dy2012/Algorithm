#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int ClimbStairs(int n) {
    if (n < 2) {
      return n;
    }

    vector<int> nums(n, 0);
    nums[0] = 1;
    nums[1] = 2;
    for (int i = 2; i < n; ++i) {
      nums[i] = nums[i - 1] + nums[i - 2];
    }
    return nums[n - 1];
  }
};

int main(int argc, char* argv[]) {
    Solution solution;
    cout << solution.ClimbStairs(10) << endl;
    return 0;
}
