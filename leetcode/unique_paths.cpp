#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
     int UniquePath(int m, int n) {
         vector<int> dp(n, 1);
         for (int i = 1; i < m; ++i) {
             for (int j = 1; j < n; ++j) {
                 dp[j] += dp[j - 1];
             }
         }
         return dp[n - 1];
     }

     int UniquePath2(int m, int n) {
         double num = 1;
         double denom = 1;
         int small = m > n ? n : m;
         for (int i = 1; i <= small - 1; ++i) {
             num *= m + n - 1 - i;
             denom *= i;
         }
         return (int)(num / denom);
     }
};



int main(int argc, char* argv[]) {
    Solution solution;
    cout << solution.UniquePath(3, 7) << endl;
    cout << solution.UniquePath2(3, 7) << endl;
    return 0;
}
