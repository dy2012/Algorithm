// 二叉树和为某一值的路径

#include <iostream>

using namespace std;

struct TreeNode {
    int val;

    TreeNode* left;

    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

bool dfs(TreeNode* curNode, int target);

// 时间复杂度O(N), 空间复杂度O(1)
bool hasPathSum(TreeNode* root, int sum) {
    if (nullptr == root) {
        return false;
    }
    return dfs(root, sum);
}

bool dfs(TreeNode* curNode, int target) {
    if (nullptr == curNode) {
        return false;
    }

    target -= curNode->val;
    if (curNode->left == nullptr && curNode->right == nullptr && target == 0) {
        return true;
    }
    return dfs(curNode->left, target) || dfs(curNode->right, target);
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    node1.left = &node2;
    cout << hasPathSum(&node1, 3) << endl;
    return 0;
}
