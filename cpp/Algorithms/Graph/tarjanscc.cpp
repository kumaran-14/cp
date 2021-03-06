// kumaran_14
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define p push
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define foi(i, a, n) for (i = (a); i < (n); ++i)
#define foii(i, a, n) for (i = (a); i <= (n); ++i)
#define fod(i, a, n) for (i = (a); i > (n); --i)
#define fodd(i, a, n) for (i = (a); i >= (n); --i)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl " \n"
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
vll tin(MAXN, -1);
vll low(MAXN, -1);
ll timer, sccidx;
vector<bool> visited(MAXN, false);


void dfs(ll u, ll parent = -1) {
  visited[u] = true;
  for(auto v:adjgraph[u]) {
    if(visited[v]) {
      low[u] = min(low[u], tin[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    }
  }
}



void tarjanscc(ll start) {
  dfs(start);
}

void reset() {
  foii(i, 0, n+1) {
    adjgraph[i].clear();
  }
  fill(all(tin), -1);
  fill(all(low), -1);
  fill(all(visited), false);
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    reset();
    ll start;
    cin>>n>>m>>start;
    foii(i, 1, n) {
      cin>>tin[i];
    }
    foi(i, 0, m) {
      ll u, v;
      cin>>u>>v;
      // directed graph
      adjgraph[u].pb(v);
    }
    tarjanscc(start);
    foi(i, 1, n) {
      cout<<tin[i]<<endl[i==n];
    }
    foi(i, 1, n) {
      cout<<low[i]<<endl[i==n];
    }
  }
  return 0;
}
