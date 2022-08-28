#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;
using std::string;
using std::cout;
using std::endl;

// Dp method.
bool WordBreak(string s, vector<string>& word_dict) {
    unordered_set<string> word_set(word_dict.begin(), word_dict.end());
    vector<bool> dp(s.size() + 1);
    dp[0] = true;
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && word_set.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            } 
        }
    }
    return dp.back();
}

int main(int argc, char* argv[]) {
    string s = "leetcode";
    vector<string> word_dict{"leet", "code"};
    cout << WordBreak(s, word_dict) << endl;
    return 0;
}

