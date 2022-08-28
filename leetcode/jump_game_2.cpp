#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
      int res = 0;
      int n = nums.size();
      int i = 0;
      int cur = 0;
      while (cur < n - 1) {
          ++res;
          int pre = cur;
          for (; i <= pre; ++i) {
              cur = max(cur, i + nums[i]);
          }
          if (pre == cur) {
              return -1;
          }
      }
      return res;
  }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << solution.jump(nums) << endl;
    return 0;
}
