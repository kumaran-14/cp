#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mxN 1e7
#define newl cout << "\n"
#define vi vector<int>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


typedef pair<int, pair<int, int>> threepair;

class Solution {
public:
  int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    if(n == 0 || m == 0)
      return max(n, m);
    if(s1 == s2) return 0;
    vector<vi> dp(n+1, vi(m+1, 1e9));
    dp[0][0] = 0;
    rep(i, 1, n+1) dp[i][0] = i;
    rep(i, 1, m+1) dp[0][i] = i;
    rep(i, 1, n+1) {
      rep(j, 1, m+1) {
        if(s1[i-1] == s2[j-1]) {
          dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
        } else {
          dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
      }
    }
    return dp[n][m];
  }
};

int main() {
  auto sol = Solution();
  vector<vector<int>> arr = {{1, 2}, {1, 3}, {2, 3}};
  vector<string> vec = {"leet", "code"};
  int n = arr.size();
  auto res = sol.minDistance("sea", "eat");
  debug(res);


}