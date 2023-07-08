// 重建二叉树

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;

    struct TreeNode* left;

    struct TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

TreeNode* reConstructBst(vector<int>& pre, vector<int>& vin) {
    int len = pre.size();
    vector<int> pre_left;
    vector<int> pre_right;
    vector<int> vin_left;
    vector<int> vin_right;

    if (0 == len) {
        return nullptr;
    }

    TreeNode* head = new TreeNode(pre[0]);
    int root = 0;
    for (int i = 0; i < len; ++i) {
        if (pre[0] == vin[i]) {
            root = i;
            break;
        }
    }
    for (int i = 0; i < root; ++i) {
        pre_left.push_back(pre[i + 1]);
        vin_left.push_back(vin[i]);
    }
    for (int i = root + 1; i < len; ++i) {
        pre_right.push_back(pre[i]);
        vin_right.push_back(vin[i]);
    }
    head->left = reConstructBst(pre_left, vin_left);
    head->right = reConstructBst(pre_right, vin_right);
    return head;
}

int main(int argc, char* argv[]) {
    vector<int> pre = {1, 2, 3, 4, 5, 6, 7};
    vector<int> vin = {3, 2, 4, 1, 6, 5, 7};
    auto res = reConstructBst(pre, vin);
    cout << res->val << endl;
    return 0;
}
