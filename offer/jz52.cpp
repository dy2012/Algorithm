// 两个链表的第一个公共节点

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int a) : val(a), next(nullptr) {
    }
};

ListNode* findFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    if (nullptr == pHead1 || nullptr == pHead2) {
        return nullptr;
    }
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    while (p1 != p2) {
        p1 = (p1 == nullptr ? pHead2 : p1->next);
        p2 = (p2 == nullptr ? pHead1 : p2->next);
    }
    return p1;
}

int main(int argc, char* argv[]) {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node6;
    node4.next = &node5;
    node5.next = &node6;
    ListNode* res = findFirstCommonNode(&node1, &node4);
    while (res != nullptr) {
        cout << res->val << ",";
        res = res->next;
    }
    cout << endl;
    return 0;
}
