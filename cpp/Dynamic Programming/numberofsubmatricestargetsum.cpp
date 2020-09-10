//
// Created by kumaran on 9/6/20.
//
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mxN 1e7
#define newl cout << "\n"
#define vi vector<int>

typedef pair<int, pair<int, int>> threepair;

class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    if(n == 0)
      return 0;
    int m = matrix[0].size(), ans = 0;

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 0; i < m; i++) {
      dp[0][i] = matrix[0][i];
    }

    for(int i = 1; i < n; i++)  {
      for(int j = 0; j < m; j++ ) {
        dp[i][j] += dp[i-1][j] + matrix[i][j];
        cout<<dp[i][j]<<" ";
      }
      newl;
    }

    newl;
    vector<int> arr(m, 0);

    for(int i = 0; i < n; i++) {
      debug(i);
      for(int j = 0; j <= i; j++ ) {
        debug(j);
        fill(all(arr), 0);
        for(int k = 0; k < m; k++) {
          if(j-1 >= 0) {
            arr[k] -= dp[j][k];
          }
          arr[k] += dp[i][k];
        }
        for(auto x:arr) cout<<x<<" ";
        newl;

        //find prefix sum hash to
        int sum = 0;
        unordered_map<int, int> hm;
        hm[0] = 1;
        for(int k = 0; k < m; k++) {
          sum += arr[k];
          if(hm.find(sum - target) != hm.end()) ans += hm[sum-target];
          hm[sum]++;
        }
      }
    }
    return ans;
  }
};

int main() {
  auto sol = Solution();
  vector<vector<int>> arr = {{0,1,0}, {1,1,1}, {0,1,0}};
  vector<int> vec = {2, 3, 4};
  int n = arr.size();
  auto res = sol.numSubmatrixSumTarget(arr, 0);
  debug(res);
  vector<int> v;
}