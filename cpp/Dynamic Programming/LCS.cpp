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


// two strings
void lcs() {
  ll ans = INT_MIN;
  cin>>n>>m;
  string stn, stm;
  cin>>stn>>stm;
  vvll dp(n+1, vll(m+1, 0));
  foii(i, 1, n) {
    foii(j, 1, m) {
      if(stn[i-1] == stm[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout<<ans<<endl;
}

// three strings;
void lcs_3() {
  ll ans = INT_MIN;
  ll n1, n2, n3;
  cin>>n1>>n2>>n3;
  string stn, stm, stk;
  cin>>stn>>stm>>stk;
  vector<vvll> dp(n1+1, vvll(n2+1, vll(n3+1, 0)));
  foii(i, 1, n1) {
    foii(j, 1, n2) {
      foii(k, 1, n3) {
        if(stn[i-1] == stm[j-1] && stm[j-1] == stk[k-1]) {
          dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
        } else {
          dp[i][j][k] = max(dp[i][j-1][k], max(dp[i-1][j][k], dp[i][j][k-1]));
        }
        ans = max(ans, dp[i][j][k]);
      }
    }
  }
  cout<<ans<<endl;
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    // lcs();
  }
  return 0; 
}


/*
//two strings
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

// three strings
1
5 8 13
geeks geeksfor geeksforgeeks

*/

