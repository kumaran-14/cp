// kumaran_14
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define p push
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define foi(i, a, n) for (i = (a); i < (n); ++i)
#define foii(i, a, n) for (i = (a); i <= (n); ++i)
#define fod(i, a, n) for (i = (a); i > (n); --i)
#define fodd(i, a, n) for (i = (a); i >= (n); --i)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl " \n"
#define MAXN 100005
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18

#define l long int
#define d double
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vll>
//vector<vector<int>> v(10, vector<int>(20,500)); 2d vector initialization. of 10 rows and 20 columns, with value 500.
#define mii map<int, int>
#define mll map<long long, long long>
#define pii pair<int, int>
#define pll pair<long long, long long>

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

ll tc, n, m, k;
// ll ans = 0, c = 0;
// ll a, b;
// ll x, y;

vvll adjgraph(MAXN);
vll tin(MAXN), tout(MAXN);
vvll up(MAXN);
ll timer = 0;
ll maxdepth;

void dfs(ll u, ll parent) {
  ll i, j;
  tin[u] = ++timer;
  up[u][0] = parent;
  foii(i, 1, maxdepth) {
    up[u][i] = up[up[u][i-1]][i-1];
  }
  for(auto v:adjgraph[u]) {
    if(v != parent) {
      dfs(v, u);
    }
  }
  tout[u] = ++timer;
}
// u is ancestor of v
bool is_ancestor(ll u, ll v) {
  return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

ll lca(ll u, ll v) {
  ll i, j;
  if(is_ancestor(u, v)) return u;
  if(is_ancestor(v, u)) return v;
  fodd(i, maxdepth, 0) {
    if(!is_ancestor(up[u][i], v)) {
      u = up[u][i];
    }
  }
  return up[u][0];
}

void precompute(ll root) {
  timer = 0;
  maxdepth = ceil(log2(n));
  up.assign(n+1, vll(maxdepth+1));
  dfs(root, root);
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  ll i, j;
  cin>>n>>m;
  foi(i, 0, m) {
    ll u, v;
    cin>>u>>v;
    adjgraph[u].pb(v);
  }
  precompute(1);
  return 0;
}
