#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }

  TreeNode(int in_val,TreeNode* in_left, TreeNode* in_right)
      : val(in_val),
        left(in_left),
        right(in_right) {
  }

  TreeNode(int in_val) : val(in_val), left(nullptr), right(nullptr) {
  }
};

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    TreeNode* p = root;
    stack<TreeNode*> s;
    while (p || !s.empty()) {
      if (p) {
        s.push(p);
        p = p->left;
      } else {
        p = s.top();
        s.pop();
        res.push_back(p->val);
        p = p->right;
      }
    }
    return res;
  }

  vector<int> inorderTraversal2(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
  }

  void inorder(TreeNode* root, vector<int>& res) {
    if (!root) {
      return;
    }
    if (root->left) {
      inorder(root->left, res);
    }
    res.push_back(root->val);
    if (root->right) {
      inorder(root->right, res);
    }
  }
};

int main(int argc, char* argv[]) {
  TreeNode node1(0);
  TreeNode node2(2);
  TreeNode node3(3);
  node1.left = &node2;
  node2.right = &node3;
  Solution solution;
  vector<int> tmp = solution.inorderTraversal(&node1);
  for (int val : tmp) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
