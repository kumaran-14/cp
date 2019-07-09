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

// indexed from 1;
// undirected graph.
#define NIL -1
ll timer;
vvll adjgraph(100005);
vll entrytime(100005, -1);
vll low(100005, -1);
vector<bool> visited(100005, false);
set<ll> cutpoints;
vector<pll> cutedges; 


//handle found cutpoint;
void iscutpoint(ll v) {
  if(cutpoints.find(v) == cutpoints.end()) {
    cutpoints.insert(v);
  }
}

void isbridge(ll v, ll to) {
  cutedges.pb({v, to});
}


//finding cutpoint.
// three cases:
/*
  to=parent - the edge leads back to parent in DFS tree.
  visited[to]=true && to≠parent - the edge is back edge to one of the ancestors;
  visited[to]=false - the edge is part of DFS tree;
*/
void dfs(ll v, ll parent = NIL) {
  visited[v] = true;
  entrytime[v] = low[v] = timer++;
  ll children = 0;
  for(auto to:adjgraph[v]) {
    if (to == parent) continue;
    if(visited[to]) {
      low[v] = min(low[v], entrytime[to]);
    } else {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      // low[to] = entrytime[v] => means backedge from 'to' --> 'v'.
      // low[to] < entrytime[v] => means backedge from 'to' --> some ancestor of 'v'
      if((low[to] >= entrytime[v] && parent != NIL)) {
        //cutpoint found;
        iscutpoint(v);
      }
      if(low[to] > entrytime[v]) {
        //bridge found;
        isbridge(v, to);
      }
      ++children;
    }
  }
  // hande root node case
  if(parent == NIL && children > 1) {
    iscutpoint(v);
  }
}




void find_cutpoints() {
  ll timer = 0;
  visited.assign(n+1, false);
  entrytime.assign(n+1, NIL);
  low.assign(n+1, NIL);
  foii(i, 1, n) {
    //dfs for each cc in undirected graph.
    if(!visited[i]) {
      dfs(i);
    }
  }
}

bool customcomp(pll& p1, pll& p2) {
  if(p1.f == p2.f) return p1.s < p2.s;
  else return p1.f < p2.f;
}


int main()
{
  fast_io();
  // freopen("./input.txt", "r", stdin);
  // freopen("./output.txt", "w", stdout);
  n = 100001;
  cin>>n>>m;
  foi(i, 0, m) {
    ll u, v;
    cin>>u>>v;
    adjgraph[u+1].pb(v+1);
    adjgraph[v+1].pb(u+1);
  }
  find_cutpoints();
  cout<<sz(cutpoints)<<endl;
  for(auto x: cutpoints) {
    cout<<x-1<<" ";
  }
  cout<<endl;
  sort(all(cutedges), customcomp);
  cout<<sz(cutedges)<<endl;
  for(auto x:cutedges) {
    cout<<x.f-1<<" "<<x.s-1<<endl;
  }
  return 0;
}
