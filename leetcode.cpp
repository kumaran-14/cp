#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define db(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mxN 1e7
#define newl cout << "\n"
#define vi vector<int>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define f first
#define s second
#define mp make_pair
#define sz(x) ((int)(x).size())
#define nl cout << "\n"

#define ll long long int
#define ld long double
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long, long long>

typedef pair<int, pair<int, int>> threepair;

struct Node {
  int time, u;
  Node(int time, int u) : time(time), u(u) {}
  bool operator<(Node other) const {
    return time > other.time;
  }
};
class Solution {
public:
  vll time;
  vvll g;
  vll mxtime;
  ll dfs(ll u, ll p = -1) {

    if(p == -1) time[u] = 0;
    else {
      if(u%2) time[u] = time[p]+1;
      else time[u] = time[p]+2;
    }
    mxtime[u] = time[u];
    ll a = -1, b = -1;
    for(auto v:g[u]) {
      if(v == p)
        continue;
      dfs(v, u);
      mxtime[u] = max(mxtime[u], mxtime[v]);
      if(a == -1) a = v;
      else {
        if(mxtime[v] > mxtime[a]) {
          b = a;
          a = v;
        } else if(mxtime[v] < mxtime[a] && (b == -1 || mxtime[v] > mxtime[b])) b = v;
      }
    }
    for(auto v:g[u]) {
      if(v == p)
        continue;

      if(a != -1) {
        if(b == -1) {
          ans[v] = ans[u]

        } else {

        }
      }
    }
    return mxtime[u];

  }
  void dfs2(ll u, ll p) {


  }
  vector<int> timeTaken(vector<vector<int>>& edges) {

  }
};
int main() {
  freopen("../output.txt", "w", stdout);

  auto sol = Solution();
  vector<vector<int>> arr(200, vector<int>(200, 0));
  auto res = sol.findKthLargest({3,2,1,5,6,4}, 2);
  debug(res);
//  vector<int> v;

}
