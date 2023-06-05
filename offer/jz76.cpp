// 删除链表中重复的结点

#include <iostream>

using namespace std;

struct ListNode {
    int val;

    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode* deleteDuplicate(ListNode* pHead) {
    if (nullptr == pHead) {
        return nullptr;
    }

    ListNode dummy(-1);
    ListNode* tail = &dummy;

    while (pHead != nullptr) {
        if (pHead->next == nullptr || pHead->val != pHead->next->val) {
            tail->next = pHead;
            tail = pHead;
        }

        while (pHead->next != nullptr && pHead->val == pHead->next->val) {
            pHead = pHead->next;
        }
        pHead = pHead->next;
    }
    tail->next = nullptr;
    return dummy.next;
}

int main(int argc, char* argv[]) {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(2);
    ListNode node4(3);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    ListNode* res = deleteDuplicate(&node1);
    while (res != nullptr) {
        cout << res->val << ",";
        res = res->next;
    }
    cout << endl;
    return 0;
}
