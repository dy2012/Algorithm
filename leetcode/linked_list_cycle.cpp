// Given head, the head of a linked list, determine if the linked list has a cycle in it.

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
  bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
          return true;
        }
    }
    return false;
  }
};

int main(int argc, char* argv[]) {
  ListNode node1(1);
  ListNode node2(2);
  ListNode node3(4);
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node1;
  Solution solution;
  cout << solution.hasCycle(&node1) << endl;
  return 0;
}
