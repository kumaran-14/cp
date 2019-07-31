// kumaran_14

// #include <boost/multiprecision/cpp_int.hpp> 
// using boost::multiprecision::cpp_int;  
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
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vull vector<ull>
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

ll tc, k;
// ll ans = 0, c = 0;
ll i, j;
// ll a, b;
// ll x, y;

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    ll n;
    cin>>n;
    vll set(n);
    foi(i, 0, n) cin>>set[i];
    ll sum = 0;
    cin>>sum;
    cout<<sum<<endl;
    // dp logic
          // O(n*sum) space
          // dp[n][sum];
          // vvll dp(n+1, vll(sum+1));
          // foii(i, 0, n) {
          //   dp[i][0] = 1;
          // }
          // foii(i, 1, sum) {
          //   dp[0][i] = 0;
          // }
          // foii(i, 1, n) {
          //   foii(j, 1, sum) {
          //     if(set[i-1] > j) {
          //       dp[i][j] = dp[i-1][j];
          //     } else {
          //       dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
          //     }
          //   }
          // }
          // cout<<dp[n-1][sum]<<endl;

          // O(sum) space.
          // ans = dp[1][sum];
          vvll dp(2, vll(sum+1));
          dp[0][0] = 1;
          dp[1][0] = 1;
          foii(i, 1, sum) {
            dp[0][i] = 0;
          }
          foii(j, 1, n) {
            foii(i, 1, sum) {
              if(set[j-1] > i) {
              dp[1][i] = dp[0][i];
              } else
              dp[1][i] = dp[0][i] || dp[0][i-set[j-1]];
            }
            if(i != sum) {
              dp[0] = dp[1];
            }
            for(auto y:dp[1]) cout<<y<<" ";
            cout<<endl;
          }
          for(auto x:dp) {
              for(auto y:x) {
                cout<<y<<" ";
              }
              cout<<endl;
            }


  }
  return 0;
}


/*
input
1  // testcases
6  //arr size
3 34 7 12 5 3 // arr el
9 // sum:9. Find subset with sum =9;
*/