#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    int res = nums[0];
    int n = nums.size();
    vector<int> f(n, 0);
    vector<int> g(n, 0);
    f[0] = nums[0];
    g[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
        g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
        res = max(f[i], res);
    }
    return res;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {2, 3, -1, 2};
    cout << maxProduct(nums) << endl;
    return 0;
}
