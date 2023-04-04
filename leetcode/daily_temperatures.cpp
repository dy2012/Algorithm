// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

#include <stack>
#include <iostream>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(const vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n);
    stack<int> s; // 单调栈
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
            res[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    return res;
}

int main(int argc, char* argv[]) {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    auto res = dailyTemperatures(temperatures);
    for (auto it : res) {
        cout << it << ",";
    }
    cout << endl;
    return 0;
}
