#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestCommonSubsequence(const string& text1, const string& text2) {
    size_t m = text1.size();
    size_t n = text2.size();
    vector<vector<int>> dp = {m + 1, vector<int>(n + 1, 0)};

    for (int i = 1; i <= m; ++i) {
        const char& tmp1 = text1[i - 1];
        for (int j = 1; j <= n; ++j) {
            const char& tmp2 = text2[j - 1];
            if (tmp1 == tmp2) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main(int argc, char* argv[]) {
    string text1 = "abcd";
    string text2 = "abd";
    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}
