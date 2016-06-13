#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
 int rob(TreeNode* root) {
   unordered_map<TreeNode*,int> tmp;
   return dfs(root, tmp);
 }
 int dfs(TreeNode* root, unordered_map<TreeNode*,int> &tmp) {
   if (!root) return 0;
   if (tmp.count(root)) return tmp[root];
   int val = 0;
   if (root->left) {
     val += dfs(root->left->left, tmp) + dfs(root->left->right, tmp);
   }
   if (root->right) {
     val += dfs(root->right->left, tmp) + dfs(root->right->right, tmp);
   }
   val = max(val + root->val, dfs(root->left, tmp) + dfs(root->right, tmp));
   tmp[root] = val;
   return val;
 }
};

int main() {
  TreeNode root(3);
  TreeNode left1(2);
  TreeNode right1(3);
  TreeNode right2(3);
  TreeNode right3(1);
  root.left = &left1;
  root.right = &right1;
  left1.right = &right2;
  right1.right = &right3;
  Solution solution;
  cout << solution.rob(&root) << endl;
}
