// Given the root of a binary tree, return the inorder traversal of its nodes' values.


#include <stack>
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

vector<int> BinaryTreeInorderTraversal(TreeNode* root) {
    vector<int> res;
    if (nullptr == root) {
        return res;
    }
    stack<TreeNode*> s;
    TreeNode* p = root;
    while (p != nullptr || !s.empty()) {
        while (p != nullptr) {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        res.push_back(p->val);
        p = p->right;
    }
    return res;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;
    vector<int> res = BinaryTreeInorderTraversal(&node1);
    for (int tmp : res) {
        cout << tmp << ":";
    }
    cout << endl;
    return 0;
}
