// 203

#include <iostream>

using namespace std;

struct ListNode {
    int val;

    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* pre = dummy;
    while (head != nullptr) {
        ListNode* next = head->next;
        if (head->val == val) {
            cout << val << endl;
            cout << "pre:" << pre->val << endl;
            pre->next = next;
        } else {
            pre = head;
        }
        head = next;
    }
    return dummy->next;
}

int main(int argc, char* argv[]) {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;
    ListNode* tmp = removeElements(&node1, 2);
    while (tmp) {
        cout << tmp->val << ",";
        tmp = tmp->next;
    }
    cout << endl;
    return 0;
}
