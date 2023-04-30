#include <iostream>
#include <vector>

using namespace std;

void setZeros(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    bool rowZeroFlag = false;
    bool colZeroFlag = false;
    for (int i = 0; i < n; ++i) {
        if (matrix[i][0] == 0) {
            colZeroFlag = true;
            break;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (matrix[0][i] == 0)  {
            rowZeroFlag = true;
            break;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    } 
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (rowZeroFlag) {
        for (int i = 0; i < n; ++i) {
            matrix[i][0] = 0;
        }
    }
    if (colZeroFlag) {
        for (int i = 0; i < m; ++i) {
            matrix[0][i] = 0;
        }
    }
}

int main(int argc, char* argv[]) {
    vector<vector<int>> nums = {{1,1,1}, {1, 0, 1}, {1, 1, 1}};
    setZeros(nums);
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[0].size(); ++j) {
            cout << nums[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
