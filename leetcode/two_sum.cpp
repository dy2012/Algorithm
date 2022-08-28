#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> TwoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mid_res;
        for (int i = 0; i < nums.size(); ++i) {
            mid_res[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int tmp = target - nums[i];
            auto iter = mid_res.find(tmp);
            if (iter != mid_res.end() && iter->second != i) {
                res.push_back(i);
                res.push_back(iter->second);
                break;
            }
        }
        return res;
    }

    vector<int> TwoSumOptimize(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mid_res;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = target - nums[i];
            auto iter = mid_res.find(tmp);
            if (iter != mid_res.end()) {
                res.push_back(iter->second);
                res.push_back(i);
                break;
            }
            mid_res[nums[i]] = i;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 2, 3, 6, 9, 8};
    Solution solution;
    vector<int> res = solution.TwoSum(nums, 10);
    for (auto tmp : res) {
        cout << tmp << " ";
    }
    cout << endl;
    vector<int> res2 = solution.TwoSumOptimize(nums, 10);
    for (auto tmp : res2) {
        cout << tmp << " ";
    }
    cout << endl;
    return 0;
}

