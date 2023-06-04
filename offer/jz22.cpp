// 链表中倒数最后k个结点

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {
    }
};

ListNode* FindKthNode(ListNode* pHead, int k) {
    int count = 0;
    ListNode* tmp = pHead;
    while (tmp != nullptr) {
        ++count;
        tmp = tmp->next;
    }
    if (count < k) {
        return nullptr;
    }
    tmp = pHead;
    for (int i = 0; i < (count - k); ++i) {
        tmp = tmp->next;
    }
    return tmp;
}

ListNode* FindKthNode2(ListNode* pHead, int k) {
    ListNode* slow = pHead;
    ListNode* fast = pHead;
    for (int i = 0; i < k; ++i) {
        if (fast == nullptr) {
            return nullptr;
        }
        fast = fast->next;
    }
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

ListNode* FindKthNode3(ListNode* pHead, int k) {
    if (pHead == nullptr || k == 0) {
        return nullptr;
    }
    stack<ListNode*> st;
    while (pHead != nullptr) {
        st.push(pHead);
        pHead = pHead->next;
    }
    if (st.size() < k) {
        return nullptr;
    }
    ListNode* newHead = st.top();
    st.pop();
    while (--k > 0) {
        ListNode* tmp = st.top();
        st.pop();
        tmp->next = newHead;
        newHead = tmp;
    }
    return newHead;
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
    ListNode* res = FindKthNode3(&node1, 2);
    while (res != nullptr) {
        cout << res->val << "," << endl;;
        res = res->next;
    }
    return 0;
}
