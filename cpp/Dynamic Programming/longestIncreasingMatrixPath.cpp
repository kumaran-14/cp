#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int ans = 1;
    int n = matrix.size();
    if (n == 0)
      return 0;
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));


    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};

    function<int(int, int)> dfs = [&](int i, int j) {
      if(dp[i][j]) return dp[i][j];
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x < 0 || y < 0 || x >= n || y >= m)
          continue;
        if (matrix[i][j] < matrix[x][y])
          // IMPORTANT
          dp[i][j] = max(dp[i][j], dfs(x, y));
      }
      // IMPORTANT
      return ++dp[i][j];
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans = max(ans, dfs(i, j));
      }
    }
    return ans;
  }
};
