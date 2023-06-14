// 二叉树的深度


#include <iostream>

using namespace std;

struct TreeNode {
    int val;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

int TreeDepth(TreeNode* pRoot) {
    if (nullptr == pRoot) {
        return 0;
    }
    return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    cout << "maxDepth=" << TreeDepth(&node1) << endl;
    return 0;
}
