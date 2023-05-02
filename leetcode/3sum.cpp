#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> TreeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) {
        return res;
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i) {
        mp[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j > (i + 1) && nums[j] == nums[j - 1]) {
                continue;
            }
            if (mp.find(-(nums[i] + nums[j])) != mp.end() &&
                    mp[-(nums[i] + nums[j])] > j) {
                res.push_back({nums[i], nums[j], -(nums[i] + nums[j])});
            }
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = TreeSum(nums);
    cout << "[";
    for (auto it : res) {
        cout << "[";
        for (auto n : it) {
            cout << n << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;
    return 0;
}

