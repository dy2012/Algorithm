#include <iostream>
#include <string>

using namespace std;

bool match(char* str, char* pattern) {
    if (str == nullptr || pattern == nullptr) {
        return false;
    }
}

bool matchCore(char* str, char* pattern) {
    if (*str == '\0' && *pattern == '\0') {
        return true;
    }
    if (*str != '\0' && *pattern == '\0') {
        return false;
    }
    if (*(pattern + 1) == '*') {
        if (*pattern == *str || (*pattern == '.' && *str != '0')) {
            return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchScore(str, pattern + 2);
        } else {
            return matchCore(str, pattern + 2);
        }
    }
    if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
        return matchCore(str + 1, pattern + 1);
    }
    return false;

int main(int argc, char* argv[]) {
    return 0;
}
