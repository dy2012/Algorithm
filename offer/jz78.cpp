// 把二叉树打印成多行

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;

    struct TreeNode* left;

    struct TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

vector<vector<int>> Print(TreeNode* root) {
    vector<vector<int>> res;
    if (nullptr == root) {
        return res;
    }
    queue<TreeNode*> que;
    que.push(root);
    vector<int> tmp;
    while (!que.empty()) {
        tmp.clear();
        int total_cnt = que.size();
        while (total_cnt--) {
            TreeNode* node = que.front();
            que.pop();
            tmp.push_back(node->val);
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        res.push_back(tmp);
    }
    return res;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;
    auto res = Print(&node1);
    for (auto it : res) {
        for (auto tmp : it) {
            cout << tmp << ",";
        }
        cout << endl;
    }
    return 0;
}
