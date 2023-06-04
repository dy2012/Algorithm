// 删除链表的节点

#include <iostream>

using namespace std;

struct ListNode {
    int val;

    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode* deleteNode(ListNode* head, int val) {
    if (nullptr == head) {
        return nullptr;
    }

    ListNode* pre = nullptr;
    ListNode* tmp = head;
    while (tmp != nullptr) {
        if (tmp->val != val) {
            pre = tmp;
            tmp = tmp->next;
            continue;
        }
        if (pre == nullptr) {
            return tmp->next;
        }
        pre->next = tmp->next;
        tmp = tmp->next;
    }
    return head;
}

int main(int argc, char* argv[]) {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);

    node1.next = &node2;
    node2.next = &node3;

    ListNode* res = deleteNode(&node1, 2);
    while (res != nullptr) {
        cout << res->val << ",";
        res = res->next;
    }
    cout << endl;

    return 0;
}
