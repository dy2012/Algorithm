#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
     int findKthLargest(vector<int>& nums, int k) {
         int left = 0;
         int right = nums.size() - 1;
         while (true) {
             int pos = partition(nums, left, right);
             if (pos == k - 1) {
                 return nums[pos];
             }
             if (pos > k - 1) {
                 right = pos - 1;
             } else {
                 right = pos + 1;
             }
         }
     }

     int partition(vector<int>& nums, int left, int right) {
         int pivot = nums[left];
         int l = left + 1;
         int r = right;
         while (l <= r) {
             if (nums[l] < pivot && nums[r] > pivot) {
                 swap(nums[l++], nums[r--]);
             }
             if (nums[l] >= pivot) {
                 l++;
             }
             if (nums[r] <= pivot) {
                 r--;
             }
         }
         swap(nums[left], nums[r]);
         return r;
     }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    Solution solution;
    cout << solution.findKthLargest(nums, 2) << endl;
    return 0;
}
