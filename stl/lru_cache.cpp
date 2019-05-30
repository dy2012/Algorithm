#include <list>
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
 public:
  LRUCache(int n) : size_(n) {
  }

  int get(int key) {
    const auto iter = mp_.find(key);
    if (iter == mp_.cend()) {
      return -1;
    }
    cache_.splice(cache_.begin(), cache_, iter->second);
    return iter->second->second;
  }

  void put(int key, int value) {
    const auto it = mp_.find(key);
    if (it != mp_.cend()) {
      it->second->second = value;
      cache_.splice(cache_.begin(), cache_, it->second);
      return;
    }
    if (mp_.size() == size_) {
      const auto& node = cache_.back();
      mp_.erase(node.first);
      cache_.pop_back();
    }

    cache_.emplace_front(key, value);
    mp_[key] = cache_.begin();
  }
 private:
  list<pair<int, int>> cache_;
  unordered_map<int, list<pair<int,int>>::iterator> mp_;
  int size_;
};

int main() {
  LRUCache lru_cache(2);
  lru_cache.put(1,1);
  lru_cache.put(2,2);
  cout << lru_cache.get(1) << endl;
  cout << lru_cache.get(2) << endl;
  return 0;
}
