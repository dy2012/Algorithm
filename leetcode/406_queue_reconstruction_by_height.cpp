#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      //vector<vector<int>> res(people.size(), vector<int>(people[0].size()));
      vector<vector<int>> res;
      sort(people.begin(), people.end(), [](vector<int>& a, vector<int> b) {
        return a[0]  > b[0] || (a[0] == b[0] && a[1] < b[1]);});
      for (auto& a : people) {
          for (auto& b : a) {
              cout << b << " ";
          }
          cout << endl;
      }
      cout << endl;
      for (auto& a : people) {
          res.insert(res.begin() + a[1], a);
          for (auto& x : res) {
              for (auto& y : x) {
                  cout << y << " ";
              }
              cout << endl;
          }
          cout << endl;
      }
      return res;
  }
};

int main() {
    vector<vector<int>> input = {{7,0}, {4, 4}, {7,1}, {5,0}, {6,1}, {5,2}};
    Solution solution;
    auto res = solution.reconstructQueue(input);
    for (auto& a : res) {
        for (auto& b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}
