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

//some special constants;
#define NO_COLOR 0 //unvisited
#define GREY 1     //entered
#define BLACK 2    //exited and visited fully.
vvll adjgraph(100005);
vector<ll> color;
vll parent(100005);
ll cycle_start, cycle_end;

bool dfs(ll u)
{
  color[u] = GREY;
  for (auto v : adjgraph[u])
  {
    if (color[v] == NO_COLOR)
    {
      parent[v] = u;
      if (dfs(v))
        return true;
    }
    else if (color[v] == GREY)
    {
      cycle_end = u;
      cycle_start = v;
      return true;
    }
  }
  color[u] = BLACK;
  return false;
}

void usecycle()
{
  ll u = cycle_end;
  vll cyclearr;
  while (u != cycle_start)
  {
    cyclearr.pb(u);
    u = parent[u];
  }
  cyclearr.pb(cycle_start);
  reverse(all(cyclearr));
  cout << "Cycle found" << endl;
  for (auto x : cyclearr)
    cout << x << " --> ";
}

void find_cycle()
{
  color.assign(n + 1, NO_COLOR);
  parent.assign(n + 1, -1);
  cycle_start = -1;

  foii(i, 1, n)
  {
    if (dfs(i))
      break;
  }
  if (cycle_start == -1)
  {
    cout << "Acyclic" << endl;
  }
  else
  {
    usecycle();
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
    // adjgraph[v].pb(u);
  }
  find_cycle();
  return 0;
}
