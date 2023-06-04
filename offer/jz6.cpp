// 从尾到头打印链表

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;

    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

vector<int> PrintListFromTailToHead(ListNode* pHead) {
    vector<int> res;

    while (pHead != nullptr) {
        res.push_back(pHead->val);
        pHead = pHead->next;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, char* argv[]) {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;
    auto res = PrintListFromTailToHead(&node1);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
    return 0;
}
