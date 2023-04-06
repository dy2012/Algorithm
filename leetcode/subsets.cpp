// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> res(1);
    if (nums.empty()) {
        return res;
    }
    for (int i = 0; i < nums.size(); ++i) {
        int size = res.size();
        for (int j = 0; j < size; ++j) {
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    for (auto it : res) {
        for (auto ot : it) {
            cout << ot << ",";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
