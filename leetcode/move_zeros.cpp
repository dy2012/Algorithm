#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void MoveZeros(vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size(); ++i) {
      if (nums[i]) {
        swap(nums[i], nums[j++]);
      }
    }
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  vector<int> nums = {1, 2, 0, 3, 0, 4};
  solution.MoveZeros(nums);
  for (int num : nums) {
    cout << num << endl;
  }
  return 0;
}
