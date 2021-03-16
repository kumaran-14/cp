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

const int mxN = 1e5 + 7;
const int mxM = 2e5+7;
const int inf = 1e9;

ll tc, n, m, k;
vector<pll> g[mxN];
ll vis[mxM];
vll ans;

void dfs(ll u) {
  while(g[u].size()) {
    auto [v, i] = g[u].back();
    g[u].pop_back();
    if(vis[i]) continue;
    vis[i] = 1;
    dfs(v);
  }
  ans.pb(u);
}

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  cin >> n >> m;

  rep(i, 0, m) {
    ll u, v;
    cin>>u>>v;
    g[u].pb({v, i});
    g[v].pb({u, i});
  }
  rep(u, 1, n+1) {
    if(g[u].size()&1) {
      cout<<"IMPOSSIBLE";
      return 0;
    }
  }


  dfs(1);



  if(ans.size() != m+1) {
    cout<<"IMPOSSIBLE";
    return 0;
  }
  for(auto x:ans) cout<<x<<" ";

  return 0;
}