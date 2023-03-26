// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

#include <queue>
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

vector<vector<int>> LevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (nullptr == root) {
        return res;
    }
    queue<TreeNode*> que;
    que.push(root);
    TreeNode* front_data = nullptr;
    vector<int> tmp;
    while (!que.empty()) {
        int size = que.size();
        tmp.clear();
        for (int i = 0; i < size; ++i) {
            TreeNode* front_data = que.front();
            que.pop();
            tmp.push_back(front_data->val);
            if (front_data->left != nullptr) {
                que.push(front_data->left);
            }
            if (front_data->right != nullptr) {
                que.push(front_data->right);
            }
        }
        res.push_back(tmp);
    }
    return res;
}

vector<vector<int>> LevelOrder2(TreeNode* root) {
    vector<vector<int>> res;
    traversal(root, 0, res);
    return res;
}

void traversal(TreeNode* root, int level, vector<vector<int>>& res) {
    if (root == nullptr) {
        return;
    }
    if (res.size() == level) {
        res.push_back({});
    }
    res[level].push_back(root->val);
    if (root->left != nullptr) {
        traversal(root->left, level+1, res);
    }
    if (root->right != nullptr) {
        traversal(root->right, level+1, res);
    }
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);

    TreeNode node2(2);

    TreeNode node3(3);
    node2.left = &node1;
    node2.right = &node3;
    vector<vector<int>> res = LevelOrder(&node2);
    for (auto tmp1 : res) {
        for (auto tmp2 : tmp1) {
            cout << tmp2 << ",";
        }
        cout << endl;
    }
    return 0;

    return 0;
}
