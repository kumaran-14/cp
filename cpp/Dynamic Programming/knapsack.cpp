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

void knapsack_unlimited() {
  ll w;
  cin>>n>>w;
  vll price(n), weight(n);
  foi(i, 0, n) cin>>price[i];
  foi(i, 0, n) cin>>weight[i];
  vll dp(w+1, 0);
  foii(i, 0, w) {
    foi(j, 0, n) {
      if(weight[j] <= i) {
        dp[i] = max(dp[i], price[j] + dp[i-weight[j]]);
      }
    }
  }
  cout<<dp[w]<<endl;
}

int r_knapsack(ll index, ll w, vll& weight, vll& price) {
    if(index == 0 || w == 0) return 0;
    if(weight[index] > w) return r_knapsack(index-1, w, weight, price);
    return max(price[index] + r_knapsack(index-1, w-weight[index], weight, price), (ll)r_knapsack(index-1, w, weight, price));
}


void knapsack_alterstate() {
    ll w;
    cin>>n>>w;
    vll weight(n, 0), price(n, 0);

    ll pricesum = 0;
    rep(i, 0, n) {
        cin>>weight[i];
        cin>>price[i];
        pricesum += price[i];
    }

    // dp state = {first i elements, max_price} = min weight needed to make max_price from 0 - i elements
    vvll dp(n+1, vll(pricesum+1, INFI));
    dp[0][0] = 0;
    rep(i, 1, n+1) {
        rep(j, 0, pricesum+1) {
            if(j - price[i-1] >= 0) {
                dp[i][j] = min(dp[i-1][j], weight[i-1] + dp[i-1][j-price[i-1]]);
            } else {
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
        }
    }



    // max price for which min weight is less or equal to capacity.
    ll ans = 0;
    rep(i, 0, pricesum+1) {
        if(dp[n][i] <= w) ans = i;
    }

    cout<<ans;
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {

  }
  return 0; 
}


/*

2
2 3
1 1
2 1 
4 8
1 4 5 7
1 3 4 5

*/

