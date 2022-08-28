#include <deque>
#include <iostream>

using namespace std;

struct BinaryTreeNode {
  int val;

  BinaryTreeNode* left;

  BinaryTreeNode* right;

  BinaryTreeNode(int tmp_val) : val(tmp_val) {
  }
};

void PrintTreeFromTopToBottom(BinaryTreeNode* root) {
  if (!root) {
    return;
  }
  
  deque<BinaryTreeNode*> node_que;
  node_que.push_back(root);
  while (!node_que.empty()) {
    auto* node = node_que.front();
    node_que.pop_front();
    cout << node->val << endl;
    if (node->left != nullptr) {
      node_que.push_back(node->left);
    }
    if (node->right != nullptr) {
      node_que.push_back(node->right);
    }
  }
}

int main(int argc, char* argv[]) {
  BinaryTreeNode tmp_node(1);
  tmp_node.left = new BinaryTreeNode(2);
  tmp_node.right = new BinaryTreeNode(3);
  PrintTreeFromTopToBottom(&tmp_node);
  return 0;
}
