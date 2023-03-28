// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>

using namespace std;

class Trie {
 public:
  Trie() {
  }

 void insert(const string& word) {
     string tmp;
     for (int i = 0; i < (word.size() - 1); ++i) {
         tmp += word[i];
         trie_.insert(make_pair(tmp, false));
     }
     trie_.insert(make_pair(word, true));
 }

 bool search(const string& word) {
     auto iter = trie_.find(word);
     if (iter == trie_.end()) {
         return false;
     }
     return iter->second;
 }

 bool startWith(const string& word) {
     return trie_.find(word) != trie_.end();
 }

 private:
  unordered_map<string, bool> trie_;
};

int main(int argc, char* argv[]) {
    Trie trie;
    trie.insert("hello");
    cout << trie.startWith("he") << endl;
    cout << trie.search("hello") << endl;
    return 0;
}
