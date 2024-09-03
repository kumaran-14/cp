#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> vec;
    deque<int> q;
    auto enq = [&](int index) {
      while(!q.empty() && arr[q.back()] < arr[index])
        q.pop_back();
      q.push_back(index);
    };
    auto deq = [&](int index) {
      if(!q.empty() && q.front() == index) q.pop_front();
    };
    for(int i = 0; i < min(k, n); i++) {
      enq(i);
    }
    vec.push_back(arr[q.front()]);
    for(int i = k; i < n; i++) {
      deq(i-k);
      enq(i);
      vec.push_back(arr[q.front()]);
    }
    return vec;
  }
};

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    multiset<int, greater<>> os;
    int n = arr.size();
    for(int i = 0; i < min(k, n); i++){
      os.insert(arr[i]);
    }
    vector<int> ans = {*os.begin()};
    for(int i = k; i < n; i++) {
      os.erase(os.find(arr[i-k]));
      os.insert(arr[i]);
      ans.push_back(*os.begin());
    }
    return ans;
  }
};
