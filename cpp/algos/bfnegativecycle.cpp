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
// ll ans = 0, c = 0;
ll i, j;
// ll a, b;
// ll x, y;

struct Edge
{
  // a , b are vectices. 1 <= a, b <= n
  ll a, b, cost;
};

// edgelist indexed from 0.
vector<Edge> edgelist;
vll dist(100005, INFLL);
vll parent(100005, -1);
ll cycle_end;

void printarr(vll arr)
{
  for (auto x : arr)
    cout << x << " ";
  cout << endl;
}

void findnegativecycle(ll x)
{
  foi(i, 0, n)
  {
    x = parent[x];
  }
  vll cyclearr;
  for (ll v = x;; v = parent[v])
  {
    cyclearr.pb(v);
    if (v == x && sz(cyclearr) > 1)
      break;
  }
  reverse(all(cyclearr));
  cout << "Negative cycle: ";
  printarr(cyclearr);
}

//single source shortest path
void bellmanford(ll source)
{
  // a negative cycle reachable from source,  then other vertex dist at starting is INFLL
  dist.assign(n + 1, INFLL);
  // a negative cycle not reachable from source, or general case, find any negative cycle,  then other vertex dist at starting is 0.
  // dist.assign(n + 1, 0);
  parent.assign(n + 1, -1);
  dist[source] = 0;
  // nth time is the time we check for negative cycle.
  foi(i, 0, n)
  {
    cycle_end = -1;
    for (auto edge : edgelist)
    {
      auto curr = edge.a;
      auto next = edge.b;
      auto cost = edge.cost;
      if (dist[next] > dist[curr] + cost)
      {
        // for integer overflow
        dist[next] = max(-INFLL, dist[curr] + cost);
        parent[next] = curr;
        cycle_end = next;
      }
    }
  }
  if (cycle_end == -1)
  {
    cout << "No negative cycle" << endl;
  }
  else
  {
    findnegativecycle(cycle_end);
  }
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  //vertices
  n = 1000;
  //edges;
  m = 100;
  cin >> n >> m;
  foi(i, 0, m)
  {
    ll u, v, cost;
    cin >> u >> v >> cost;
    struct Edge edge = {u, v, cost};
    edgelist.pb(edge);
    // struct Edge edge2 = {v, u, cost};
    // edgelist.pb(edge2);
  }
  // a negative cycle reachable from source,  then other vertices dist at starting is INFLL
  // a negative cycle not reachable from source, or general case, find any negative cycle,  then other vertices dist at starting is 0.
  // choose accordingly in the function.
  bellmanford(5);
  return 0;
}
