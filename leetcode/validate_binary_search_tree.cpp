// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// The left subtree  of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;

    TreeNode* left;

    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

bool valid(TreeNode* root, int mn, int mx) {
    if (nullptr == root) {
        return true;
    }

    if (root->val <= mn || root->val >= mx) {
        return false;
    }
    return valid(root->left, mn, root->val) && valid(root->right, root->val, mx);
}

bool IsValidBst(TreeNode* root) {
    return valid(root, INT_MIN, INT_MAX);
}

bool IsValidBst2(TreeNode* root) {
    stack<TreeNode*> stk;
    long long inorder = (long long)INT_MIN - 1;
    while (!stk.empty() || root != nullptr) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (root->val <= inorder) {
            return false;
        }
        inorder = root->val;
        root = root->right;
    }
    return true;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node2.left = &node1;
    node2.right = &node3;
    cout << IsValidBst(&node2) << endl;
    cout << IsValidBst2(&node2) << endl;
    return 0;
}
