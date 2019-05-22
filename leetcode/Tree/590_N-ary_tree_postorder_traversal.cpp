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
  vector<int> postorder(Node* root) {
    if (root != nullptr) {
      for (auto iter : root->children) {
          postorder(iter);
      }
      res.push_back(root->val);
    }
    return res;
  }

  vector<int> postorder2(Node* root) {
      if (root == nullptr) {
        return res;
      }

      stack<Node*> tmp;
      tmp.push(root);
      while (!tmp.empty()) {
          Node* top = tmp.top();
          tmp.pop();
          for (int i = 0; i < top->children.size() ; ++i) {
              tmp.push(top->children[i]);
          }
          res.push_back(top->val);
      }
      reverse(res.begin(), res.end());
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
  vector<int> res = solution.postorder2(&node1);
  for (auto it : res) {
      cout << it << endl;
  }
  return 0;
}

