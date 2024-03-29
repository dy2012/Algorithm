// Median of Two Sorted Arrays
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).


#include <iostream>
#include <vector>

using namespace std;

int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k);

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int left = (m + n + 1) / 2;
    int right = (m + n + 2) / 2;
    return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
}

int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
    if (i == nums1.size()) {
        return nums2[j + k - 1];
    }
    if (j == nums2.size()) {
        return nums1[i + k - 1];
    }
    if (k == 1) {
        return min(nums1[i], nums2[j]);
    }
    int midVal1 = ((i + k / 2 - 1) < nums1.size()) ? nums1[i + k/2 - 1] : INT_MAX;
    int midVal2 = ((j + k / 2 - 1) < nums2.size()) ? nums2[j + k/2 - 1] : INT_MAX;
    if (midVal1 < midVal2) {
        return findKth(nums1, i + k /2, nums2, j, k - k/2);
    } else {
        return findKth(nums1, i, nums2, j + k/2, k - k/2);
    }
}

int main(int argc, char* argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}

