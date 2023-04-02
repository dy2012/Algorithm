// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;


class LRUCache {
 public:
  LRUCache(int capacity) : cap_(capacity) {
  }

  int get(int key) {
    auto it = map_.find(key);
    if (it == map_.end()) {
        return -1;
    }
    pair<int, int> kv = *map_[key];
    cache_.erase(map_[key]);
    cache_.push_front(kv);
    map_[key] = cache_.begin();
    return kv.second;
  }

  void put(int key, int value) {
    auto it = map_.find(key);
    if (it == map_.end()) {
      if (cache_.size() == cap_) {
        auto lastKv = cache_.back();
        map_.erase(lastKv.first);
        cache_.pop_back();
      }
      cache_.push_front({key, value});
      map_[key] = cache_.begin();
    } else {
      cache_.erase(map_[key]);
      cache_.push_front({key, value});
      map_[key] = cache_.begin();
    }
  }

 private:
  int cap_;

  list<pair<int, int>> cache_;

  unordered_map<int, list<pair<int, int>>::iterator> map_;
};

int main(int argc, char* argv[]) {
    return 0;
}
