#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
 public:
  string longestPalindrome(string s) {
      if (s.empty()) {
          return "";
      }
      int n = s.size();
      int len = 1;
      int left = 0;
      vector<vector<int>> dp(n, vector<int>(n, 0));
      for (int i = 0; i < n; ++i) {
          dp[i][i] = 1;
          for (int j = 0; j < i; ++j) {
              dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
              if (dp[j][i] && len < i - j + 1) {
                  len = i - j + 1;
                  left = j;
              }
          }
      }
      return s.substr(left, len);
  }
};

int main(int argc, char* argv[]) {
    string tmp = "noon";
    Solution solution;
    cout << solution.longestPalindrome(tmp) << endl;
    return 0;
}
