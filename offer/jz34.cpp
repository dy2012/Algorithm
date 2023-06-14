// 带有记忆的DFS

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

void dfs(TreeNode* root, int s, vector<vector<int>>& res, vector<int>& path) {
    path.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
        if (s == root->val) {
            res.push_back(path);
        }
    }
    if (root->left) {
        dfs(root->left, s - root->val, res, path);
    }

    if (root->right) {
        dfs(root->right, s - root->val, res, path);
    }
    path.pop_back();
}

vector<vector<int>> FindPath(TreeNode* root, int target) {
    vector<vector<int>> res;
    vector<int> path;
    if (root != nullptr) {
        dfs(root, target, res, path);
    }
    return res;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);

    TreeNode node2(2);

    node1.left = &node2;

    vector<vector<int>> res = FindPath(&node1, 3);
    for (auto itor : res) {
        for (auto it : itor) {
            cout << it << ",";
        }
        cout << endl;
    }
    return 0;
}
