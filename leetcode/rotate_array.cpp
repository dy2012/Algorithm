/z/ Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& nums, int left, int right) {
    while (left < right) {
        swap(nums[left], nums[right]);
        ++left;
        --right;
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (k > n) {
        k = k % n;
    }
    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
}

int main(int argc, char* argv[]) {
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
    for (auto it : nums) {
        cout << it << ",";
    }
    cout << endl;
    return 0;
}
