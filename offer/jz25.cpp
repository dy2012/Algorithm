// 合并两个排序的链表

#include <iostream>

using namespace std;

struct ListNode {
    int val;

    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode* recurseMerge(ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == nullptr || pHead2 == nullptr) {
        return pHead1 == nullptr ? pHead2 : pHead1;
    }
    if (pHead1->val <= pHead2->val) {
        pHead1->next = recurseMerge(pHead1->next, pHead2);
        return pHead1;
    } else {
        pHead2->next = recurseMerge(pHead1, pHead2->next);
        return pHead2;
    }
}

ListNode* merge(ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == nullptr || pHead2 == nullptr) {
        return pHead1 == nullptr ? pHead2 : pHead1;
    }

    ListNode dummy(-1);
    ListNode* cur = new ListNode(0);
    dummy.next = cur;
    while (pHead1 != nullptr && pHead2 != nullptr) {
        if (pHead1->val < pHead2->val) {
            cur->next = pHead1;
            pHead1 = pHead1->next;
        } else {
            cur->next = pHead2;
            pHead2 = pHead2->next;
        }
        cur = cur->next;
    }

    while (pHead1 != nullptr) {
        cur->next = pHead1;
        cur = cur->next;
        pHead1 = pHead1->next;
    }
    while (pHead2 != nullptr) {
        cur->next = pHead2;
        cur = cur->next;
        pHead2 = pHead2->next;
    }
    return dummy.next->next;
}

int main(int argc, char* argv[]) {
    ListNode node1(1);
    ListNode node3(3);
    ListNode node5(5);

    node1.next = &node3;
    node3.next = &node5;

    ListNode node2(2);
    ListNode node4(4);
    ListNode node6(6);
    
    node2.next = &node4;
    node4.next = &node6;

    ListNode* tmp = recurseMerge(&node1, &node2);
    while (tmp != nullptr) {
        cout << tmp->val << ",";
        tmp = tmp->next;
    }
    cout << endl;
    return 0;
    return 0;
}
