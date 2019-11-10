#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool Exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (Dfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool Dfs(vector<vector<char>>& board, string word, int x, int y, int pos, vector<vector<bool>>& visited) {
        if (pos == word.size()) {
            return true;
        }

        if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && !visited[x][y] && word[pos] == board[x][y]) {
            visited[x][y] = true;
            for (int i = 0; i < 4; ++i) {
                if (Dfs(board, word, x + step[i][0], y + step[i][1], pos + 1, visited)) {
                    return true;
                }
                visited[x][y] = false;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> res = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution solution;
    cout << solution.Exist(res, word) << endl;
    return 0;
}
