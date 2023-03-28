// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

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

TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (nullptr == root) {
        return nullptr;
    }
    if (root == p || root == q) {
        return root;
    }
    TreeNode* left = LowestCommonAncestor(root->left, p, q);
    TreeNode* right = LowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr) {
        return root;
    }
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }
    return root;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node2.left = &node1;
    node2.right = &node3;
    TreeNode* res = LowestCommonAncestor(&node2, &node1, &node3);
    if (res == nullptr) {
        cout << "res is nullptr" << endl;
        return 0;
    }
    cout << res->val << endl;
    return 0;
}
