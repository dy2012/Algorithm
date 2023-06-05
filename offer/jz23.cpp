// 链表中环的入口结点

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode* EntryNodeOfLoop(ListNode* pHead) {
    ListNode* fast = pHead;
    ListNode* slow = pHead;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            break;
        }
    }
    if (!fast || !fast->next) {
        return nullptr;
    }
    slow = pHead;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

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
    node5.next = &node3;
    ListNode* res = EntryNodeOfLoop(&node1);
    if (res != nullptr) {
        cout << "res=" << res->val << endl;
    }
    return 0;
}
