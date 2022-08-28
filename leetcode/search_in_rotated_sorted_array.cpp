#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
      int left = 0;
      int right = nums.size() - 1;
      while (left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] == target) {
              return mid;
          }

          if (nums[mid] < nums[right]) {
              if (nums[mid] < target && nums[right] >= target) {
                  left = mid + 1;
              } else {
                  right = mid - 1;
              }
          } else {
              if (nums[left] <= target && nums[mid] > target) {
                  right = mid - 1;
              } else {
                  left = mid + 1;
              }
          }
      }
      return -1;
  }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    Solution solution;
    cout << solution.search(nums, 0) << endl;
    return 0;
}
