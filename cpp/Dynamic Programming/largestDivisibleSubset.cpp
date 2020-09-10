//
// Created by kumaran on 8/12/20.
//
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(all(nums));
    int n = nums.size();
    int endIndex = -1;
    int maxLen = 0;
    vector<int> parent(n, 0);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = i; j >= 0; --j) {
        if(nums[i]%nums[j] == 0 && dp[i] < dp[j]+1) {
          dp[i] = 1 + dp[j];
          parent[i] = j;
          if(maxLen < dp[i]) {
            maxLen = max(maxLen, dp[i]);
            endIndex = i;
          }
        }
      }
    }
    vector<int> ans;
    int t = endIndex;
    int h = maxLen;
    // way to form the largest divisible subset
    while(h--) {
      ans.push_back(nums[t]);
      t = parent[t];
    }
    return ans;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> v = {1, 2, 4, 8, 64};
  auto res = sol.largestDivisibleSubset(v);
  for(auto x:res) cout<<x<<" ";
}
