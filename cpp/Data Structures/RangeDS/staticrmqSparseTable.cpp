#include <bits/stdc++.h>
using namespace std;

ll tc, n, m, k;
const int mxN = 2e5 + 7;
const int mxM = 500;
const int lg = 22;

ll arr[mxN];
ll dp[lg+1][mxN];
ll lg2[mxN];

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ll q;
  cin >> n >> q;
  rep(i, 0, n) cin >> arr[i];
  rep(j, 0, n) dp[0][j] = arr[j];

  rep(i, 2, n+1) lg2[i] = lg2[i>>1]+1;

  // precomputing sparse table
  // dp[i][j] = 2^i, from j index;
  for (int i = 1; i < lg; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
    }
  }
  // good for rsq;
  /*
  auto ans = [&](ll a, ll b) {
    ll res = 0;
    int x = b-a+1;
    for(int i = 0; (1<<i) <= n; i++) {
      if(x&(1<<i)) {
        res += dp[i][a];
        a = a + (1<<i);
      }
    }
    return res;
  };
  */

  while(q--) {
    ll L, R; cin>>L>>R; L--, R--;
    // rmq
    R++;
    int x = lg2[R-L];
    cout<<min(dp[x][L], dp[x][R-(1<<x)]);
    newl;
  }


  return 0;
}