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

// pll -> {vertex, distance}
vector<vector<pll>> adjgraph(100005);
vector<bool> visited(100005, false);

ll prim(ll source)
{
  ll mincost = 0;
  // pll -> {distance , vertex}
  priority_queue<pll, vector<pll>, greater<pll>> q;
  q.push({0, source});
  while (!q.empty())
  {
    pll v = q.top();
    q.pop();
    if (visited[v.s])
      continue;
    mincost += v.f;
    visited[v.s] = true;
    for (auto u : adjgraph[v.s])
    {
      // u -> {vertex, distance}
      if (!visited[u.f])
      {
        q.push({u.s, u.f});
      }
    }
  }
  return mincost;
}

int main()
{
  fast_io();
  // freopen("./input.txt", "r", stdin);
  // freopen("./output.txt", "w", stdout);
  return 0;
}
