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
