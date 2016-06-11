#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
 vector<int> topKFrequent(vector<int>& nums, int k) {
     vector<int> result;
     unordered_map<int,int> tmp;
     for (int i = 0; i < nums.size(); ++i) {
       if (tmp.find(nums[i]) != tmp.end()) {
         tmp[nums[i]]++;
         continue;
       }
       tmp[nums[i]] = 1;
     }
     vector<pair<int,int>> res(tmp.begin(), tmp.end());
     sort(res.begin(), res.end(), [=](pair<int,int>&a, pair<int,int>&b){
         return a.second < b.second; });
     for (int i = 0; i < k; ++i) {
       result.push_back(res[res.size() - 1 - i].first);
     }
     return result;
 }
};

int main() {
    Solution solution;
    vector<int> nums{3,2,1,2};
    vector<int> res = solution.topKFrequent(nums, 1);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 1;
}
