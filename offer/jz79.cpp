// 判断是不是平衡二叉树

#include <iostream>

using namespace std;

struct TreeNode {
    int val;

    struct TreeNode* left;

    struct TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

int Depth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int left = Depth(root->left);
    int right = Depth(root->right);
    return 1 + max(left, right);
}

bool IsSym(TreeNode* root) {
    if (nullptr == root) {
        return true;
    }

    int left = Depth(root->left);
    int right = Depth(root->right);

    if (abs(left - right) > 1) {
        return false;
    }

    return IsSym(root->left) && IsSym(root->right);
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    cout << IsSym(&node1) << endl;
    node1.left = &node2;
    node1.right = &node3;
    cout << IsSym(&node1) << endl;
    return 0;
}
