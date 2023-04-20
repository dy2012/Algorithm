// You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int ct = 0;
    int minutes = -1;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<vector<int>> q;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] > 0) {
                ++ct;
            }
            if (grid[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        ++minutes;
        int size = q.size();
        for (int k = 0; k < size; ++k) {
            vector<int> cur = q.front();
            --ct;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = cur[0] + dir[i][0];
                int y = cur[1] + dir[i][1];
                if (x >= grid.size() ||
                        x < 0 ||
                    y >= grid.size() ||
                        y < 0 ||
                    grid[x][y] != 1) {
                    continue;
                }
                grid[x][y] = 2;
                q.push({x, y});
            }
        }
    }
    if (0 == ct) {
        return max(0, minutes);
    }
    return -1;
}

int main(int argc, char* argv[]) {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << orangesRotting(grid) << endl;
    return 0;
}
