#include <stack>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {
  }
};

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    ListNode* tmp = head;
    stack<int> tmp_stack;
    while (tmp) {
      tmp_stack.push(tmp->val);
      tmp = tmp->next;
    }
    while (head) {
      int t = tmp_stack.top();
      tmp_stack.pop();
      if (t != head->val) {
        return false;
      }
      head = head->next;
    }
    return true;
  }
};

int main(int argc, char* argv[]) {
  return 0;
}
