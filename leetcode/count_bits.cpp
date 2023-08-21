#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      res[i] = res[i & (i - 1)] + 1;
    }
    return res;
  }

  vector<int> countBits2(int n) {
    vector<int> res(n + 1);
    for (int i = 0; i <= n; ++i) {
      int count = 0;
      int n = i;
      while (n) {
        n = n & (n - 1);
        ++count;
      }
      res[i] = count;
    }
  }

  vector<int> countBits3(int n) {
      vector<int> dp(n + 1, 0);
      for (int i = 0; i <= n; ++i) {
          if (i % 2 == 0) {
              dp[i] = dp[i / 2];
          } else {
              dp[i] = dp[i / 2] + 1;
          }
      }
      return dp;
  }

  vector<int> countBits4(int n) {
      vector<int> res;
      for (int i = 0; i <= n; ++i) {
          int cur = 0;
          int num = i;
          while (num) {
              if (num % 2) {
                  ++cur;
              }
              num /= 2;
          }
          res.push_back(num);
      }
      return res;
  }

};

int main(int argc, char* argv[]) {
  Solution solution;
  vector<int> nums = solution.countBits(10);
  for (int num : nums) {
    cout << num <<  ",";
  }
  cout << endl;
  vector<int> nums2 = solution.countBits(10);
  for (int num : nums2) {
      cout << num << ",";
  }
  cout << endl;
  return 0;
}
