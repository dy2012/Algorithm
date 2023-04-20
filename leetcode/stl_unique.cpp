#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct AreBothSpaces {
    bool operator()(char x, char y) {
        return x == ' ' && y == ' ';
    }
};

void removeContinuousSpaces(std::string& str) {
    std::string::iterator last = 
        std::unique(str.begin(), str.end(), AreBothSpaces());
    str.erase(last, str.end());
    cout << str << endl;
}

int main(int argc, char* argv[]) {
    string x = "a  b";
    removeContinuousSpaces(x);
    return 0;
}
