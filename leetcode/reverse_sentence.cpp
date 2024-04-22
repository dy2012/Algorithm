#include <iostream>

using namespace std;

void Reverse(char* pBegin, char* pEnd) {
    if (pBegin == nullptr || pEnd == nullptr) {
        return;
    }
    while (pBegin < pEnd) {
        char pTemp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = pTemp;
        ++pBegin, pEnd--;
    }
}

char* ReverseSentence(char* pData) {
    if (pData == nullptr) {
        return pData;
    }
    char* pBegin = pData;
    char* pEnd = pData;

    while (*pEnd != '\0') {
        ++pEnd;
    }
    --pEnd;
    Reverse(pBegin, pEnd);

    pBegin = pEnd = pData;
    while (*pBegin != '\0') {
        if (*pBegin == ' ') {
            ++pBegin;
            ++pEnd;
        } else if (*pEnd == ' ' || *pEnd == '\0') {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        } else {
            ++pEnd;
        }
    }
    return pData;
}

int main(int argc, char* argv[]) {
    string str = "I am a student";
    char* res = ReverseSentence(const_cast<char*>(str.c_str()));
    string final_str(res);
    cout << final_str << endl;
    return 0;
}
