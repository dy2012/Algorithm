#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* fast = head;
    ListNode* slow = head;
    for (int i = 0; i < k - 1; ++i) {
        fast = fast->next;
    }
    ListNode* right = fast;
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    swap(right->val, slow->val);
    return head;
}

int main(int argc, char* argv[]) {
    ListNode node1(1);
    ListNode node2(2);
    node1.next = &node2;
    ListNode* res = swapNodes(&node1, 1);
    while (res != nullptr) {
        cout << res->val << ",";
        res = res->next;
    }
    cout << endl;
    return 0;
}
