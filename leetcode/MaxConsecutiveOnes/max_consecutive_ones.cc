#include <iostream>
#include <vector>

class Solution {
 public:
  int findMaxConsecutiveOnes(std::vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    if (nums.size() == 1) {
      return nums[0];
    }

    int max_seq = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i - 1]) {
        if (count == 0) {
          count = 1;
        }
        if (count > max_seq) {
          max_seq = count;
        }
        if (nums[i]) {
          ++count;
        } else {
          count = 0;
        }
        if (count > max_seq) {
          max_seq = count;
        }
      } else {
        if (nums[i]) {
          count = 1;
        }
        if (count > max_seq) {
          max_seq = count;
        }
      }
    }
    return max_seq;
  }
};

int main() {
  std::vector<int> nums{1, 1, 0, 0, 1, 1, 1};
  Solution solution;
  std::cout << "Max Consecutive Ones is "
      << solution.findMaxConsecutiveOnes(nums) << std::endl;
}
