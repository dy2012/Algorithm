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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head->next == nullptr) {
      return nullptr;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }
    if (!fast) {
      return head->next;
    }
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
  }
};

int main(int argc, char* argv[]) {
  ListNode node1(1);
  ListNode node2(2);
  ListNode node3(3);
  ListNode node4(4);
  ListNode node5(5);
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;
  Solution solution;
  auto* res = solution.removeNthFromEnd(&node1, 2);
  while (res != nullptr) {
    cout << res->val << " ";
    res = res->next;
  }
  cout << endl;
  return 0;
}
