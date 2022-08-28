#include <queue>
#include <iostream>
#include <vector>

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
  int MaximumDepthOfBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(MaximumDepthOfBinaryTree(root->left), MaximumDepthOfBinaryTree(root->right));
  }

  int MaxDepath(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    int res = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        ++res;
        for (int i = q.size(); i > 0; --i) {
          TreeNode* t = q.front();
          q.pop();
          if (t->left) {
            q.push(t->left);
          }
          if (t->right) {
            q.push(t->right);
          }
        }
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  TreeNode node1(0);
  TreeNode node2(1);
  TreeNode node3(2);
  node1.left = &node2;
  node2.left = &node3;
  Solution solution;
  cout << solution.MaximumDepthOfBinaryTree(&node1) << endl;
  return 0;
}
