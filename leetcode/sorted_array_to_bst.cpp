#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
 int val;
 TreeNode* left;
 TreeNode* right;

 TreeNode() : val(0), left(nullptr), right(nullptr) {
 }

 TreeNode(int in_val)
     : val(in_val),
       left(nullptr),
       right(nullptr) {
 }

 TreeNode(int in_val, TreeNode* in_left, TreeNode* in_right)
     : val(in_val),
       left(in_left),
       right(in_right) {
 }
};

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) {
      return nullptr;
    }
    int mid = nums.size() / 2;
    TreeNode* cur = new TreeNode(nums[mid]);
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin() + mid + 1, nums.end());
    cur->left = sortedArrayToBST(left);
    cur->right = sortedArrayToBST(right);
    return cur;
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums{1, 2, 3, 4};
  Solution solution;
  TreeNode* head = solution.sortedArrayToBST(nums);
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->left;
  }
  cout << endl;
  return 0;
}
