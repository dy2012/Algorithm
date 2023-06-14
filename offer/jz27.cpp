// 二叉树的镜像

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;

    TreeNode* left;

    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

TreeNode* Mirror(TreeNode* pRoot) {
    if (nullptr == pRoot) {
        return nullptr;
    }
    TreeNode* p = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = p;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
    return pRoot;
}

TreeNode* Mirror2(TreeNode* pRoot) {
    if (nullptr == pRoot) {
        return nullptr;
    }
    stack<TreeNode*> st;
    st.push(pRoot);
    while (!st.empty()) {
        TreeNode* top = st.top();
        st.top();
        TreeNode* p = top->right;
        top->right = top->left;
        top->left = p;
        if (top->right != nullptr) {
            st.push(top->right);
        }
        if (top->left != nullptr) {
            st.push(top->left);
        }
    }
    return pRoot;
}

int main(int argc, char* argv[]) {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;
    TreeNode* res = Mirror(&node1);
    if (res != nullptr) {
        cout << res->val << ",";
        if (res->left != nullptr) {
            cout << res->left->val << ",";
        }
        if (res->right != nullptr) {
            cout << res->right->val << ",";
        }
    }
    cout << endl;
    return 0;
}
