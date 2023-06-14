// 二叉搜索树的第k个节点

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

void Inorder(TreeNode* root, vector<int>& res) {
    if (root != nullptr) {
        Inorder(root->left, res);
        res.push_back(root->val);
        Inorder(root->right, res);
    }
}

int KthNode(TreeNode* root, int k) {
    if (nullptr == root) {
        return -1;
    }
    vector<int> res;
    Inorder(root, res);
    if (k == 0 || k > res.size()) {
        return -1;
    }
    return res[k - 1];
}

int main(int argc, char* argv[]) {
    TreeNode node1(5);
    TreeNode node2(3);
    TreeNode node3(7);
    TreeNode node4(2);
    TreeNode node5(4);
    TreeNode node6(6);
    TreeNode node7(8);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    cout << KthNode(&node1, 2) << endl;
    return 0;
}
