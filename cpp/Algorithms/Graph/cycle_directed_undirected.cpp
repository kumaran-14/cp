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

const int mxN = 1e5 + 5;
const int inf = 1e9;

vll vis(mxN, 0);
int id;
vvll g(mxN);
vll par(mxN);

void dfs(ll u, ll p = -1){
  vis[u] = 1;
  par[u] = p;
  for(auto v:g[u]) {
//    if(v == p) continue; // enable this condition for directed graph;
    if(!vis[v]) {
      dfs(v, u);
    } else if(vis[v] == 1) {
      vi ans = {v};
      for(auto y = u; y^v && ~y; y = par[y], k++) ans.pb(y);
      ans.pb(v);
      reverse(ans.begin(),ans.end());
      cout<<ans.size();
      newl;
      for(auto x:ans) cout<<x<<" ";
      exit(0);
    }
  }
  vis[u] = 2;
}

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  cin>>n>>m;
  rep(i, 0, m) {
    ll u, v;
    cin>>u>>v;
    g[u].pb(v);
//    g[u].pb(v); uncomment for undirected
  }

  rep(u, 1, n+1) {
    if(par[u] == 0) dfs(u);
  }

  cout<<"IMPOSSIBLE";

  return 0;
}