// Given the root of a binary tree, invert the tree, and return its root.

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x): val(x), left(nullptr), right(nullptr) {
  }
};

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }

    TreeNode* tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
  }

  TreeNode* invertTree2(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      TreeNode* tmp = node->left;
      node->left = node->right;
      node->right = tmp;
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
    return root;
  }
};

int main(int argc, char* argv[]) {
  TreeNode node1(1);
  TreeNode node2(2);
  TreeNode node3(3);
  node1.left = &node2;
  node1.right = &node3;
  Solution solution;
  solution.invertTree(&node1);
  return 0;
}
