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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define vll vector<long long>
#define vvll vector<vll>
//vector<vector<int>> v(10, vector<int>(20,500)); 2d vector initialization. of 10 rows and 20 columns, with value 500.
#define pll pair<long long, long long>

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

ll tc, n, m, k;

int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // atcoder dp candies problem.
    cin>>n>>k;
    vll arr(n, 0);
    rep(i, 0, n) cin>>arr[i];
    vvll dp(n+1, vll(k+1, 0));

    rep(i, 0, n+1) dp[i][0] = 1;

    rep(i, 1, n+1) {
        rep(j, 1, k+1) {
            // two things happening here, querying prefix sum, making prefix array.
            if(j-arr[i-1]-1 >= 0)
                // dp[i][j-1] is making prefix arr
                //dp[i-1][j-arr[i-1]-1] is querying prefix : candies can go from 1 - arr[i-1];
                dp[i][j]  = dp[i][j-1]  + dp[i-1][j] - dp[i-1][j-arr[i-1]-1] + MOD;
            else
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }

    cout<<(dp[n][k]);

    return 0;
}

/*
2
4
0 1 0 1
5
0 0 1 0 0
*/