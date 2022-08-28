/* O(NlogN) */

#include <iostream>

#include <stdlib.h>

int UpperBound(int arr[], int start, int end, int key) {
    int mid;
    if (arr[end] <= key) {
        return end + 1;
    }

    while (start < end) {
        mid = start + (end - start) / 2;
        if (arr[mid] <= key) {
            start = mid + 1;
        } else {
            end = mid;
        }
        return start;
    }
}

int Lis(int d[], int n) {
    int i = 0;
    int len = 1;
    int* end = (int*)malloc(sizeof(int)*(n+1));
    end[1] = d[0];
    for (i = 1; i < n; ++i) {
        int pos = UpperBound(end, 1, len, d[i]);
        end[pos] = d[i];
        if (len < pos) {
            len = pos;
        }
    }
    return len;
}

int main() {
    int a[9] = {2, 1, 5, 3, 6, 4, 8, 9, 7};
    std::cout << "Longest Increasing Subsequnence is " << Lis(a, 9) << std::endl;
    return 0;
}
