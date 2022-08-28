#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int res = 0;
        int left = -1;
        int n = s.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.count(s[i]) && m[s[i]] > left) {
                left = m[s[i]];
            }
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
        
    }

    int lengthOfLongestSubstring2(string s) {
        vector<int> m(128, -1);
        int res = 0;
        int left = -1;
        for (int i = 0; i < s.size(); ++i) {
            left = max(left, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    string s = "abcabcbb";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    cout << solution.lengthOfLongestSubstring2(s) << endl;
    return 0;
}
