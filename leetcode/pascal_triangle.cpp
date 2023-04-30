#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if (numRows < 1) {
        return res;
    }
    if (numRows <= 2) {
        for (int i = 0; i <= numRows; ++i) {
            vector<int> tmp(i, 1);
            res.push_back(tmp);
        }
        return res;
    } else {
        for (int i = 1; i <= 2; ++i) {
            vector<int> tmp(i, 1);
            res.push_back(tmp);
        }
        for (int i = 3; i <= numRows; ++i) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int k = 1; k < res[i - 2].size(); ++k) {
                int sum = res[i-2][k-1] + res[i-2][k];
                tmp.push_back(sum);
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    int n = 5;
    vector<vector<int>> res = generate(n);
    int current_row = 0;
    for (vector<int> iter : res) {
        for (int i = current_row; i < n - 1; ++i) {
            cout << " ";
        }
        ++current_row;
        for (int num : iter) {
            cout << num << ",";
        }
        cout << endl;
    }
    return 0;
}
