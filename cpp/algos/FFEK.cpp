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
// ll i, j;
// ll a, b;
// ll x, y;

vvll capacity(30, vll(30));
vvll adjgraph(30);
vll parent(30);

// edmonds karp;
ll bfs(ll source, ll target) {
  fill(all(parent), -1);
  parent[source] = -2;
  queue<pll> q;
  q.push({source, INFLL});
  while(!q.empty()) {
    ll curr = q.front().f;
    ll currflow = q.front().s;
    q.pop();
    for(auto next:adjgraph[curr]) {
      //not visited and capacity not 0
      if(parent[next] == -1 && capacity[curr][next]) {
        parent[next] = curr;
        ll newflow = min(currflow, capacity[curr][next]);
        if(next == target) return newflow;
        q.push({next, newflow});
      }
    }
  }
  return 0;
}

//ford fulerson.
ll maxflow(ll source, ll target) {
  ll flow = 0;
  ll newflow;
  while(newflow = bfs(source, target)) {
    flow += newflow;
    ll curr = target;
    while(curr != source) {
      ll prev = parent[curr];
      capacity[prev][curr] -= newflow;
      capacity[curr][prev] += newflow;
      curr = prev;
    }
  }
  return flow;
}


int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>m;
  while(m--) {
    ll u, v, cost;
    cin>>u>>v>>cost;
    capacity[u][v] = cost;
    capacity[v][u] = 0;
    adjgraph[u].pb(v);
    adjgraph[v].pb(u);
  }
  ll source = 19;
  ll target = 20;
  cout<<maxflow(source, target);
  return 0;
}
