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
// ll i, j;
// ll a, b;
// ll x, y;

vector<vector<pll>> adjgraph(100005);
vll dist(100005, INFLL);
vll rlxncount(100005, 0);
vector<bool> inqueue(100005, false);

bool spfa(ll source)
{
  dist.assign(n + 1, INFLL);
  rlxncount.assign(n + 1, 0);
  queue<ll> q;

  dist[source] = 0;
  q.p(source);
  inqueue[source] = true;
  while (!q.empty())
  {
    ll u = q.front();
    q.pop();
    inqueue[u] = false;
    for (auto v : adjgraph[u])
    {
      ll to = v.f;
      ll cost = v.s;
      if (dist[u] + cost < dist[to])
      {
        dist[to] = dist[u] + cost;
        if (!inqueue[to])
        {
          q.p(to);
          inqueue[to] = true;
          rlxncount[u]++;

          //negative cycle
          if (rlxncount[u] > n)
          {
            cout << "Negative Cycle";
          }
        }
      }
    }
  }
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  n = 100;
  m = 100;
  return 0;
}
