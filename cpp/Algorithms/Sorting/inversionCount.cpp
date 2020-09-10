#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
#define itr vector<pair<int, int>>::iterator
  vector<int> countSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> count(n, 0);
    vector<pair<int, int>> vec;
    for(int i = 0; i < n; i++) {
      vec.push_back({arr[i], i});
    }

    function<void(itr, itr)> invcount = [&](itr l, itr r) {
      if(r-l <= 1) return;
      itr m = l + (r-l)/2;
      invcount(l, m);
      invcount(m, r);
      for(itr i = l, j = m; i < m; i++) {
        while(j < r && (*i).first > (*j).first) j++;
        count[(*i).second] += m - j;
      }
      inplace_merge(l, m, r);
    };

    return count;
  }
};
