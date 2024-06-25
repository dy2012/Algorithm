#include <iostream>
#include <vector>

using namespace std;


bool IsContinuous(vector<int>& nums) {
    int len = nums.size();
    int zero_num = 0;
    sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
            return a < b;
            });
    for (int i = 0; i < len && nums[i] == 0; ++i) {
        ++zero_num;
    }
    int gap = 0;
    int small = zero_num;
    int big = small + 1;
    while (big < len) {
        if (nums[small] == nums[big]) {
            return false;
        }
        gap += nums[big] - nums[small] - 1;
        small = big;
        ++big;
    }
    return gap <= zero_num ? true : false;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {0, 3, 2, 4};
    cout << IsContinuous(nums) << endl;
    vector<int> nums2 = {0, 3, 2, 9};
    cout << IsContinuous(nums2) << endl;
    return 0;
}
