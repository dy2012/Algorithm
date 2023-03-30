// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    if (nullptr == fast || nullptr == fast->next) {
        return nullptr;
    }
    slow = head;
    while (slow != head) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

int main(int argc, char* argv[]) {
    ListNode node1(3);
    ListNode node2(2);
    ListNode node3(0);
    ListNode node4(-4);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2;
    ListNode* res = detectCycle(&node1);
    cout << "the entrance of cycle:" << res->val <<endl;
    return 0;
}
