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
const int mxM = 2e5 + 7;
const int inf = 1e9;

ll tc, n, m, k;
vll g[mxN];
ll in[mxN], out[mxN];

vll path;

void dfs(ll u) {
  while(g[u].size()) {
    auto v = g[u].back(); g[u].pop_back();
    dfs(v);
  }
  path.pb(u);
}

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  // directed euler path condition;
  // n-2 vertices with indeg = outdegree
  // atmost 1 vertex with (outdeg-indeg == 1)
  // atmost 1 vertex with (indeg-outdeg == 1)
  // every vertex must be in same connected component; ie size of path = m+1

  // directed euler circuit condition; (cycle)
  // n-2 vertices with indeg = outdegree
  // every vertex must be in same connected component; ie size of circuit = m+1

  // undirected euler path condition;
  // exactly 2 vertices have odd degree
  // n vertices in same connected component, ie size of path = m+1

  // undirected euler circuit condition;
  // n vertices have even degree
  // n vertices in same connected component, ie size of circuit = m+1

  // this problem is cses teleportes path, eu path from 1 to n
  // general problem, from any to any path
  // https://codeforces.com/contest/508/submission/77697447
  cin >> n >> m;

  rep(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    g[u].pb(v);
    out[u]++, in[v]++;
  }
  rep(u, 2, n) {
    if (in[u] != out[u]) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  if (out[1] - in[1] != 1 || in[n] - out[n] != 1) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  dfs(1);

  // all vertices in same component;
  if(path.size() != m+1) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  for(int i = path.size()-1; ~i; i--) cout<<path[i] <<" ";

  return 0;
}