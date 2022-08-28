#include <unordered_map>

using namespace std;

struct Node {
  int k;
  int v;
  Node* pre;
  Node* next;

  Node() : k(0), v(0), pre(nullptr), next(nullptr){
  }

  Node(int key, int val) : k(key), v(val), pre(nullptr), next(nullptr) {
  }
};

class LruCache {
 public:
  LruCache(int capacity) : cap(capacity), size(0) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->pre = head;
  }

  int get(int key) {
    if (!cache.count(key)) {
      return -1;
    }
    Node* node = cache[key];
    MoveToHead(node);
    return node->v;
  }

  void put(int key, int val) {
    if (cache.count(key)) {
      Node* node = cache[key];
      node->v = val;
      MoveToHead(node);
    } else {
      Node* node = new Node(key, val);
      cache[key] = node;
      AddToHead(node);
      ++size;
      if (size > cap) {
        node = RemoveTail();
        cache.erase(node->k);
        --size;
      }
    }
  }

 private:
  int cap;
  int size;
  Node* head;
  Node* tail;
  unordered_map<int, Node*> cache;

  void MoveToHead(Node* node) {
    RemoveNode(node);
    AddToHead(node);
  }

  void RemoveNode(Node* node) {
    node->pre->next = node->next;
    node->next->pre = node->pre;
  }

  void AddToHead(Node* node) {
    node->next = head->next;
    node->pre = head;
    head->next = node;
    node->next->pre = node;
  }

  Node* RemoveTail(Node* node) {
    Node* node = tail->pre;
    RemoveNode(node);
    return node;
  }
};

int main(int argc, char* argv[]) {
  return 0;
}
