#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define db(x) cout << '>' << #x << ':' << x << endl;
#define sz(x) ((int)(x).size())
#define newl cout << "\n"

#define ll long long int
#define vi vector<int>
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long, long long>

#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

ll tc, n, m, k;

const int mxN = 1e3 + 5;
const int inf = 1e9;
vvll isfloor(mxN, vll(mxN, 0));
vvll vis(mxN, vll(mxN, 0)), par(mxN, vll(mxN, 0));

vll dx = {-1, 0, 1, 0};
vll dy = {0, -1, 0, 1};

/*
void dfs(ll x, ll y) {
  vis[x][y] = 1;
  rep(i, 0, 4) {
    ll u = x+dx[i];
    ll v = y+dy[i];
    if(u < 0 || u >= n || v < 0||  v >= m || !isfloor[u][v] || vis[u][v])
continue; dfs(u, v);
  }
}
*/

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  cin >> n >> m;
  ll sx, sy, ex, ey;
  rep(i, 0, n) {
    string str;
    cin >> str;
    rep(j, 0, m) {
      char ch = str[j];
      if (ch == '#') {

      } else {
        if (ch == 'A') {
          sx = i, sy = j;
        } else if (ch == 'B') {
          ex = i, ey = j;
        }
        isfloor[i][j] = 1;
      }
    }
  }

  par[sx][sy] = -1;
  queue<array<ll, 2>> pq;
  pq.push({sx, sy});
  string dir = "ULDR";
  while (!pq.empty()) {
    auto top = pq.front();
    auto x = top[0], y=  top[1];

    pq.pop();
    vis[x][y] = 1;
    if (x == ex && y == ey) {
      // backtrack to find string;
      string ans = "";
      int k = par[x][y];
      while(k != -1) {
        x -= dx[k];
        y -= dy[k];
        ans += (dir[k]);
        k = par[x][y];
      }
      reverse(ans.begin(), ans.end());
      cout << "YES";
      newl;
      cout<<sz(ans);
      newl;
      cout<<ans;
      return 0;
    }
    rep(i, 0, 4) {
      ll u = x + dx[i];
      ll v = y + dy[i];
      if (u < 0 || u >= n || v < 0 || v >= m || !isfloor[u][v] || vis[u][v])
        continue;
      vis[u][v] = 1;
      par[u][v] = i;
      pq.push({u, v});
    }
  }

  cout << "NO";

  return 0;
}

// cses labyrinth