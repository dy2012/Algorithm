// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) {
      return res;
    }

    sort(nums.begin(), nums.end());
    unordered_map<int, int> tmp;
    for (int i = 0; i < nums.size(); ++i) {
      tmp[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      for (int j = i + 1; j < nums.size(); ++j) {
        if (j > (i + 1) && nums[j] == nums[j - 1]) {
          continue;
        }

        if (tmp.find(-(nums[i] + nums[j])) != tmp.end() &&
            tmp[-(nums[i] + nums[j])] > j) {
          res.push_back({nums[i], nums[j], -(nums[i] + nums[j])});
        }
      }
    }
    return res;
  }

  vector<vector<int>> threeSum2(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int first = 0; first < n; first++) {
      if (first > 0 && nums[first] == nums[first - 1]) {
        continue;
      }
      int third = n - 1;
      int target = -nums[first];
      for (int second = first + 1; second < n; second++) {
        if (second > first + 1 && nums[second] == nums[second - 1]) {
          continue;
        }
        while (second < third && nums[second] + nums[third] > target) {
          --third;
        }
        if (second == third) {
          break;
        }
        if (nums[second] + nums[third] == target) {
          ans.push_back({nums[first], nums[second], nums[third]});
        }
      }
    }
    return ans;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  auto res = solution.threeSum(nums);
  for (int i = 0; i < res.size(); ++i)  {
    for (int j = 0; j < res[i].size(); ++j) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
