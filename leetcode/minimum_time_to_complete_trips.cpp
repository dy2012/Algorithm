#include <iostream>
#include <vector>

using namespace std;

long long minmumTime(vector<int>& time, int totalTrips) {
    long minTime = INT_MAX;
    for (auto tmp : time) {
        minTime = minTime > tmp ? tmp : minTime;
    }

    if (totalTrips == 1) {
        return minTime;
    }

    long left = minTime;
    long right = minTime * totalTrips;
    while (left <= right) {
        long mid = left + (right - left) / 2;
        long cnt = 0;
        for (auto tmp : time) {
            cnt += mid / tmp;
            if (cnt > totalTrips) {
                break;
            }
        }
        if (cnt >= totalTrips) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 2, 3};
    int totalTrips = 5;
    cout << minmumTime(nums, totalTrips) << endl;
    return 0;
}
