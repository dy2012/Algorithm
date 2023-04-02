// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> res;
    int charVec[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
        charVec[s[i] - 'a'] = i;
    }
    for (int i = 0; i < s.size();) {
        int nextPos = charVec[s[i] - 'a'];
        for (int j = i + 1; j <= nextPos; ++j) {
            nextPos = max(nextPos, charVec[s[j] - 'a']);
        }
        res.push_back(nextPos - i + 1);
        i = nextPos + 1;
    }
    return res;
}

int main(int argc, char* argv[]) {
    string s = "ababcbacadefegdehijhklij";
    vector<int> res;
    res = partitionLabels(s);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
    return 0;
}
