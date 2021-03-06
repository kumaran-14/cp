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

ll tc, n, m, k;
ll i, j;
// ll ans = 0, c = 0;
// ll a, b;
// ll x, y;
vector<vector<pll>> adjgraph(100005);
vll dist(100005, INFLL);
vll parent(100005, -1);
vector<bool> visited(100005, false);

void dijkstra(ll source)
{
  dist.assign(n + 1, INFLL);
  parent.assign(n + 1, -1);

  dist[source] = 0;
  //pll => {dist, vertex}
  priority_queue<pll, vector<pll>, greater<pll>> q;
  //optimization: we dont need to store pair, only vertex. Overload with custom comparator for set which compares based on dist.
  q.push({0, source});
  while (!q.empty())
  {
    ll v = q.top().second;
    ll d_v = q.top().first;
    q.pop();
    if (d_v != dist[v])
      continue;

    for (auto edge : adjgraph[v])
    {
      ll next = edge.f;
      ll cost = edge.s;

      if (dist[v] + cost < dist[next])
      {
        dist[next] = dist[v] + cost;
        parent[next] = v;
        q.push({dist[next], next});
      }
    }
  }
}

vll restore_path(ll source, ll dest)
{
  vll path;
  for (ll v = dest; v != source; v = parent[v])
  {
    path.pb(v);
  }
  path.pb(source);
  reverse(all(path));
  return path;
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  return 0;
}
