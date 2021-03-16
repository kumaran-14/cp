#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define db(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mxN 1e7
#define newl cout << "\n"
#define vi vector<int>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


typedef pair<int, pair<int, int>> threepair;


class Solution {
public:
  int superEggDrop(int k, int n) {
    int inf = 1e9 + 7;
    vector<vector<int>> dp(n+1, vll(k+1, inf));
    memset(dp[0], 0, sizeof dp[0]);
    rep(i, 1, n) dp[i][1] = i;
    rep(i, 1, n) {
      for(int j = 2; j <= k; j++) {
        for(int y = 1; y <= min(j, i); y++) {
          // drop floor is y;
          dp[i][j] = min({dp[i][j], 1 + max(dp[y][j-1], dp[i-y][j]));
        }
      }
    }

    return dp[n][k];
  }
};
int main() {
  freopen("../output.txt", "w", stdout);

  auto sol = Solution();
  vector<vector<int>> arr = {{0,1,0}, {1,1,1}, {0,1,0}};
  vector<int> vec = {2, 3, 4};
  int n = arr.size();
  auto res = sol.superEggDrop();
//  debug(res);
//  vector<int> v;

}