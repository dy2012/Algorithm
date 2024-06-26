#include <iostream>
#include <stack>
#include <utility>
#include <functional>

using namespace std;

struct TreeNode {
    int val;

    TreeNode* left;

    TreeNode* right;

    TreeNode(int val) : left(nullptr), right(nullptr) {
    }
};

vector<int> inorder(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    stack<pair<TreeNode*, int>> stk;
    stk.push(make_pair(root, 0));
    while (!stk.empty()) {
        auto [node, type] = stk.top();
        stk.pop();
        if (nullptr == node) {
            continue;
        }
        if (type == 0) {
            stk.push(make_pair(node->right, 0));
            stk.push(make_pair(node, 1));
            stk.push(make_pair(node->left, 0));
        } else {
            res.push_back(node->val);
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    return 0;
}
