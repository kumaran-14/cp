#include <bits/stdc++.h>
using namespace std;

/*
 WILDCARD
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
*/
class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = 1;
    for (int j = 1; j <= m; j++) {
      dp[0][j] = p[j - 1] == '*' && dp[0][j - 1];
    }
    // state {i, j} = valid from s[0.....i] p[0......j]
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        } else {
          dp[i][j] =
              ((p[j - 1] == '?' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1]);
        }
      }
    }
    return dp[n][m];
  }
};

/*
 REGEX
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

*/
class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int j = 2; j <= m; j++) {
      dp[0][j] = p[j - 1] == '*' && dp[0][j - 2];
    }
    // state {i, j} = valid from s[0.....i] p[0......j]
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
          // keep moving or stay
          dp[i][j] =
              ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]) ||
              dp[i][j - 2];
        } else {
          dp[i][j] =
              ((p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1]);
        }
      }
    }
    return dp[n][m];
  }
};