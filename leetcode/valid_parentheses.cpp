// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.


#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> parentheses;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
         parentheses.push(s[i]);
      } else {
        if (parentheses.empty()) {
          return false;
        }
        if (s[i] == ')' && parentheses.top() != '(') {
          return false;
        }
        if (s[i] == '}' && parentheses.top() != '{') {
          return false;
        }
        if (s[i] == ']' && parentheses.top() != '[') {
          return false;
        }
      }
    }
    return true;
  }
};

int main(int argc, char* argv[]) { 
  string s = "(x)";
  Solution solution;
  cout << solution.isValid(s) << endl;
}
