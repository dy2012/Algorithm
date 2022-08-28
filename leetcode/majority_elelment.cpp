#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int> nums) {
    int res = 0;
    int cnt = 0;
    for (int num : nums) {
      if (cnt == 0) {
        res = num;
        ++cnt;
      } else if (res == num) {
        ++cnt;
      } else {
        --cnt;
      }
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  vector<int> nums = {1,1,1,1,2};
  cout << solution.majorityElement(nums) << endl;
  return 0;
}
