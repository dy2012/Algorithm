#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int MaxProfit(vector<int>& prices) {
    int res = 0;
    int buy = INT_MAX;
    for (int price : prices) {
      buy = min(buy, price);
      res = max(res, price - buy);
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  vector<int> prices = {7,1,5,3,6,4};
  cout << solution.MaxProfit(prices) << endl;
  return 0;
}
