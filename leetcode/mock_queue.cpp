#include <stack>
#include <iostream>

using namespace std;

template <typename T>
class MockQueue {
 public:
  MockQueue() {
  }

  ~MockQueue() {
  }

  void addTail(const T& element) {
    stack1.push(element);
  }

  T deleteHead() {
      if (stack2.size() <= 0) {
          while (stack1.size() > 0) {
              T& tmp = stack1.top();
              stack2.push(tmp);
              stack1.pop();
          }
      }

      if (stack2.size() == 0) {
          return -1;
      }

      T& head = stack2.top();
      stack2.pop();
      return head;
  }

 private:
  stack<T> stack1;

  stack<T> stack2;
};

int main(int argc, char* argv[]) {
    MockQueue<int> mock_queue;
    mock_queue.addTail(1);
    cout << mock_queue.deleteHead() << endl;
    return 0;
}
