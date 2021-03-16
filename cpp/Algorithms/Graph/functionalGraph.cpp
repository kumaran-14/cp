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

const int mxN = 2e5 + 5;
const int inf = 1e9;

ll lg = 20;
ll up[mxN][21];
ll vis[mxN], which[mxN], d[mxN], pos[mxN];

vll adj[mxN], g[mxN];

ll lift(ll u, ll k) {
  assert(k >= 0);
  rep(i, 0, lg) {
    if (k & (1 << i))
      u = up[u][i];
  }
  return u;
}

int main() {
  // cses task planet queries II
  // functional graph is a graph of many components;
  // each component has the following structure;
  // a cycle of root nodes, from each root, a tree may or may not exist, if it exists, the tree will be inverted;

  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  ll Q;
  cin >> n >> Q;
  rep(u, 1, n + 1) {
    cin >> up[u][0];
    g[up[u][0]].pb(u);
  }

  rep(i, 1, lg+1) {
    rep(u, 1, n + 1) { up[u][i] = up[up[u][i - 1]][i - 1]; }
  }

  vvll cyc;
  set<ll> cy;
  rep(u, 1, n + 1) { cy.insert(lift(u, n + 5)); }
  queue<ll> q;

  for (auto u : cy) {
    if (vis[u])
      continue;
    vll cycle = {u};
    vis[u] = 1;
    auto x = up[u][0];
    while (x != u) {
      vis[x] = 1;
      cycle.pb(x);
      x = up[x][0];
    }
    // cycle now contains the root cycle;
    for (int i = 0; i < cycle.size(); i++) {
      auto u = cycle[i];
      pos[u] = i;
      d[u] = 0;
      q.push(u);
      which[u] = cyc.size(); // component id = id of cycle in functional graph
    }
    cyc.pb(cycle);
  }

  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (vis[v])
        continue;
      vis[v] = 1;
      d[v] = d[u] + 1;
      q.push(v);
      which[v] = which[u];
    }
  }

  while (Q--) {
    ll a, b;
    cin >> a >> b;
    ll ans = -1;
    if (which[a] != which[b])
      ans = -1;
    else if (d[a] < d[b])
      ans = -1;
    else if (d[b] != 0) {
      if (lift(a, d[a] - d[b]) == b)
        ans = d[a] - d[b];
      else
        ans = -1;
    } else if (d[b] == 0) {
      // b = 0, a = 0 or non zero;
      auto c = lift(a, d[a]);
      ans = d[a] +
          (pos[b] - pos[c] + cyc[which[a]].size()) % cyc[which[a]].size();
    }
    cout << ans;
    newl;
  }

  return 0;
}

