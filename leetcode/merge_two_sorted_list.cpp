// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  ListNode(int in_val) : val(in_val), next(nullptr) {
  }

  ListNode() :val(0), next(nullptr) {
  }

  ListNode(int in_val, ListNode* in_next) : val(in_val), next(in_next) {
  }

  int val;

  ListNode* next;
};
class Solution {
  public:
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     ListNode* head = new ListNode(0);
     ListNode* tmp = head;
     while (l1 != nullptr && l2 != nullptr) {
       if (l1->val < l2->val) {
         tmp->next = l1;
         l1 = l1->next;
       } else {
         tmp->next = l2;
         l2 = l2->next;
       }
       tmp = tmp->next;
     }
     if (l1 != nullptr) {
       tmp->next = l1;
     } else if (l2 != nullptr) {
       tmp->next = l2;
     }
      return head->next;
   }
};

int main(int argc, char* argv[]) {
  ListNode node1(0);
  ListNode node2(1);
  ListNode node3(2);
  ListNode node4(3);
  ListNode node5(4);
  node1.next = &node2;
  node2.next= &node3;
  node4.next = &node5;
  Solution solution;
  ListNode* tmp = solution.mergeTwoLists(&node1, &node4);
  while (tmp != nullptr) {
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
