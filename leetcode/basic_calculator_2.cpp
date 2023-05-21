#include <stack>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int calculate(const string& s) {
    long res = 0;
    long num = 0;
    long n = s.size();
    char op = '+';
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] >= '0') {
            num = num * 10 + s[i] - '0';
        }
        if ((s[i] < '0' && s[i] != ' ') || i == n-1) {
            if (op == '+') {
                st.push(num);
            }
            if (op == '-') {
                st.push(-num);
            }
            if (op == '*' || op == '/') {
                int tmp = (op == '*') ? st.top() * num : st.top() / num;
                st.pop();
                st.push(tmp);
            }
            op = s[i];
            num = 0;
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main(int argc, char* argv[]) {
    string s = "3+2*2";
    cout << calculate(s) << endl;
}
