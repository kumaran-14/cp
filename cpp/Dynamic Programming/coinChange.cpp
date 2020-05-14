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
#define newl cout<<"\n"
#define MAXN 100005
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18
// ¯\_(ツ)_/¯
#define l long int
#define d double
#define ll long long int
#define ull unsigned long long int
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
// ll i, j;
// ll a, b;
// ll x, y;

// order matters
void coinChange_1() {
    cin>>target;
    vll coins = {1, 2, 3};
    int n = sz(coins);
    vll dp(target+1, 0);
    dp[0] = 1;
    rep(i, 0, target+1)
        rep(j, 0, n) {
            if(i-coins[j] >= 0)
                dp[i] += dp[i-coins[j]];
        }
    cout<<dp[target]<<endl;
}

// order does not matter
// exhaust usage of each coin, one by one at the top.
void coinChange_1() {
    cin>>target;
    vll coins = {1, 2, 3};
    int n = sz(coins);
    vll dp(target+1, 0);
    dp[0] = 1;
    rep(i, 0, n)
        rep(j, 0, target+1) {
            if(j-coins[i] >= 0)
                dp[j] += dp[j-coins[i]];
        }
    cout<<dp[target]<<endl;
}



int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cin>>tc;
    while(tc--) {
        int target;

    }

    return 0;
}

/*
 *    min coins required;
     int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0) return 0;
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int x = 1; x < amount+1; x++) {
                if(x-coins[i] >= 0) {
                    if(dp[x-coins[i]] == 0) continue;
                    if(dp[x] == 0) {
                        dp[x] = 1 + dp[x-coins[i]];
                    } else {
                        dp[x] = min(dp[x], 1 + dp[x-coins[i]]);
                    }
                }
            }
        }
        for(auto x:dp) cout<<x<<" ";
        if(dp[amount] == 0) return -1;
        return dp[amount]-1;
    }


 */