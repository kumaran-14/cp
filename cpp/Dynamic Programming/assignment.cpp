// kumaran_14

// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;
#include <bits/stdc++.h>
using namespace std;
// ¯\_(ツ)_/¯
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl " \n"
#define newl cout<<"\n"
#define MAXN 100005                 // 1e5 + 5
#define MOD 1000000007LL            // 1e9 + 7
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18
// ¯\_(ツ)_/¯
#define ll long long int
#define ull unsigned long long int
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vll>
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


int csb (ll n) {
  ll ans = 0;
  ll i = 0;
  while(n >= (1<<i)) {
    if(n&(1<<i)) ans++;
    i++;
  }
  return ans;
};

int main()
{
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif



  ll m = (1<<21);
  cin>>n;
  vvll cost(n, vll(n, 0));
  vll dp(n+1, vll((1<<n), 1e10));
  rep(i, 0, n) rep(j, 0, n) cin>>cost[i][j];

  rep(i, 0, n+1) dp[i][0] = 0;

  // dp bitmask with state {k, mask} - cost to assign 1 to k tasks, with 'mask' as available set of guys
  rep(i, 1, n+1) {
    rep(mask, 0, (1<<(n))) {
      auto bitcount = csb(mask);
      if(bitcount + 1 != i)
        continue;
      rep(j, 0, n) {
        if((mask&(1<<j)) == 0) {
          auto val = cost[bitcount-1][j] + dp[i-1][mask];
          dp[i][mask|(1<<j)] = min(dp[i][mask|(1<<j)], cost[bitcount][j] + dp[bitcount][mask]);
        }

      }
    }
  }
  // tip. It is possible to remove the first dimension. See hackerearth bitmask dp

//  newl;
//  rep(i, 0, sz(dp)) {
//    rep(j, 0, sz(dp[i])) cout<<dp[i][j]<<" ";
//    newl;
//  }


  auto val = csb(0);
  debug(val);
  return 0;


}


/*
input n = number of jobs and number of people available.
n*n matrix contains cost of assigning i'th guy to j'th task.

4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
 */