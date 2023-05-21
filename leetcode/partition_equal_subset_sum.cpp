#include <vector>
#include <iostream>

using namespace std;

bool PartitionEqualSubsetSum(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int x : nums) {
        sum += x;
    }
    if ((sum & 1) == 1) {
        return false;
    }
    int target = sum / 2;
    vector<vector<bool>> dp(n, vector<bool>(target + 1));
    if (nums[0] < target) {
        dp[0][nums[0]] = true;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (nums[i] == j) {
                dp[i][j] = true;
                continue;
            }
            if (nums[i] < j) {
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                continue;
            }
        }
        if (dp[i][target]) {
            return true;
        }
    }
    return dp[n - 1][target];
}

int main(int argc, char* argv[]) {
    vector<int> nums1{1, 5, 11, 5};
    cout << PartitionEqualSubsetSum(nums1) << endl;
    vector<int> nums2{1, 2, 3, 5};
    cout << PartitionEqualSubsetSum(nums2) << endl;
    return 0;
}
