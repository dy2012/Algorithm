// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int x) : val(x), next(nullptr), random(nullptr) {
    }
};

Node* copyRandomNode(Node* head) {
    if (nullptr == head) {
        return nullptr;
    }

    unordered_map<Node*, Node*> mp;
    Node* cur = head;
    while (cur != nullptr) {
        mp.insert({cur, new Node(cur->val)});
        cur = cur->next;
    }

    for (auto it : mp) {
        if (it.first->next != nullptr) {
            it.second->next = mp[it.first->next];
        }
        if (it.first->random != nullptr) {
            it.second->random = mp[it.first->random];
        }
    }
    return mp[head];
}


int main(int argc, char* argv[]) {
    Node node1(1);
    Node node2(2);
    Node node3(3);
    node1.next = &node2;
    node2.next = &node3;
    node1.random = &node3;
    node2.random = &node1;
    Node* res = copyRandomNode(&node1);
    return 0;
}
