// kumaran_14
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define p push
#define mp make_pair
#define pb push_back
#define foi(i, a, n) for (i = (a); i < (n); ++i)
#define foii(i, a, n) for (i = (a); i <= (n); ++i)
#define fod(i, a, n) for (i = (a); i > (n); --i)
#define fodd(i, a, n) for (i = (a); i >= (n); --i)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl "\n"
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
ll i, j;
// ll a, b;
// ll x, y;

vvll adjgraph(MAXN);
vll height(MAXN), firstocc(MAXN);

// 1 indexed.
vll segtree;
// 0 indexed.
vll euler;
vector<bool> visited(MAXN, false);
ll root = 1;


void dfs(ll node, ll h = 1) {
  visited[node] = true;
  height[node] = h;
  firstocc[node] = sz(euler);
  euler.pb(node);
  for(auto to: adjgraph[node]) {
    if(!visited[to]) {
      dfs(to, h+1);
      euler.pb(node);
    }
  }
}

// Eg: tree[1] holds the range of all elements of given array. [0, n-1], in this case, [0, m-1];
void buildsegtree(ll treeidx, ll leftidx, ll rightidx) {
  if(leftidx == rightidx) {
    segtree[treeidx] = euler[leftidx];
  } else {
    ll mid = leftidx + ((rightidx - leftidx)/2);
    buildsegtree(treeidx<<1, leftidx, mid);
    buildsegtree(treeidx<<1 | 1, mid+1, rightidx);
    // left_height_idx and right_height_idx;
    ll lnode = segtree[treeidx<<1];
    ll rnode = segtree[treeidx<<1 | 1];
    segtree[treeidx] = (height[lnode] < height[rnode] ? lnode : rnode);
  }
}

// rr is rangeleft, rr is rangeright. for tree[1] = [0, n-1] (all elements)
// qstart(L) and qend(R) is needed query range (inclusive). Eg: [0,3] (for first 4 elements), [3,3]: for the 4th element.
ll querysegtree(ll treeidx, ll leftidx, ll rightidx, ll L, ll R) {
  if(rightidx < L || leftidx > R) return -1;
  if(leftidx >= L && rightidx <= R) {
    return segtree[treeidx];
  }
  ll mid = leftidx + ((rightidx - leftidx)/2);
  ll lnode = querysegtree(treeidx<<1, leftidx, mid, L, R);
  ll rnode = querysegtree(treeidx<<1 | 1, mid+1, rightidx, L, R);
  if(lnode == -1) return rnode;
  if(rnode == -1) return lnode;
  return (height[lnode] < height[rnode] ? lnode : rnode);
}

void initialize() {
  height.assign(n+1, -1);
  firstocc.assign(n+1, -1);
  euler.reserve(2*n + 1); // if size is less, increases size to 2n+1.
}


void precompute() {
  dfs(root);
  m = sz(euler);
  segtree.resize(4*m+1);
  buildsegtree(1, 0, m-1);
}

ll lca(ll u, ll v) {
  ll leftidx = firstocc[u];
  ll rightidx = firstocc[v];
  if(leftidx > rightidx) swap(leftidx, rightidx);
  return querysegtree(1, 0, m-1, leftidx, rightidx);
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  n = 1000;
  //populate adjgraph;
  ll edges;
  cin>>n>>edges;
  foi(i, 0, edges) {
    ll u, v;
    cin>>u>>v;
    adjgraph[u].pb(v);
    adjgraph[v].pb(u);

  }
  initialize();
  precompute();
  return 0;
}
