#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;

    TreeNode* left;

    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {
    }
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if (root != nullptr) {
        que.push(root);
    }
    while (!que.empty()) {
        int n = que.size();
        vector<int> level;
        for (int i =0 ; i < n; ++i) {
            TreeNode* tmp = que.front();
            que.pop();
            level.push_back(tmp->val);
            if (tmp->left != nullptr) {
                que.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                que.push(tmp->right);
            }
        }
        res.push_back(level);
    }
    return res;
}

int main(int argc, char* argv[]) {
    return 0;
}
