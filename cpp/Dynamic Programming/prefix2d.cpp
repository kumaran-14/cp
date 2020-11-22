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

class Solution {
public:
  vector<vector<int>> prefix2d(vector<vector<int>> &mat) {
    int n = mat.size();
    if (n == 0)
      return vector<vector<int>>();
    int m = mat[0].size();

    // 2d prefix sum;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // fill left top element
    dp[0][0] = mat[0][0];
    // fill 1st row and 1st column
    rep(i, 1, m) dp[0][i] = dp[0][i-1] + mat[0][i];
    rep(i, 1, n) dp[i][0] = dp[i-1][0] + mat[i][0];

    // fill rest of them
    rep(i, 1, n) {
      rep(j, 1, m) {
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i][j];
      }
    }

    // query rectange sum from (both inclusive) [0][0] to [p][q], p = x.first, q = x.second.
    auto pfsum = [&](pii x) {
      if (x.first >= 0 && x.first < n && x.second >= 0 && x.second < m)
        return dp[x.first][x.second];
      return 0;
    };
    // query rectangle sum (left top) [x][y] to  (right bottom) [p][q] both inclusive.
    auto getsum = [&](pii a, pii b) {
      return pfsum(b) + pfsum({a.first - 1, a.second - 1}) -
          pfsum({a.first - 1, b.second}) - pfsum({b.first, a.second-1});
    };

  }
};

int main() {
  auto sol = Solution();
  vector<vector<int>> arr = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
  vector<int> vec = {2, 3, 4};
  int n = arr.size();
  //  auto res = sol.numSubmatrixSumTarget(arr, 0);
  //  debug(res);
  //  vector<int> v;
}