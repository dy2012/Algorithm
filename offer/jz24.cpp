// 反转单链表

#include <iostream>

using namespace std;

struct ListNode {
    int val;

    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode* reverseList(ListNode* pHead) {
    if (nullptr == pHead) {
        return nullptr;
    }

    ListNode* pre = nullptr;
    while (pHead != nullptr) {
        ListNode* next = pHead->next;
        pHead->next = pre;
        pre = pHead;
        pHead = next;
    }
    return pre;
}

int main(int argc, char* argv[]) {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;
    ListNode* res = reverseList(&node1);
    while (res != nullptr) {
        cout << res->val << ",";
        res = res->next;
    }
    cout << endl;
    return 0;
}
