#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;

    ListNode* next;

    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode* p) : val(x), next(p) {
    }
};

class Solution {
 public:
  ListNode* addTwoNumber(ListNode* l1, ListNode* l2) {
      ListNode* dummy = new ListNode(-1);
      ListNode* cur = dummy;
      int carry = 0;
      while (l1 || l2) {
          int val1 = l1 ? l1->val : 0;
          int val2 = l2 ? l2->val : 0;
          int sum = val1 + val2 + carry;
          carry = sum / 10;
          cur->next = new ListNode(sum % 10);
          cur = cur->next;
          if (l1) {
              l1 = l1->next;
          }
          if (l2) {
              l2 = l2->next;
          }
      }
      if (carry) {
          cur->next = new ListNode(1);
      }
      return dummy->next;
  }
};

int main(int argc, char* argv[]) {
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;


    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(6);
    ListNode* node6 = new ListNode(4);
    node4->next = node5;
    node5->next = node6;

    Solution solution;
    auto* res = solution.addTwoNumber(node1, node4);

    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
