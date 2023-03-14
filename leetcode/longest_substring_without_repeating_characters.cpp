#include <iostream>
#include <unordered_map>

using namespace std;

int LongestSubstring(const string& s) {
    if (s.empty()) {
        return 0;
    }
    int res = 0;
    int n = s.size();
    int left = -1;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; ++i) {
        if (mp.count(s[i]) && left < mp[s[i]]) {
            left = mp[s[i]];
        }
        mp[s[i]] = i;
        res = max(res, i - left);
    }
    return res;
}

int main(int argc, char* argv[]) {
    string s = "abababa";
    cout << LongestSubstring(s) << endl;
    return 0;
}
