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
#define ll long long int
#define vll vector<ll>

typedef pair<int, pair<int, int>> threepair;


class Solution {
public:

  int maximumScore(vector<int>& arr, vector<vector<int>>& edges) {
    int n = arr.size();
    vi cond(n, 1);
    vector<vector<ll>> g(n);
    for(auto& e : edges) {
      g[e[0]].pb(e[1]);
      g[e[1]].pb(e[0]);
    }
    ll res = cal(cond, g);
    cout<<res<<"\n";
    if(res >= 4) return cal(arr, g);

    return -1;

  }

};

int main() {
  freopen("../output.txt", "w", stdout);

  auto sol = Solution();
  vi a = {1, 1, 1, 1};
  vi b = {811,364,124,873,790,656,581,446,885,134};
  vi arr = {4,1,5,2,6,2};
  vi pf = {1, 2, 3, 6};
  auto res = sol.kIncreasing(a, 3);
  db(res);
//  vector<int> v;

}
