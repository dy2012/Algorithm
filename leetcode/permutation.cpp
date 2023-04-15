// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    res.push_back(nums);
    while (next_permutation(nums.begin(), nums.end())) {
        res.push_back(nums);
    }
    return res;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = permute(nums);
    for (auto it : res) {
        for (auto tmp : it) {
            cout << tmp << ",";
        }
        cout << endl;
    }
    return 0;
}
