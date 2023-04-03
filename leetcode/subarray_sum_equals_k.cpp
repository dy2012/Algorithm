// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(const vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int res = 0;
    int sum = 0;
    mp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (mp.count(sum - k)) {
            res += mp[sum - k];
        }
        mp[sum]++;
    }
    return res;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 1, 1};
    cout << subarraySum(nums, 2) << endl;
    return 0;
}
