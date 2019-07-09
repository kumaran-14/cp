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

struct edge
{
  // a , b are vectices. 1 <= a, b <= n
  ll a, b, cost;
};

// edgelist indexed from 0.
vector<edge> edgelist;
vll dist(100005, INFLL);
vll parent(100005, -1);

//single source shortest path
void bellmanford(ll source)
{
  dist.assign(n + 1, INFLL);
  parent.assign(n + 1, -1);
  dist[source] = 0;
  // until relaxation takes place for atleast one edge
  for (;;)
  {
    bool isrelaxed = false;
    foi(i, 0, m)
    {
      auto curr = edgelist[i].a;
      auto next = edgelist[i].b;
      auto cost = edgelist[i].cost;
      if (dist[curr] < INFLL)
      {
        if (dist[next] > dist[curr] + cost)
        {
          dist[next] = dist[curr] + cost;
          parent[next] = curr;
          isrelaxed = true;
        }
      }
    }
    if(!isrelaxed) {
      break;
    }
  }
}

vll restore_path(ll source, ll dest) {
    vll path;
    if(dist[dest] == INFLL) {
      // no path.
      return path;
    }
    for(ll v = dest; v != source; source = parent[v]) {
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
  //vertices
  n = 1000;
  //edges;
  m = 100;
  return 0;
}
