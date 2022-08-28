#include <iostream>
#include <stack>

using namespace std;

class MinStack {
 public:
  MinStack() {
    min_val_ = INT_MAX;
  }

  void push(int val) {
    if (val <= min_val_) {
      min_stack_.push(min_val_);
      min_val_ = val;
    }
    min_stack_.push(val);
  }

  void pop() {
    int t = min_stack_.top();
    min_stack_.pop();
    if (min_val_ == t) {
      min_val_ = min_stack_.top();
      min_stack_.pop();
    }
  }

  int top() {
    return min_stack_.top();
  }

  int getMin() {
    return min_val_;
  }

 private:
  int min_val_;

  stack<int> min_stack_;
};

int main(int argc, char* argv[]) {
  MinStack min_stack;
  min_stack.push(-2);
  min_stack.push(0);
  min_stack.push(-3);
  cout << min_stack.getMin() << endl;
  min_stack.pop();
  cout << min_stack.top() << endl;
  cout << min_stack.getMin() << endl;
  return 0;
}
