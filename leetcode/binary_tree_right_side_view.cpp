// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;

    TreeNode* left;

    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

vector<int> RightSideView(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        res.push_back(que.back()->val);
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* tmp = que.front();
            que.pop();
            if (tmp->left != nullptr) {
                que.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                que.push(tmp->right);
            }
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node2.left = &node1;
    node2.right = &node3;
    vector<int> res = RightSideView(&node2);
    for (int tmp : res) {
        cout << tmp << ",";
    }
    cout << endl;
    return 0;
}
