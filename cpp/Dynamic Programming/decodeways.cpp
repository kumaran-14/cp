#include <bits/stdc++.h>
using namespace std;

#include <iostream>

class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    if(n == 0 || s[0] == '0') return 0;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 1; i < n; i++) {
      int curr_digit = s[i]-'0';
      int prev_digit = s[i-1]-'0';

      if(curr_digit > 0) dp[i+1] += dp[i];
      if(prev_digit == 1 || (prev_digit == 2 && curr_digit < 7)) dp[i+1] += dp[i-1];
    }

    return dp[n];
  }
};


class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    if(n == 0 || s[0] == '0') return 0;
    int prev = 1, curr = 1;

    for(int i = 1; i < n; i++) {
      int next = 0;
      int curr_digit = s[i]-'0';
      int prev_digit = s[i-1]-'0';

      if(curr_digit > 0) next += curr;
      if(prev_digit == 1 || (prev_digit == 2 && curr_digit < 7)) next += prev;

      prev = curr;
      curr = next;
    }

    return curr;
  }
};
