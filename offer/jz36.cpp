#include <iostream>
#include <vector>


using namespace std;

struct TreeNode {
    int val;

    TreeNode* left;

    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
 private:
  TreeNode* tail = nullptr;

 public:
  TreeNode* Convert(TreeNode* root) {
    if (nullptr == root) {
        return nullptr;
    }
    Convert(root->right);
    if (tail != nullptr) {
        tail->left = root;
        root->right = tail;
        tail = root;
    } else {
        tail = root;
    }
    Convert(root->left);
    return tail;
  }
};

int main(int argc, char* argv[]) {
    Solution solution;
    TreeNode node1(2);
    TreeNode node2(1);
    TreeNode node3(3);
    node1.left = &node2;
    node2.right = &node3;
    auto res = solution.Convert(&node1);
    while (res != nullptr) {
        cout << res->val << ",";
        res = res->left;
    }
    cout << endl;

    return 0;
}
