#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int max_area = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l < r) {
      max_area = max(max_area, min(height[l], height[r]) * (r - l));
      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }
    return max_area;
  }
};

int main(int argc, char* argv[]) {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution solution;
  cout << solution.maxArea(height) << endl;
  return 0;
}
