#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int RomanToInt(string s) {
    unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (mp.find(s[i]) == mp.end()) {
            continue;
        }
        if ((i + 1) < s.size() && mp[s[i]] < mp[s[i + 1]]) {
            sum += mp[s[i + 1]] - mp[s[i]];
            ++i;
            continue;
        }
        sum += mp[s[i]];
    }
    return sum;
}


int main(int argc, char* argv[]) {
    string s = "LVIII";
    cout << RomanToInt(s) << endl;
    return 0;
}
