// 二叉搜索树的最近公共祖先

#include <iostream>

using namespace std;

struct TreeNode {
    int val;

    struct TreeNode* left;

    struct TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

int lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (p < root->val && q < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (p > root->val && q > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root->val;
}

int main(int argc, char* argv[]) {
    TreeNode node1(7);
    TreeNode node2(1);
    TreeNode node3(12);
    node1.left = &node2;
    node1.right = &node3;
    cout << lowestCommonAncestor(&node1, 1, 12) << endl;
    return 0;
}
