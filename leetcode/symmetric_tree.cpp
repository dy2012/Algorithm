#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;

    TreeNode* left;

    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};
bool dfs(TreeNode* l, TreeNode* r);

bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    return dfs(root->left, root->right);
}

bool dfs(TreeNode* l, TreeNode* r) {
    if (l == nullptr && r == nullptr) {
        return true;
    }

    if (l == nullptr || r == nullptr) {
        return false;
    }

    if (l->val != r->val) {
        return false;
    }
    return dfs(l->right, r->left) && dfs(l->left, r->right);
}

bool newSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    queue<TreeNode*> que;
    que.push(root->left);
    que.push(root->right);
    while (!que.empty()) {
        TreeNode* x1 = que.front();
        que.pop();
        TreeNode* x2 = que.front();
        que.pop();
        if (x1 == nullptr && x2 == nullptr) {
            continue;
        }
        if (x1 == nullptr || x2 == nullptr) {
            return false;
        }
        if (x1->val != x2->val) {
            return false;
        }
        que.push(x1->left);
        que.push(x2->right);
        que.push(x1->right);
        que.push(x2->left);
    }
    return true;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(2);
    node1.left = &node2;
    node1.right = &node3;
    cout << isSymmetric(&node1) << endl;
    cout << newSymmetric(&node1) << endl;
    return 0;
}
