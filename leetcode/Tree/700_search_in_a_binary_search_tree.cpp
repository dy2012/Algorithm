// According to leetcode.

#include <iostream>

using namespace std;

typedef struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int value) : val(value), left(nullptr), right(nullptr) {
  }
} TreeNode;

class Solution {
 public:
  TreeNode* SearchBST(TreeNode* root, int val) {
    if (root == nullptr) {
      return nullptr;
    }

    TreeNode* res;
    if (root->val > val) {
      res = SearchBST(root->left, val);
    } else if (root->val < val) {
      res = SearchBST(root->right, val);
    } else {
      return root;
    }
    return res;
  }
};

int main() {
  TreeNode node1(4);
  TreeNode node2(2);
  TreeNode node3(7);
  TreeNode node4(1);
  TreeNode node5(3);
  node1.left = &node2;
  node1.right = &node3;
  node2.left = &node4;
  node2.right = &node5;
  Solution solution;
  auto* res = solution.SearchBST(&node1, 3);
  if (res == nullptr) {
    cout << "can't find it" << endl;
  } else {
    cout << "find it, value is " << res->val << endl;;
  }
  return 0;
}
