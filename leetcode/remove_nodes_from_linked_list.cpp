#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
ListNode* removeNodes(ListNode* head) {
        if (nullptr == head) {
            return nullptr;
        }
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* cur = dummy.next;
        stack<ListNode*> st;
        st.push(head);
        while (cur->next != nullptr) {
            ListNode* next = cur->next;
            while (!st.empty()) {
                ListNode* top = st.top();
                if (next->val <= top->val) {
                    break;
                }
                st.pop();
            }
            st.push(next);
            cur = cur->next;
        }
        cout << st.size() << endl;
        dummy.next = st.top();
        st.pop();
        cur = dummy.next;
        while (!st.empty()) {
            ListNode* tmp = st.top();
            cout << tmp->val << endl;
            tmp->next = cur;
            cur = tmp;
            st.pop();
        }
        return cur;
}

int main(int argc, char* argv[]) {
    ListNode node1(5);
    ListNode node2(2);
    ListNode node3(13);
    ListNode node4(3);
    ListNode node5(8);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    auto res = removeNodes(&node1);
    while (res != nullptr) {
        cout << res->val;
        res = res->next;
    }
    cout << endl;
    return 0;
}
