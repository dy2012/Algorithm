// 按之字形顺序打印二叉树

#include <iostream>
#include <queue>
#include <stack>
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
    queue<TreeNode*> q;
    stack<TreeNode*> st;
    st.push(root);
    int dir = 1;
    vector<int> v;
    while (!st.empty()) {
        int size = st.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* cur = st.top();
            st.pop();
            v.push_back(cur->val);
            TreeNode* first = (dir == 1) ? cur->left : cur->right;
            TreeNode* second = (dir == 1) ? cur->right : cur->left;
            if (first) {
                q.push(first);
            }
            if (second) {
                q.push(second);
            }
        }
        res.push_back(v);
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        dir = (dir == 1) ? 2 : 1;
        v.clear();
    }
    return res;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;

    auto res = Print(&node1);
    for (auto it : res) {
        for (auto num : it) {
            cout << num << ",";
        }
        cout << endl;
    }

    return 0;
}
