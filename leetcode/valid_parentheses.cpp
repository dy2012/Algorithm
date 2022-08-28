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
