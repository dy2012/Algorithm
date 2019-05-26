#include <iostream>

using namespace std;

class Solution {
 public:
  string RemoveKdigits(string num, int k) {
    string ans;
    int len = num.size();
    int n = k;
    for (auto val : num) {
      while (!ans.empty() && n > 0 && val < ans.back()) {
        ans.pop_back();
        --n;
      }
      ans.push_back(val);
    }
    int cnt = 0;
    while (num[cnt] == '0') {
      ++cnt;
    }
    ans = ans.substr(cnt, len - k - cnt);
    return ans.empty() ? "0" : ans;
  }
};

int main() {
    Solution solution;
    string num = "123456";
    cout << solution.RemoveKdigits(num, 3) << endl;
    return 0;
}
