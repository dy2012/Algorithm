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
  ListNode* reverseList(ListNode* head) {
    ListNode* newHead = nullptr;
    while (head) {
      ListNode* tmp = head->next;
      head->next = newHead;
      newHead = head;
      head = tmp;
    }
    return newHead;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  ListNode node1(1);
  ListNode node2(2);
  ListNode node3(3);
  node1.next = &node2;
  node2.next = &node3;
  ListNode* res = solution.reverseList(&node1);
  while (res) {
    cout << res->val <<endl;
    res = res->next;
  }
  return 0;
}
