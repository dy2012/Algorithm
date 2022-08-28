#include <iostream>
#include <vector>

using namespace std;

int upper_bound(vector<int> nums, int s, int e, int key) {
  int mid;
  if (nums[e] <= key ) {
    return e + 1;
  }

  while (s < e) {
    mid = s + (e - s) / 2;
    if (nums[mid] <= key) {
      s = mid + 1;
    } else {
      e = mid;
    }
  }
  return s;
}

int lis(vector<int> nums) {
  int len = 1;
  vector<int> end(nums.size() + 1);
  end[1]= nums[0];
  for(int i = 1; i < nums.size(); ++i) {
    int pos = upper_bound(end, 1, len, nums[i]);
    end[pos] = nums[i];
    if (len < pos) {
      len = pos;
    }
  }
  return len;
}

int main() {
  vector<int> nums = {2, 3, 1, 5, 9, 8, 10};
  cout << lis(nums) << endl;
}
