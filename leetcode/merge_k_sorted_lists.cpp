#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
  int val;

  ListNode* next;

  ListNode(int x) : val(x), next(nullptr) {
  }
};

ListNode* split(vector<ListNode*>& lists, int l, int r);
ListNode* merge(ListNode* s, ListNode* t);

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }
    if (lists.size() == 1) {
        return lists[0];
    }

    int l = 0;
    int r = lists.size() - 1;
    return split(lists, l, r);
}

ListNode* split(vector<ListNode*>& lists, int l, int r) {
    if (l > r) {
        return nullptr;
    }
    if (l == r) {
        return lists[l];
    }
    int mid = (l + r) >> 1;
    ListNode* s = split(lists, l, mid);
    ListNode* t = split(lists, mid + 1, r);
    return  merge(s, t);
}

ListNode* merge(ListNode* s, ListNode* t) {
    ListNode dummy(0);
    ListNode* p = &dummy;
    while (s && t) {
        if (s->val < t->val) {
            p->next = s;
            s = s->next;
        } else {
            p->next = t;
            t = t->next;
        }
        p = p->next;
    }
    if (s) {
        p->next = s;
    }
    if (t) {
        p->next = t;
    }
    return dummy.next;
}

int main(int argc, char* argv[]) {
    ListNode node1(1);
    ListNode node2(2);
    node1.next = &node2;

    ListNode node3(3);
    ListNode node4(4);
    node3.next = &node4;

    ListNode node5(5);
    ListNode node6(6);
    node5.next = &node6;

    vector<ListNode*> res;
    res.push_back(&node1);
    res.push_back(&node3);
    res.push_back(&node5);

    ListNode* ans = mergeKLists(res);
    while (ans != nullptr) {
        cout << ans->val << ",";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
