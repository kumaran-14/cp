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
ll i, j;
// ll a, b;
// ll x, y;

vvll adjgraph(100005);
vvll revadjgraph(100005);
stack<ll> descpost;
vector<bool> visited(100005, false);
ll sccidx = 0;
vvll sccarr(100);

void dfs(ll u)
{
  visited[u] = true;
  for (auto x : revadjgraph[u])
  {
    if (!visited[x])
    {
      dfs(x);
    }
  }
  descpost.push(u);
}

void sccdfs(ll u)
{
  // vis.insert(u);
  visited[u] = true;
  for (auto x : adjgraph[u])
  {
    // if (vis.find(x) == vis.end())
    if (!visited[x])
    {
      sccarr[sccidx].pb(x);
      sccdfs(x);
    }
  }
}

void findscc()
{
  //step 1. order by decreasing post number.
  foii(i, 1, n)
  {
    if (!visited[i])
    {
      dfs(i);
    }
  }
  // step 1. find scc one by one.
  visited.assign(n + 1, false);
  while (!descpost.empty())
  {
    ll top = descpost.top();
    descpost.pop();
    if (!visited[top])
    {
      sccarr[sccidx].pb(top);
      sccdfs(top);
      sccidx++;
    }
  }
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin >> n >> m;
  foi(i, 0, m)
  {
    ll u, v;
    cin >> u >> v;
    adjgraph[u].pb(v);
    revadjgraph[v].pb(u);
  }

  findscc();
  foi(i, 0, sccidx)
  {
    cout << "{";
    for (auto y : sccarr[i])
      cout << y << ", ";
    cout << "}" << endl;
  }
  return 0;
}
