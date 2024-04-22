#include <stack>
#include <iostream>

using namespace std;

class MockQueue {
 public:
  MockQueue() {
  }

  ~MockQueue() {
  }

  void addTail(int element) {
    stack1.push(element);
  }

  int deleteHead() {
      if (stack2.size() <= 0) {
          while (stack1.size() > 0) {
              int tmp = stack1.top();
              stack2.push(tmp);
              stack1.pop();
          }
      }

      if (stack2.size() == 0) {
          return -1;
      }

      int head = stack2.top();
      stack2.pop();
      return head;
  }

 private:
  stack<int> stack1;

  stack<int> stack2;
};

int main(int argc, char* argv[]) {
    return 0;
}
