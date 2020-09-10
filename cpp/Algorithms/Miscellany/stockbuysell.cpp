//
// Created by kumaran on 4/18/20.
//

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
#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define foi(i, a, n) for (i = (a); i < (n); ++i)
#define foii(i, a, n) for (i = (a); i <= (n); ++i)
#define fod(i, a, n) for (i = (a); i > (n); --i)
#define fodd(i, a, n) for (i = (a); i >= (n); --i)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl " \n"
#define newl cout << "\n"
#define MAXN 100005
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll // 10^18
// ¯\_(ツ)_/¯
//#define l long int
//#define d double
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vll>
#define vvld vector<vector<ld>>

// vector<vector<int>> v(10, vector<int>(20,500)); 2d vector initialization. of
// 10 rows and 20 columns, with value 500.
#define mii map<int, int>
#define mll map<long long, long long>
#define pii pair<int, int>
#define pll pair<long long, long long>

#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

ll tc, n, m, k;
// ll ans = 0, c = 0;
// ll i, j;
// ll a, b;
// ll x, y;

// only one time buy-sell
int one_buy_sell(vector<int> &arr) {
  int ans = 0;
  int n = arr.size();
  int curr = 0;
  for (int i = 1; i < n; i++) {
    curr = max(curr + arr[i] - arr[i - 1], 0);
    ans = max(ans, curr);
  }
  return ans;
}

// many times buy sell
void many_buy_sell_1(vll &arr) {
  ll n = sz(arr);
  vector<pll> out;
  ll i = 0;
  while (i < n) {
    while (i < n - 1 && arr[i + 1] <= arr[i])
      i++;
    if (i == n - 1)
      break;
    ll buy = i++;
    while (i < n && arr[i] >= arr[i - 1])
      i++;
    ll sell = i - 1;
    out.pb({buy, sell});
  }
  for (auto x : out)
    cout << "(" << x.f << " " << x.s << ") ";
  newl;
}

// many time buy and sell.
int many_buy_sell_2(vector<int> &arr) {
  int n = arr.size();
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] - arr[i - 1] > 0)
      ans += arr[i] - arr[i - 1];
  }
  return ans;
}

// k times buy and sell
// f[k, i] represents the max profit up until prices[j]; (Note: NOT ending with
// prices[ii]) using at most k transactions. f[k, i] = max(f[k, i-1], prices[i]
// - prices[j] + f[k-1, j]); where { j in range of [0, i-1] }
//          = max(f[k, i-1], prices[i] + max(f[k-1, j] - prices[j])) //
//          implicitly calcuated
// f[0, i] = 0; 0 times transation makes 0 profit
// f[k, 0] = 0; if there is only one price data point you can't make any money
// no matter how many times you can trade
int k_buy_sell_1(int k, vector<int> &arr) {
  int n = arr.size();
  if (n <= 1) {
    return 0;
  }
  int ans = 0;
  vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

  // hidden trick to reduce loop from kn^2 to kn
  for (int i = 1; i <= k; i++) {
    int maxSoFar = dp[i - 1][0] - arr[0];
    for (int j = 1; j < n; j++) {
      dp[i][j] = max(dp[i][j - 1], arr[j] + maxSoFar);
      maxSoFar = max(maxSoFar, dp[i - 1][j] - arr[j]);
      ans = max(ans, dp[i][j]);
    }
  }
  return ans;
}

// k times, less memory
int k_buy_sell_2(int k, vector<int> &arr) {
  int n = arr.size();
  int ans = 0;
  if (n <= 1)
    return 0;

  // n/2 is max transaction possible. If k more than that, many_buy_sell
  if(k >= n/2) {
    for(int i = 1; i < n; i++) {
      ans = max(ans+arr[i]-arr[i-1], ans);
    }
    return ans;
  }

  vector<vector<int>> dp(2, vector<int>(n + 1, 0));

  // hidden trick to reduce loop from kn^2 to kn
  for (int h = 1; h <= k; h++) {
    int i = 1;
    int maxSoFar = dp[i - 1][0] - arr[0];
    for (int j = 1; j < n; j++) {
      dp[i][j] = max(dp[i][j - 1], arr[j] + maxSoFar);
      maxSoFar = max(maxSoFar, dp[i - 1][j] - arr[j]);
      ans = max(ans, dp[i][j]);
    }
    swap(dp[0], dp[1]);
  }
  return ans;
}

// stock with cooldown, original unoptimized
int stock_cooldown_0(vector<int>& arr) {
  int n = arr.size();
  if(n <= 1) return 0;
  vector<int> dp(n+1, 0);
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j < i; j++) {
      if(j-2 >= 0)
        dp[i] = max({dp[i], dp[i-1], arr[i]-arr[j]+dp[j-2]});
      else dp[i] = max({dp[i], dp[i-1], arr[i]-arr[j]});
    }
  }
  for(auto x:dp) cout<<x<<" ";
  cout<<endl;
  return *max_element(dp.begin(), dp.end());
}

// stock with cooldown
int stock_cooldown_1(vector<int>& arr) {
  int n = arr.size();
  if(n <= 1) return 0;
  vector<int> dp(n+1, 0);
  int localmax = -arr[0];
  for(int i = 1; i < n; i++) {
    dp[i] = max(dp[i-1], localmax+arr[i]);
    if(i-2 >= 0)
      localmax = max(localmax, dp[i-2]-arr[i]);
    else localmax = max(localmax, -arr[i]);
  }
  for(auto x:dp) cout<<x<<" ";
  cout<<endl;
  return *max_element(dp.begin(), dp.end());
}

// stock with cooldown, better space. only dp[i-1] and dp[i-2] needed to calculate dp[i]
int stock_cooldown_2(vector<int>& arr) {
  int n = arr.size();
  int ans = 0;
  if(n <= 1) return 0;
  int localmax = -arr[0];
  int preprev = 0, prev = 0, curr = 0;
  for(int i = 1; i < n; i++) {
    curr = max(prev, localmax+arr[i]);
    if(i-2 >= 0)
      localmax = max(localmax, preprev-arr[i]);
    else localmax = max(localmax, -arr[i]);
    ans = max(ans, curr);
    preprev = prev;
    prev = curr;
  }
  return ans;
}

// stock transaction fee required.asdf
class Solution {
public:
  int maxProfit(vector<int>& arr, int fee) {
    int n = arr.size();
    int ans = 0;
    if(n <= 1) return 0;
    int localmax = -arr[0];
    int prev = 0, curr = 0;
    for(int i = 1; i < n; i++) {
      curr = max(prev, localmax+arr[i] -fee);
      if(i-2 >= 0)
        localmax = max(localmax, prev-arr[i]);
      else localmax = max(localmax, -arr[i]);
      ans = max(ans, curr);
      prev = curr;
    }
    return ans;
  }
};

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  cin >> tc;
  while (tc--) {
    cin >> n;
    vll arr(n, 0);
    rep(i, 0, n) cin >> arr[i];
    buysellstock(arr);
  }

  return 0;
}

/*
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67
*/