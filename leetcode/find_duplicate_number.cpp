#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int left = 1;
            int right = nums.size();
            while (left < right)  {
                int mid = left + (right - left) / 2;
                int cnt = 0 ;
                for (int num : nums) {
                    if (num <= mid) {
                        ++cnt;
                    }
                }
                if (cnt <= mid) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return right;
        }
};


int main(int argc, char* argv[]) {
    vector<int> nums = {1, 3, 4, 2, 2};
    Solution solution;
    cout << solution.findDuplicate(nums) << endl;
    return 0;
}
