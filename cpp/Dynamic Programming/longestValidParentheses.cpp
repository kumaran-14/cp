#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

class Solution {
public:
  int longestValidParentheses(string s) {
    if(!s.length()) return 0;
    int n = s.size();
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++ ){
      if(s[i] == ')' && s[i-1] == '(')  {
        dp[i] = 2 + (i-2 >= 0 ? dp[i-2] : 0);
      }
      else if (s[i] == ')' && s[i-1] == ')' && i-1-dp[i-1] >= 0 && s[i-1-dp[i-1]] == '(') {
        dp[i] = max(dp[i], 2 + dp[i-1] + (i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0));
      }
    }
    for(auto x:dp) cout<<x<<" ";
    return *max_element(dp.begin(), dp.end());
  }
};

/**
 * 2. stack solution
 * 3. left-right scan
 */

int main() {
  Solution sol = Solution();
  string s = "((((((((((((";
  auto f = sol.longestValidParentheses(s);
  debug(f);
}