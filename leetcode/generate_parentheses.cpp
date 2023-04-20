// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include <string>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int left, int right, string out, vector<string>& res);

vector<string> generateParenthesis(int n) {
    vector<string> res;
    dfs(n, n, "", res);
    return res;
}

void dfs(int left, int right, string out, vector<string>& res) {
    if (left > right) {
        return;
    }
    if (0 == left && 0 == right) {
        res.push_back(out);
    } else {
        if (left > 0) {
            dfs(left - 1, right, out + '(', res);
        }
        if (right > 0) {
            dfs(left, right - 1, out + ')', res);
        }
    }
}

int main(int argc, char* argv[]) {
  vector<string> res = generateParenthesis(2);
  cout << "[";
  for (auto it : res) {
      cout << it << ",";
  }
  cout << "]";
  cout << endl;
  return 0;
}

