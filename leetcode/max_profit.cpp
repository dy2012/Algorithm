#include <iostream>
#include <vector>

using namespace std;

int max_profit(const vector<int>& nums) {
    if (nums.empty() || nums.size() < 2) {
        return 0;
    }

    int min = nums[0];
    int max_profit = nums[1] - min;
    for (int i = 2; i < nums.size(); ++i) {
        if (min > nums[i - 1]) {
            min = nums[i - 1];
        }
        int current_profit = nums[i] - min;
        if (current_profit > max_profit) {
            max_profit = current_profit;
        }
    }
    return max_profit;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {9, 11, 8, 5, 7, 12, 16, 14};
    cout << max_profit(nums) << endl;
    return 0;
}
