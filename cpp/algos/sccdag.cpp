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

//indexed from 1
vvll adjgraph(100005);
vvll revadjgraph(100005);
vector<pll> edgelist;
stack<ll> topsortstack;
vector<bool> visited(100005, false);

//indexed from 1, because of sccidx.
ll sccidx = 1;
vll paintscc(100005, -1), dagdepth(100005, 0);
vvll dag(100005);
vvll sccarr(100005);

void resetdfs() {
  // n+1 or max number of scc +1, but n+1 >= scc_count + 1
  visited.assign(n + 1, false);
}

// topsort revadjgraph
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
  topsortstack.push(u);
}

// parse scc
void sccdfs(ll u)
{
  visited[u] = true;
  for (auto x : adjgraph[u])
  {
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
  // step 2. find scc one by one.
  resetdfs();
  while (!topsortstack.empty())
  {
    ll top = topsortstack.top();
    topsortstack.pop();
    if (!visited[top])
    {
      //sccarr starts from index 1; 
      sccarr[sccidx].pb(top);
      sccdfs(top);
      sccidx++;
      // at last counter goes extra by 1.
    }
  }
}

// topsort dag
void dfs2(ll u)
{
  visited[u] = true;
  for (auto x : dag[u])
  {
    if (!visited[x])
    {
      dfs2(x);
    }
  }
  topsortstack.push(u);
}


void identifyscc() {
  foi(i, 1, sccidx) {
    for(auto u:sccarr[i]) {
      paintscc[u] = i;
    }
  }
}

void builddag() {
  ll u, v;
  foi(i, 0, m) {
    u = edgelist[i].f;
    v = edgelist[i].s;
    if(paintscc[u] != paintscc[v]) {
      dag[paintscc[u]].pb(paintscc[v]);
    }
  }
}

void topsort_dag() {
  resetdfs();
  foi(i, 0, sccidx) {
    if(!visited[i]) {
      dfs2(i);
    }
  }
  while(!topsortstack.empty()) {
    //least indegree element;
    ll top = topsortstack.top();
    topsortstack.pop();
    for(auto v:dag[top]) {
      dagdepth[v] = max(dagdepth[v], dagdepth[top] + 1);
    }
  }

}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin >> n >> m;
  ll u, v;
  foi(i, 0, m)
  {
    cin >> u >> v;
    adjgraph[u].pb(v);
    revadjgraph[v].pb(u);
    edgelist.pb({u, v});
  }

  findscc();          // populates sccarr
  identifyscc();      // paints scc by id
  builddag();         // new dag by scc id (1 to sccidx-1);
  topsort_dag();

  ll maxdepth = INT_MIN;
  foi(i,1, sccidx) {
    maxdepth = max(maxdepth, dagdepth[i]);
  }
  cout<<maxdepth;
  return 0;
}
