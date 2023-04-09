// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool CanFinish(int numCourses, vector<vector<int>>& prereq) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> in(numCourses);
    for (auto a : prereq) {
        graph[a[1]].push_back(a[0]);
        ++in[a[0]];
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto a : graph[t]) {
            --in[a];
            if (in[a] == 0) {
                q.push(a);
            }
        }
    }

    for (int i = 0; i < numCourses; ++i) {
        if (in[i] != 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    vector<vector<int>> prereq = {{1,0}};
    cout << CanFinish(2, prereq) << endl;
    return 0;
}
