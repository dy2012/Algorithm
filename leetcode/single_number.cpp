// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int SingleNumber(vector<int>& nums) {
    int res = 0;
    for (int num : nums) {
      res ^= num;
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  vector<int> nums = {2, 2, 1};
  cout << solution.SingleNumber(nums) << endl;
  return 0;
}
