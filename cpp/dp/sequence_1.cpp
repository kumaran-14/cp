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
#define MAXN 100005
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18
// ¯\_(ツ)_/¯ 
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
ll ans = 0, c = 0;
// ll a, b;
// ll x, y;

// void seq2seq(ll n, ll m) {
//   if((n == 1 && m >= 1)) {
//     ans++;
//   }
//   if(n <= 0) return;
//   ll i;
//   foii(i, 1, m/2) {
//     seq2seq(n-1, i);
//   }
// }


int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    cin>>m>>n;
    // ans = 0;
    // ll i;
    // foii(i, 1, m) {
    //   seq2seq(n, i);
    // }
    // cout<<ans<<endl;
    ll i, j;
    vvll dp(n+1, vll(m+1, 0));
    foii(i, 1, m) {
      dp[1][i] = 1;
    }
    foii(i, 1, n) {
      foii(j, 1, m) {
        if(i == 1) {
          dp[i][j] = j;
        } else {
          dp[i][j] = dp[i][j-1] + dp[i-1][j/2];
        }
      }
    }
    cout<<dp[n][m]<<endl;
  }
  return 0;
}


/*
https://www.geeksforgeeks.org/sequences-given-length-every-element-equal-twice-previous/

2
3
abc
5
axxxy
*/

