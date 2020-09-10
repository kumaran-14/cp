// kumaran_14

// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;
#include <bits/stdc++.h>
using namespace std;
// ¯\_(ツ)_/¯
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
#define newl cout<<"\n"
#define MAXN 100005
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18
// ¯\_(ツ)_/¯
#define l long int
#define d double
#define ll long long int
#define ull unsigned long long int
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


int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin>>n>>m;
    vvll adjgraph(n+1);
    vll side(n+1, -1);
    // -1 -> not visited
    // 0 -> visited - set A
    // 1 -> visited - set B

    rep(i, 0, m){
        ll u, v;
        cin>>u>>v;
        adjgraph[u].pb(v);
        adjgraph[v].pb(u);
    }
    int ans = 0;

    bool isBipartite = true;
    queue<ll> q;
    rep(startv ,1, n+1) {
        if(side[startv]!= -1) continue;
        q.push(startv);
        side[startv] = 0;
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            for (auto u:adjgraph[v]) {
                if (side[u] == -1) {
                    side[u] = side[v] ^ 1;
                    q.push(u);
                } else {
                    // neighbour already visited
                    // check for color
                    isBipartite &= side[v] != side[u];
                    if (side[v] == side[u]) ans++;
                }
            }
        }
    }

    return 0;
}

// DFS solution
class Solution {
public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    for(auto& x:dislikes) {
      x[0]--;
      x[1]--;
    }
    vector<vector<int>> graph(n);
    for(auto x:dislikes) {
      graph[x[0]].push_back(x[1]);
      graph[x[1]].push_back(x[0]);
    }

    vector<int> color(n, -1);

    bool ans = true;
    function<void(int, int)> dfs = [&](int u, int val) {
      if(!ans) return;
      if(color[u] == -1) color[u] = val;
      for(auto v:graph[u]) {
        if(color[v] == -1) {
          dfs(v, color[u]^1);
        }
        else if(color[u] == color[v]){
          ans = false;
          return;
        }
      }
    };
    for(int i = 0; i < n; i++) {
      if(color[i] == -1)
        dfs(i, 0);
    }
    return ans;
  }
};

// CSES - problem : building teams uses dfs . See william lin youtube for that.
// Note: ~(-1) = 0
// ~(0) = -1;
