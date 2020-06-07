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

int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // UVa cutting rod
    ll x;
    while(cin>>x && x) {
        cin>>n;
        vll arr(n+2, 0);
        arr[0] = 0;
        rep(i, 1, n+1) cin>>arr[i];
        arr[n+1] = x;
        // state = {i, j} from i to j in arr
        vvll dp(n+2, vll(n+2, -1));

        rep(len, 1, n+2) {
            for(int j = 0; j + len < n+2; j++) {
                int left = j;
                int right = j+len;
                if(left+1 == right) {
                    dp[left][right] = 0;
                    continue;
                }
                dp[left][right] = INT_MAX;
                for(int k = left+1; k < right; k++) {
                    dp[left][right] = min(dp[left][right], arr[right]-arr[left] + dp[left][k] + dp[k][right]);
                }
            }
        }
        cout<<"The minimum cutting is "<<dp[0][n+1]<<".";
        newl;
    }
    return 0;
}
