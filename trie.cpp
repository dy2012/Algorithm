#include <vector>

using namespace std;

class Trie {
 public:
  vector<Trie*> children;

  bool isEnd;
  
  Trie* SearchPrefix(string s) {
      Trie* node = this;
      for (char c : s) {
          int idx = c - 'a';
          if (!node->children[idx]) {
              return nullptr;
          }
          node = node->children[idx];
      }
      return node;
  }

 private:
  Trie() : children(26), isEnd(false) {
  }

  void insert(String word) {
      Trie* node = this;
      for (char c : word) {
          int idx = c - 'a';
          if (!node->children[idx]) {
              node->children[idx] = new Trie();
          }
          node = node->children[idx];
      }
      node->isEnd(true);
  }

  bool search(String word) {
      Trie* node = SearchPrefix(word);
      return node != nullptr && node->isEnd();
  }

  bool StartWith(string prefix) {
      Trie* node = SearchPrefix(prefix);
      return node != nullptr;
  }
};
