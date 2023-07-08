#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = nums1.size() - 1;
    --m;
    --n;
    while (n >= 0) {
        while (m >= 0 && nums1[m] > nums2[n])  {
            swap(nums1[i--], nums1[m--]);
        }
        swap(nums1[i--], nums2[n--]);
    }
}

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p = m - 1;
    int q = n - 1;
    for (int i = m + n - 1; i >= 0; --i) {
        if (p >= 0 && q >= 0) {
            nums1[i] = nums1[p] > nums2[q] ? nums1[p--] : nums2[q--];
        } else if (q >= 0) {
            nums1[i] = nums2[q--];
        } else {
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {4, 5, 6};
    merge2(nums1, 3, nums2, 3);
    for (auto it : nums1) {
        cout << it << ",";
    }
    cout << endl;
    return 0;
}
