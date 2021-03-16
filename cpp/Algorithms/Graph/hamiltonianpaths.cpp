#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define db(x) cout << '>' << #x << ':' << x << endl;
#define sz(x) ((int)(x).size())
#define newl cout << "\n"

#define ll long long int
#define vi vector<int>
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long, long long>

#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

const int mxN = 20;
const int mxM = 2e5 + 7;
const int inf = 1e9;
const int MOD = 1e9+7;

ll tc, n, m, k;
ll g[mxN][mxN];
ll dp[(1<<mxN)][mxN];


int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif


  cin >> n >> m;

  rep(i, 0, m) {
    ll u, v;
    cin>>u>>v, u--, v--;
    g[u][v]++;
  }

  dp[1][0] = 1;
  ll limit = (1<<n);
  rep(mask, 2, limit) {
    // if visiting n, but before all are visitied, then skip
    if(mask&(1<<(n-1)) && mask != limit-1) continue;
    rep(v, 0, n) {
      if(mask&(1<<v)){
        // we need to go to dp[mask][v] from different u;
        auto submask = mask^(1<<v);
        rep(u, 0, n) {
          if(submask&(1<<u) && g[u][v]) {
            dp[mask][v] += dp[submask][u]*g[u][v];
          }
        }
        dp[mask][v] %= MOD;
      }
    }
  }

  cout<<dp[limit-1][n-1];
  // better solution: https://cses.fi/problemset/hack/1690/entry/1491570/
  return 0;
}