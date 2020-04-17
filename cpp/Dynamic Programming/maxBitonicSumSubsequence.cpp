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

// O(n^2)
void LIS_1(ll pp) {
  ll ans = INT_MIN;
  cin>>n;
  vll arr(n+1, 0);
  foi(i, 0, n) cin>>arr[i]; 

  // max sum decreasing subsequence starting from left to right
  vll dp1(n+1, 0), dp2(n+1, 0);
  dp1[n-1] = arr[n-1];
  fodd(i, n-2, 0) {
    foi(j, i+1, n) {
      if(arr[i] > arr[j]) {
        dp1[i] = max(dp1[i], arr[i] + dp1[j]);
      }
    }
    dp1[i] = max(dp1[i], arr[i]);
  }

  // max sum increasing subsequence starting from left to right
  dp2[0] = arr[0];
  foi(i, 1, n) {
    foi(j, 0, i) {
      if(arr[i] > arr[j]) {
        dp2[i] = max(dp2[i], arr[i] + dp2[j]);
      }
    }
    dp2[i] = max(dp2[i], arr[i]);
  }


  foi(i, 0, n) ans = max(ans, dp1[i] + dp2[i] - arr[i]);
  cout<<ans<<endl;

}

// longest bitonic subsequence using two lis.
void LIS_2() {
    vll dpi(n, 0), dpd(n, 0);
    dpi[0] = 1;
    dpd[n-1] = 1;
    vll nums(n, 0);
    rep(i, 0, n) cin>>nums[i];
    rep(i, 1, n) {
        ll mx = 0;
        rep(j, 0, i)
            if(nums[j] < nums[i])
                mx = max(mx, dpi[j]);
        dpi[i] += mx + 1;
    }
    rep(i, n-1, 0) {
        ll mx = 0;
        rep(j, n, i+1)
            if(nums[j] < nums[i])
                mx = max(mx, dpd[j]);
        dpd[i] += mx + 1;
    }
//        rep(i, 0, n) cout<<dpi[i]<<endl[i==n-1];
//        rep(i, 0, n) cout<<dpd[i]<<endl[i==n-1];

    ll ans = INT_MIN;
    rep(i, 0, n) ans = max(ans, dpi[i] + dpd[i] - 1);
    cout<<ans<<endl;
}


int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    LIS_1(tc);
  }
  return 0; 
}


/*

2
6
80 60 30 40 20 10
9
1 15 51 45 33 100 12 18 9
*/

