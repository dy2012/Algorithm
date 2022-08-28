#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int binary_search(vector<int> vec, int value) {
    int low = 0;
    int high = vec.size() - 1;
    int mid = low + (high - low) / 2;
    while (low <= high) {
        if (vec[mid] == value) {
            return mid;
        } else if (vec[mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return -1;
}

int main(int argc, char* argv[]) {
    vector<int> vec{1,2,3,4,7,9};
    cout << binary_search(vec, 7) << endl;
}
