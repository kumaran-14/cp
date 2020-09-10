#include <bits/stdc++.h>
using namespace std;



class LRUCache {
public:
  int cap;
  list<pair<int, int>> l;
  // key -> list{key, value}
  unordered_map<int, list<pair<int, int>>::iterator > hm;
  LRUCache(int capacity) {
    cap = capacity;
  }

  int get(int key) {
    if(hm.find(key) == hm.end())
      return -1;
    auto it = hm[key];
    int value = it->second;
    l.erase(it);
    l.push_back({key, value});
    hm[key] = prev(l.end());
    return value;
  }

  void put(int key, int value) {
    if(hm.find(key) == hm.end()) {
      if(cap == l.size()) {
        auto node = l.begin();
        hm.erase(hm.find(node->first));
        l.erase(l.begin());
      }
      // insert at end;
      l.push_back({key, value});
      hm[key] = prev(l.end());
    } else {
      // update key;
      // find list node, erase node, push node to first, update map;
      auto it = hm[key];
      l.erase(it);
      l.push_back({key, value});
      hm[key] = prev(l.end());
    }
  }
};

int main() {
  LRUCache cache = LRUCache( 2 /* capacity */ );

  cache.put(1, 1);
  cache.put(2, 2);
  cout<<cache.get(1)<<endl;       // returns 1
  cache.put(3, 3);    // evicts key 2
  cout<<cache.get(2)<<endl;       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1

  cout<<cache.get(1)<<endl;       // returns -1 (not found)
  cout<<cache.get(3)<<endl;       // returns 3
  cout<<cache.get(4);       // returns 4
}