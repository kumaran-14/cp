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

ll tc, n, m, k;
const int mxN = 500 + 7;
const int mxM = 500;
ll vis[mxM];
ll mt[mxM];
vll g[mxN];

// cses school dance
// more kuhn optimization: cf blog
// https://codeforces.com/blog/entry/17023?locale=en

int dfs(ll u) {
  if (vis[u])
    return 0;
  vis[u] = 1;

  for (auto v1 : g[u]) {
    if (mt[v1] == -1 || dfs(mt[v1])) {
      mt[v1] = u;
      return 1;
    }
  }
  return 0;
}

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif


  cin >> n >> m >> k;

  rep(i, 0, k) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
  }
  int ans = 0;
  memset(mt, -1, m*sizeof(ll) );
  memset(vis, 0, n*sizeof(ll));
  rep(u, 0, n) {
    memset(vis, 0, n*sizeof(ll));
    ans += dfs(u);
  }
  cout << ans;
  newl;
  rep(u, 0, m) {
    if (~mt[u]) {
      cout << mt[u] + 1 << " " << u + 1;
      newl;
    }
  }

  return 0;
}