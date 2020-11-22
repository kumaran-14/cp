#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define db(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mxN 1e7
#define newl cout << "\n"
#define vi vector<int>
#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

typedef pair<int, pair<int, int>> threepair;

class Solution {
public:
  // Problem: Given string, find smallest subsequence by removing m digits.
  // Idea: Same as constructing smallest sequence of length n-m from original string.
  string removeKdigits(string str, int m) {
    auto xnum = [&](int j, const string& st) { return st[j] - '0'; };
    int n = str.size();
    int k = n - m;
    string ans = "";
    for (int i = 0; i < n; i++) {
      // pop until stack is empty, or until original array contains enough elements to make n-m length sequence.
      while(ans.size() && n-i > k-ans.size() && xnum(ans.size()-1, ans) > xnum(i, str)) {
        ans.pop_back();
      }
      if(ans.size() < k) ans.pb(str[i]);
    }

    // to remove leading zeros
    reverse(ans.begin(), ans.end());
    while(ans.size() && xnum(ans.size()-1, ans) == 0) ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  auto sol = Solution();
  vector<vector<int>> arr = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
  vector<int> vec = {2, 3, 4};
  int n = arr.size();
  auto res = sol.removeKdigits("10200", 1);
  db(res);
  //  vector<int> v;
}