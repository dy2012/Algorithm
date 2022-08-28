#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return vector<int>{-1, -1};
        }
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + right >> 1;
            cout << mid << endl;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (nums[left] != target) {
            return vector<int>{-1, -1};
        }
        int l = left;
        right = nums.size() - 1;
        while (left < right) {
            int mid = left + right + 1 >> 1;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return vector<int>{l, left};
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 2, 2, 3, 4};
    Solution solution;
    vector<int> res = solution.searchRange(nums, 2);
    for (int num : res) {
        cout << num << ",";
    }
    cout << endl;
    return 0;
}
