// Given the head of a linked list, return the list after sorting it in ascending order.

#include <iostream>

using namespace std;

struct ListNode {
    int val;

    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode* merge(ListNode* l1, ListNode* l2);

ListNode* sortList(ListNode* head) {
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* pre;
    while (fast != nullptr && fast->next != nullptr) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;
    return merge(sortList(head), sortList(slow));
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1 != nullptr) {
        cur->next = l1;
    }
    if (l2 != nullptr) {
        cur->next = l2;
    }
    return dummy->next;
}

int main(int argc, char* argv[]) {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    node4.next = &node2;
    node2.next = &node1;
    node1.next = &node3;
    ListNode* head = sortList(&node4);
    while (head != nullptr)  {
        cout << head->val << ",";
        head = head->next;
    }
    cout << endl;
    return 0;
}
