#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {
  }

  Node(int value) : val(value) {
  }
  Node(int value, vector<Node*> children_vec)
      : val(value), children(children_vec) {
  }
};

class Solution {
 public:
  vector<int> preorder(Node* root) {
      if (root != nullptr) {
          res.push_back(root->val);
          for (auto* iter : root->children) {
              preorder(iter);
          }
      }
      return res;
  }

  vector<int> preorder2(Node* root) {
      if (root == nullptr) return res;
      stack<Node*> tmp;
      tmp.push(root);
      while (!tmp.empty()) {
          Node* tmp_top = tmp.top();
          tmp.pop();
          for (int i = tmp_top->children.size() - 1; i >= 0; --i) {
            tmp.push(tmp_top->children[i]);
          }
          res.push_back(tmp_top->val);
      }
      return res;
  }
  vector<int> res;
};
int main() {
    Node node1(1);
    Node node2(3);
    Node node3(2);
    Node node4(4);
    Node node5(5);
    Node node6(6);
    node1.children.push_back(&node2);
    node1.children.push_back(&node3);
    node1.children.push_back(&node4);
    node2.children.push_back(&node5);
    node2.children.push_back(&node6);
    Solution solution;
    vector<int> res = solution.preorder2(&node1);
    for (auto it : res) {
        cout << it << endl;
    }
    return 0;
}

