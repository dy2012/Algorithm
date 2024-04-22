#include <stdio.h>

#include <iostream>
#include <string>

using namespace std;

void Permutation(char* str, char* begin);

void Permutation(char* str) {
    if (nullptr == str) {
        return;
    }

    Permutation(str, str);
}

void Permutation(char* str, char* begin) {
    if (*begin == '\0') {
        printf("%s\n", str);
    } else {
        for (char* ch = begin; *ch != '\0'; ++ch) {
            char tmp = *ch;
            *ch = *begin;
            *begin = tmp;

            Permutation(str, begin + 1);

            tmp = *ch;
            *ch = *begin;
            *begin = tmp;
        }
    }
}

int main(int argc, char* argv[]) {
    string tmp = "abc";
    Permutation(const_cast<char*>(tmp.c_str()));
    return 0;
}
