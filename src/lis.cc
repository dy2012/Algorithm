#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> nums) {
  int len = 1;
  vector<int> res(nums.size());
  for (int i = 0; i < nums.size(); ++i) {
    res[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (nums[j] <= nums[i] && res[j] + 1 > res[i]) {
        res[i] = res[j] + 1;
      }
    }
    if (res[i] > len) {
      len = res[i];
    }
  }

  return len;
}

int main() {
  vector<int> nums = {5, 3, 4, 8, 6, 7};
  cout << lis(nums) << endl;
  return 0;
}
