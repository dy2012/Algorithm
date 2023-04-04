// Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string decode(const string& s, int& i);

string decodeString(const string& s) {
    int i = 0;
    return decode(s, i);
}

string decode(const string& s, int& i) {
    string res = "";
    int n = s.size();
    while (i < n && s[i] != ']') {
        if (s[i] < '0' || s[i] > '9') {
            res += s[i++];
        } else {
            int cnt = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + s[i++] - '0';
            }
            ++i;
            string t = decode(s, i);
            ++i;
            while (cnt-- > 0) {
                res += t;
            }
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    string s = "2[abc]3[cd]ef";
    cout << decodeString(s) << endl;
    return 0;
}
