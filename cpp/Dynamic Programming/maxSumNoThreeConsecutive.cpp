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
// ll ans = 0, c = 0;
ll i, j;
// ll a, b;
// ll x, y;
vll arr(MAXN);
int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    cin>>n;
    vll arr(n+1), dp(n+1, 0);
    foii(i, 1, n) cin>>arr[i];
    foii(i, 1, n) {
      if(i-3 >= 0) {
        dp[i] = max(dp[i-1], max(arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3]));
      } else {
        dp[i] += arr[i] + dp[i-1];
      }
    }

    // No two elements are adjacent
    /*
    foii(i, 1, n) {
      if(i-2 >= 0) {
        dp[i] = max(dp[i-1], arr[i] + dp[i-2]);
      } else {
        dp[i] += arr[i] + dp[i-1];
      }
    }
    */
    for(auto x:dp) cout<<x<<" ";
    cout<<endl;
  }
  return 0; 
}


/*

4
5
100 1000 100 1000 1
3
1 2 3
5
1 1 1 1 1
5
3000 2000 1000 3 10

*/

