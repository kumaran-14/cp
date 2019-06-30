// kumaran_14
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define p push
#define mp make_pair
#define pb push_back
#define foi(i, a, n) for ( i = (a); i < (n); ++i)
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
#define INFI 1000000000 // 10^9
#define INFLL 1000000000000000000ll //10^18

#define l long int
#define d double
#define ll long long int
#define ld long double
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vll vector<long long>
#define vvi vector<vector <int>>
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

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll tc, n, m, k, i, j, x, y, a, b, u, v, ans = 0, c = 0;

// graph starts with node 1 <= x <= n;
vvll adjgraph;
vector<bool> visited;
// map<ll, ll> visited;
vll dist, btpath;
queue<ll> q;

int main() {
  fast_io();
  ll edges;
  cin >> n >> edges;
  adjgraph.resize(n + 1);
  visited.resize(n + 1, false);
  dist.resize(n + 1, 0);
  btpath.resize(n + 1, -1);
  foii(i, 1, edges) {
    cin >> u>>v;
    adjgraph[u].pb(v);
    adjgraph[v].pb(u);
  }
  //start from source;
  ll source;
  cin >> source;
  q.p(source);
  visited[source] = true;
  dist[source] = 0;
  btpath[source] = 0;
  while (!q.empty())
  {
    u = q.front();
    q.pop();
    for(auto v:adjgraph[u]) {
      if(!visited[v]) {
        visited[v] = true;
        q.p(v);
        dist[v] = dist[u] + 1;
        btpath[v] = u;
      }
    }
  }
  // cout << "levels endl";
  // foii(i, 1, n)
  // {
  //   cout << i << " " << dist[i] << endl;
  // }
  //   cout << "path endl";
  // foii(i, 1, n)
  // {
  //   cout << i << " " << btpath[i] << endl;
  // }

  return 0;
}
// input;
// n edges
// 'edges' lines of graph input eg: 1 3 // edge between 3 and 1.
// source;
