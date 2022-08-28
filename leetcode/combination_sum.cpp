#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> res;
      vector<int> out;
      combinationSumDFS(candidates, target, 0, out, res);
      return res;
  }

  void combinationSumDFS(vector<int>& candidates, int target,
                         int start, vector<int>& out,
                         vector<vector<int>>& res) {
      if (target < 0) {
          return;
      }

      if (0 == target) {
          res.push_back(out);
          return;
      }
      for (int i = start; i < candidates.size(); ++i) {
          out.push_back(candidates[i]);
          combinationSumDFS(candidates, target - candidates[i], i, out, res);
          out.pop_back();
      }
  }
};

int main(int argc, char* argv[]) {
    vector<int> candidates = {2, 3, 6, 7};
    Solution solution;
    auto res = solution.combinationSum(candidates, 7);
    for (auto a : res) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}
