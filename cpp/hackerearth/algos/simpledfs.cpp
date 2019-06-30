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
#define gcd __gcd
#define mem(a, b) memset(a, b, sizeof a)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl "\n"
#define println(a) cout << (a) << endl
#define PI 3.141592653589793238L
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18

#define l long int
#define d double
#define ll long long int
#define ld long double
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vll>
//vector<vector<int>> v(10, vector<int>(20,500)); 2d vector initialization. of 10 rows and 20 columns.
// Initialization value is 500.
#define si set<int>
#define mii map<int, int>
#define mll map<long long, long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pcc pair<char, char>
#define pdd pair<double, double>

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

ll tc, n, m, k, i, j, x, y, a, b, ans = 0, c = 0;

// graph starts with node 1 <= x <= n;
vvll adjgraph;
vector<ll> color; // 0-unvisited. 1-visited. 2 exited;
vll pre, post;
queue<ll> q;
ll dfs_timer = 0;

void dfs(ll v)
{
  pre[v] = dfs_timer++;
  color[v] = 1;
  for (auto u : adjgraph[v])
  {
    if(color[u] == 0) {
      dfs(u);
    }
  }
  post[v] = dfs_timer++;
  color[v] = 2;
}

int main()
{
  fast_io();
  ll edges;
  cin >> n >> edges;
  adjgraph.resize(n + 1);
  color.resize(n + 1, 0);
  pre.resize(n + 1, 0);
  post.resize(n + 1, -1);
  ll source, u, v;
  cin >> source;
  foii(i, 1, edges)
  {
    cin >> u >> v;
    adjgraph[u].pb(v);
    adjgraph[v].pb(u);
  }
  dfs(source);
  return 0;
}
