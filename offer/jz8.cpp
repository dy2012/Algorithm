// 二叉树的下一个节点

#include <iostream>

using namespace std;

struct  TreeLinkNode {
    int val;

    struct TreeLinkNode* left;

    struct TreeLinkNode* right;

    struct TreeLinkNode* next;

    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {
    }
};

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    if (pNode->next == nullptr && pNode->left == nullptr && pNode->right == nullptr) {
        return nullptr;
    }
    TreeLinkNode* p = pNode;
    if (p->right) {
        p = p->right;
        while (p->left) {
            p = p->left;
        }
        return p;
    } else if (!p->next) {
        return nullptr;
    } else {
        while (p->next && p->next->right == p) {
            p = p->next;
        }
        if (!p->next) {
            return nullptr;
        }
        return p->next;
    }
}

int main(int argc, char* argv[]) {
    TreeLinkNode node1(5);
    auto res = GetNext(&node1);
    if (res == nullptr) {
        cout << "Nullptr" << endl;
    }
    return 0;
}
