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

// longest common subsequence, for a string and reversed string gives LPS
void lcs(string& stn, string& stm) {
    n = sz(stn);
    m = sz(stm);
    vvll dp(n+1, vll(m+1, 0));
    ll ans = 0;
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            if(stn[i-1] == stm[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
                // remove 'else' part, if Longest Common Substring needed.
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout<<ans<<endl;
}

void lps(string& str) {
    n = sz(str);
    vvll dp(n, vll(n, 0))
    // state = lps{start, end}
    // string of len 1 = lps = 1
    rep(i, 0, n) dp[i][i] = 1;
    rep(len, 2, n+1) {
        for(int i = 0; i + len < n+1; i++) {
            int j = i + len -1;
            if(str[i] == str[j] && len == 2) dp[i][j] = 2;
            else if(str[i] == str[j]) dp[i][j] = 2 + dp[i+1][j-1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
    cout<<"ji";
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
        string str;
        cin>>str;
        string s2 = str;
        reverse(all(s2));
//        lcs(str, s2);
        lps(str);
    }

    return 0;
}