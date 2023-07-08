// 树的子结构

#include <iostream>

using namespace std;

struct TreeNode {
    int val;

    struct TreeNode* left;

    struct TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

bool check(TreeNode* p1, TreeNode* p2);

bool HasSubTree(TreeNode* p1, TreeNode* p2) {
    if (nullptr == p1 || nullptr == p2) {
        return false;
    }
    return check(p1, p2) || HasSubTree(p1->left, p2) || HasSubTree(p1->right, p2);
}

bool check(TreeNode* p1, TreeNode* p2) {
    if (p1 == nullptr && p2 != nullptr) {
        return false;
    }
    if (p2 == nullptr) {
        return true;
    }
    if (p1->val != p2->val) {
        return false;
    }
    return check(p1->left, p2->left) && check(p1->right, p2->right);
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    TreeNode node7(2);
    TreeNode node8(4);
    node7.left = &node8;
    cout << HasSubTree(&node1, &node7) << endl;
    return 0;
}
