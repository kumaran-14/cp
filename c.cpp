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

const int mxN = 1e5 + 5;
const int inf = 1e9;

ll tc, n, m, k;
vll g[2][mxN];
ll coins[mxN], vis[mxN];
vll comp[mxN];
ll scc = 0;

vll topo;

void dfs(ll u, ll t) {
  vis[u] = 1;
  if(t == 1) comp[scc].pb(u);
  for(auto v:g[t][u]) {
    if(!vis[v]) dfs(v, t);
  }
  if(t==0) topo.pb(u);
}

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  cin >> n >> m;
  rep(u, 1, n+1) cin>>coins[u];

  rep(i, 0, m) {
    ll u, v;
    cin>>u>>v;
    g[0][u].pb(v);
    g[1][v].pb(u);
  }
  rep(u, 1, n+1) {
    if(!vis[u]) {
      scc++;
      dfs(u, 0);
    }
  }

  rep(u, 1, n+1) vis[u] = 0;

  rep(i, n, 0) {
    auto u = topo[i];
    if(!vis[u]) dfs(u, 1);
  }






  return 0;
}