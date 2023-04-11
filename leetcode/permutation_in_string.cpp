// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool checkInclusion(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    vector<int> m1(128);
    vector<int> m2(128);
    for (int i = 0; i < n1; ++i) {
        ++m1[s1[i]];
        ++m2[s2[i]];
    }
    if (m1 == m2) {
        return true;
    }
    for (int i = n1; i < n2; ++i) {
        ++m2[s2[i]];
        --m2[s2[i - n1]];
        if (m1 == m2) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    string s1 = "ab";
    string s2 = "eidboaoo";
    cout << checkInclusion(s1, s2) << endl;
    return 0;
}
