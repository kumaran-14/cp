#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> partition(string s) {
    auto isPalin = [&](const string str) {
      if (str.length() == 1)
        return true;
      int x = 0, y = str.size() - 1;
      while (x < y) {
        if (str[x] != str[y])
          return false;
        x++;
        y--;
      }
      return true;
    };

    vector<vector<string>> ans;

    function<void(int, vector<string>)> bt = [&](int i, vector<string> vec) {
      if (i >= s.length()) {
        ans.push_back(vec);
        return;
      }
      string str = "";
      for (int j = i; j < s.length(); j++) {
        str += s[j];
        if (!isPalin(str))
          continue;
        // cout << str << " ";
        vec.push_back(str);
        bt(j + 1, vec);
        vec.pop_back();
      }
    };

    vector<string> vec;
    bt(0, vec);
    return ans;
  }
};