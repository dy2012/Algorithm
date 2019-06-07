#include <iostream>

using namespace std;

class Solution {
 public:
  int LongestPalindrome(std::string s) {
      int char_map[128] = {0};
      int max_length = 0;
      int flag = 0;
      for (int i = 0; i < s.size(); ++i) {
          char_map[s[i]]++;
      }

      for (int i = 0; i < 128; ++i) {
          if (char_map[i] % 2 == 0) {
              max_length += char_map[i];
          } else {
              flag = 1;
              max_length += char_map[i] - 1;
          }
      }
      return max_length + flag;
  }
};

int main() {
    std::string s = "abcccccddaa";
    Solution solution;
    cout << solution.LongestPalindrome(s) << endl;
    return 0;
}
