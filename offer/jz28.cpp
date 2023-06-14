// 对称的二叉树

#include <iostream>

using namespace std;

struct TreeNode {
    int val;

    struct TreeNode* left;

    struct TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

bool isSame(TreeNode* p1, TreeNode* p2) {
    if (p1 == nullptr && p2 != nullptr) {
        return false;
    }

    if (p1 != nullptr && p2 == nullptr) {
        return false;
    }

    if (p1 == nullptr && p2 == nullptr) {
        return true;
    }

    if (p1->val == p2->val) {
        return isSame(p1->left, p2->right) && isSame(p1->right, p2->left);
    } else {
        return false;
    }
}

bool isSymmetrical(TreeNode* pRoot) {
    if (nullptr == pRoot) {
        return true;
    }
    return isSame(pRoot->left, pRoot->right);
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(2);
    node1.left = &node2;
    node1.right = &node3;
    cout << isSymmetrical(&node1) << endl;
    return 0;
}
