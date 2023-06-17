# 链表

## 链表结构

```c++
struct ListNode {
  int val;

  ListNode* next;

  ListNode(int x) : val(x), next(nullptr) {
  }
};
```

## 虚拟头节点
编程技巧
```c++
ListNode* dummy = new ListNode(-1);
dummy->next = head;
return dummy->next;
```
