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

const ll maxn = 2e5 + 7;
ll lg = 20;
ll timer = 0;
vvll adj(maxn);
vll tin(maxn), tout(maxn), h(maxn);
vvll up(maxn, vll(lg+1));


void dfs(ll u, int p) {
  tin[u] = ++timer;
  up[u][0] = p;
  for (int i = 1; i <= lg; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  h[u] = u != p ? h[p]+1 : 0;
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  tout[u] = timer;
}

// check if u is a ancestor of v
bool is_ancestor(ll u, ll v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

// check if u is a ancestor of v
int lca(ll u, ll v) {
  if (is_ancestor(u, v))
    return u;
  if (is_ancestor(v, u))
    return v;
  for (int i = lg; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v))
      u = up[u][i];
    // if(!isancestor(up[u][i], v) && up[u][i]); as up[u][i] can be 0;
  }
  return up[u][0];
}

// kth ancestor of u
ll lift(ll u, ll k) {
  rep(i, 0, lg+1) {
    if(k&(1<<i)) u = up[u][i];
  }
  return u;
}


int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  // https://codeforces.com/contest/519/problem/E
  cin >> n;
  rep(i, 0, n - 1) {
    ll a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  // use dfs(root, root) for [1...n] indexing. this implementation does not use -1 anywhere. So use dfs(root, root) always.
  dfs(1, 1);
  cin >> k;
  while (k--) {
    ll a, b;
    cin >> a >> b;
    if(a == b) {
      cout<<n;
      newl;
      continue;
    }
    ll ans = 0;
    ll anc = lca(a, b);
    ll len = h[a] + h[b] -2*h[anc];
    ll k_1 = len/2 -1;
    if(h[a] == h[b]) {
      ll k_1_anc_a = lift(a, k_1);
      ll k_1_anc_b = lift(b, k_1);
      ans = -1 + (tout[1]-tin[1]) - (tout[k_1_anc_a]-tin[k_1_anc_a]) - (tout[k_1_anc_b]-tin[k_1_anc_b]);
    } else {

      if(h[a] < h[b]) swap(a, b);
      if(len%2 == 0) {
        ll k_a = lift(a, len/2);
        ll k_1anc_a = lift(a, k_1);
        ans = (tout[k_a]-tin[k_a]) - (tout[k_1anc_a]-tin[k_1anc_a]);
      }
    }
    cout<<ans;
    newl;
  }
}
// input
/*
8
1 2
2 3
2 4
2 5
5 6
6 7
6 8
7
3 5
3 6
3 8
5 8
7 3
5 7
5 5

*/
// https://csacademy.com/app/graph_editor/