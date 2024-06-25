#include <iostream>
#include <list>

using namespace std;

int LastRemaining(unsigned int n, unsigned int m) {
    if (n < 1 || m < 1) {
        return -1;
    }

    list<int> numbers;
    for (int i = 0; i < n; ++i) {
        numbers.push_back(i);
    }
    auto current = numbers.begin();
    while (numbers.size() > 1) {
        for (int i = 1; i < m; ++i) {
            ++current;
            if (current == numbers.end()) {
                current = numbers.begin();
            }
        }
        auto next = ++current;
        if (next == numbers.end()) {
            next = numbers.begin();
        }
        --current;
        numbers.erase(current);
        current = next;
    }
    return *(current);
}

int LastRemaining2(unsigned int n, unsigned int m) {
    if (n < 1 || m < 1) {
        return -1;
    }
    int last = 0;
    for (int i = 2; i <= n; ++i) {
        last = (last + m) % i;
    }
    return last;
}

int main(int argc, char* argv[]) {
    cout << LastRemaining(5, 3) << endl;
    cout << LastRemaining2(5, 3) << endl;
    return 0;
}
