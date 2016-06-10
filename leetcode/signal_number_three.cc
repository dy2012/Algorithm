#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
 vector<int> signalNumber(vector<int>& nums) {
     vector<int> result;
     unordered_map<int, int> tmp;
     for (int i = 0; i < nums.size(); ++i) {
       if (tmp.find(nums[i]) != tmp.end()) {
         tmp.erase(nums[i]);
         continue;
       }
       tmp[nums[i]] = 0;
     }
     for (unordered_map<int, int>::iterator it = tmp.begin();
          it != tmp.end();
          ++it) {
       result.push_back(it->first);
     }
     return result;
 }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    Solution res;
    vector<int> result = res.signalNumber(nums);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 1;
}
