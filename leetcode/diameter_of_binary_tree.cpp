// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

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

int maxDepth(TreeNode* root, int& res);

int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    maxDepth(root, res);
    return res;
}

int maxDepth(TreeNode* root, int& res) {
    if (root == nullptr) {
        return 0;
    }

    int left = maxDepth(root->left, res);
    int right = maxDepth(root->right, res);
    res = max(res, left + right);
    return max(left, right) + 1;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;
    cout << diameterOfBinaryTree(&node1) << endl;
    return 0;
}
