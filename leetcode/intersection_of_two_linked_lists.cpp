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
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    if (lenA < lenB) {
      for (int i = 0; i < (lenB - lenA); ++i) {
        headB = headB->next;
      }
    } else {
      for (int i = 0; i < (lenA - lenB); ++i) {
        headA = headA->next;
      }
    }
    while (headA != nullptr && headB != nullptr && headA != headB) {
      headA = headA->next;
      headB = headB->next;
    }
    return (headA && headB) ? headA : nullptr;
  }

  int getLength(ListNode* head) {
    int cnt = 0;
    while (head) {
      head = head->next;
      ++cnt;
    }
    return cnt;
  }
};

int main(int argc, char* argv[]) {
  ListNode node1(1);
  ListNode node2(2);
  ListNode node3(3);
  ListNode node4(4);
  ListNode node5(5);
  node1.next = &node2;
  node3.next = &node4;
  node4.next = &node2;
  node2.next = &node5;
  Solution solution;
  ListNode* tmp = solution.getIntersectionNode(&node1, &node3);
  cout << tmp->val << endl;
  return 0;
}
