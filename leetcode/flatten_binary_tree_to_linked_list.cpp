// Given the root of a binary tree, flatten the tree into a "linked list":
// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

#include <iostream>

using namespace std;


struct TreeNode {
    int val;

    TreeNode* left;

    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

void flatten(TreeNode* root) {
    if (root != nullptr) {
        return;
    }
    if (root->left != nullptr) {
        flatten(root->left);
    }

    if (root->right != nullptr) {
        flatten(root->right);
    }
    TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (root->right) {
        root = root->right;
    }
    root->right = tmp;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node2.left = &node1;
    node2.right = &node3;
    flatten(&node2);
    return 0;
}
