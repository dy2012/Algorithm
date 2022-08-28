#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int MaxSubarray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    int local = nums[0];
    int global = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      local = max(local + nums[i], nums[i]);
      global = max(global, local);
    }
    return global;
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums = {1, 2, -3, 4, 5, -3, 2, 10};
  Solution solution;
  cout << solution.MaxSubarray(nums) << endl;
  return 0;
}
