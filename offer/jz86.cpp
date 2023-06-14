// 在二叉树中找到两个节点的最近公共祖先
//
// 键还是找到最近公共节点的特征：
//1. 如果该节点不是O1也不是O2，那么O1与O2必然分别在该节点的左子树和右子树中
//2. 如果该节点就是O1或者O2，那么另一个节点在它的左子树或右子树中
//稍微可以优化的一点就是，遇到O1或者O2节点就不往下递归了，把O1或者O2节点一层层往上传。


#include <iostream>

using namespace std;

struct TreeNode {
    int val;

    struct TreeNode* left;

    struct TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

TreeNode* dfs(TreeNode* root, int p , int q) {
    if (nullptr == root || root->val == p || root->val == q) {
        return root;
    }
    TreeNode* left = dfs(root->left, p, q);
    TreeNode* right = dfs(root->right, p, q);
    return left == nullptr ? right : (right == nullptr ? left : root);
}

int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
    TreeNode* res = dfs(root, o1, o2);
    return res->val;
}

int main(int argc, char* argv[]) {
    TreeNode node1(7);
    TreeNode node2(1);
    TreeNode node3(12);
    node1.left = &node3;
    node1.right = &node2;
    cout << lowestCommonAncestor(&node1, 1, 12) << endl;
    return 0;
}
