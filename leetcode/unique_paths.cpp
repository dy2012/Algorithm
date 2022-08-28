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
};

int main(int argc, char* argv[]) {
    Solution solution;
    cout << solution.UniquePath(3, 7) << endl;
    return 0;
}
