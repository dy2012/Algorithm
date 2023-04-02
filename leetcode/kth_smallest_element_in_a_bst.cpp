// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

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

int kthSmallest(TreeNode* root, int k) {
    int cnt = 0;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while (p || !s.empty()) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        ++cnt;
        if (cnt == k) {
            return p->val;
        }
        p = p->right;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    TreeNode node1(3);
    TreeNode node2(1);
    TreeNode node3(4);
    TreeNode node4(2);
    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node4;
    cout << kthSmallest(&node1, 1) << endl;
    return 0;
}
