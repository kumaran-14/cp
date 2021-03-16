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

const int mxN = 2e5 + 7;
const int mxM = 2e5 + 7;
const int inf = 1e9;

ll tc, n, m, k;
vll g1[mxN], g2[mxN];
ll vis[mxN], who[mxN];
vll tops, comp;

char ans[mxN];

void dfs1(ll u) {
  vis[u] = 1;
  for (auto v : g1[u]) {
    if (!vis[v])
      dfs1(v);
  }
  tops.pb(u);
}

void dfs2(ll u, ll sccid) {
  vis[u] = 0;
  who[u] = sccid;
  for (auto v : g2[u]) {
    if (vis[v])
      dfs2(v, sccid);
  }
  comp.pb(u);
}

int main() {
  // cses 2sat;
  // all conditions' implications
  /*

    (any one is true or both true )
    (a or b) => !a -> b, !b -> a

    (any one is true but not both true)
    (a xor b) is (a or b) && (!a or !b) => 4edges; (4 implications

    (both same, either (0,0) or (1,1))
    (a <-> b)  is (!a xor b);
   */
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  cin >> n >> m;

  rep(i, 0, n) {
    char a, b;
    ll u, v;
    cin >> a >> u >> b >> v;
    u *= 2, v *= 2;

    if (a == '-')
      u = u ^ 1;
    if (b == '-')
      v = v ^ 1;

    g1[u ^ 1].pb(v);
    g1[v ^ 1].pb(u);
  }
  // since u can be upto 2m or 2m+1
  for (int u = 1; u <= 2 * m + 1; u++) {
    for (auto v : g1[u])
      g2[v].pb(u);
  }

  for (int u = 1; u <= 2 * m + 1; u++) {
    if (!vis[u])
      dfs1(u);
  }

  // reverse process topsort;
  for (int i = tops.size() - 1; i >= 0; i--) {
    auto u = tops[i];
    if (vis[u]) {
      dfs2(u, i);
      comp.clear();
    }
  }

  // check 2 sat condition, x and !x shouldnt be in same component;
  for (int u = 1; u <= m; u++) {
    if (who[u * 2] == who[u * 2 + 1]) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    // usually in topsort order, if comp[x] < comp[!x], then x is false;
    // here, topsort ids are bigger to smaller;
    ans[u] = (who[2 * u] > who[2 * u + 1]) ? '-' : '+';
  }
  for (int u = 1; u <= m; u++) {
    cout << ans[u] << " ";
  }

  return 0;
}

// look for more problems in cp-algorithms, solved door problem.