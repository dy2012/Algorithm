#include <deque>
#include <vector>
#include <iostream>

using namespace std;

// nums: input array
// size: window's size
vector<int> maxInWindows(const vector<int>& nums, unsigned int size) {
    vector<int> maxInWindows;
    if (nums.size() > 0 && size >= 1) {
        deque<int> index;
        for (unsigned int i = 0; i < size; ++i) {
            while (!index.empty() && nums[i] >= nums[index.back()]) {
                index.pop_back();
            }
            index.push_back(i);
        }
        for (unsigned int i = size; i < nums.size(); ++i) {
            maxInWindows.push_back(nums[index.front()]);
            while (!index.empty() && nums[i] >= nums[index.back()]) {
                index.pop_back();
            }
            if (!index.empty() && index.front() <= int(i - size)) {
                index.pop_front();
            }
            index.push_back(i);
        }
        maxInWindows.push_back(nums[index.front()]);
    }
    return maxInWindows;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {2, 3, 4, 2, 6, 5, 1};
    vector<int> res = maxInWindows(nums, 3);
    for (auto i : res) {
        cout << i << ",";
    }
    cout << endl;
    return 0;
}
