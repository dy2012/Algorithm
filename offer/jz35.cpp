// 复杂链表的复制

#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;

    struct RandomListNode* next;
    struct RandomListNode* random;

    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {
    }
};

RandomListNode* clone(RandomListNode* pHead) {
    if (nullptr == pHead) {
        return nullptr;
    }
    RandomListNode* pHead1 = pHead;
    RandomListNode* pHead2 = new RandomListNode(pHead1->label);
    RandomListNode* newHead = pHead2;
    unordered_map<RandomListNode*, RandomListNode*> mp;
    mp[pHead1] = pHead2;
    while (pHead1 != nullptr) {
        if (pHead1->next != nullptr) {
            pHead2->next = new RandomListNode(pHead1->next->label);
        } else {
            pHead2->next = nullptr;
        }
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
        mp[pHead1] = pHead2;
    }

    pHead1 = pHead;
    pHead2 = newHead;
    while (pHead1 != nullptr) {
        pHead2->random = mp[pHead1->random];
        pHead2 = pHead2->next;
        pHead1 = pHead1->next;
    }
    return newHead;
}

int main(int argc, char* argv[]) {
    RandomListNode node1(1);
    RandomListNode node2(2);
    RandomListNode node3(3);
    RandomListNode node4(4);
    RandomListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node1.random = &node3;
    node2.random = &node1;
    node3.random = &node5;
    node4.random = &node2;
    node5.random = &node1;
    RandomListNode* res = clone(&node1);
    RandomListNode* tmp = res;
    while (res != nullptr) {
        cout << res->label << ",";
        res = res->next;
    }
    cout << endl;
    cout << "random" << endl;
    while (tmp != nullptr) {
        if (tmp->random != nullptr) {
            cout << tmp->random->label << ",";
        } else {
            cout << "nullptr" << ',';
        }
        tmp = tmp->next;
    }
    cout << endl;
}
