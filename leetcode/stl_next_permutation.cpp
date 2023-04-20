#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 2, 3, 4};
    sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
    do {
        copy(nums.begin(), nums.end(), std::ostream_iterator<int>(cout, ", "));
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));

    cout << "--------------------------------------------------------" << endl;

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    vector<int> elements = {1, 1, 1, 0, 0, 0, 0};
    int count = 0;
    do {
        cout << ++count <<  ": ";
        for (size_t i = 0; i < elements.size(); ++i) {
            if (elements[i] > 0) {
                cout << vec[i] << ", ";
            }
        }
        cout << endl;
    } while (prev_permutation(elements.begin(), elements.end()));
    return 0;
}
