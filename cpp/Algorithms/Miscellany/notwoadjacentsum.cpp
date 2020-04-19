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


ll no_two_adjacentsumsubsequence(vll& arr) {
    ll n = sz(arr);
    vll dp(n, 0);
    ll ans = INT_MIN;
    if(n == 1) return arr[0];
    dp[0] = arr[0];
    dp[1] = max(arr[1], dp[0]);
    ans = max(ans, max(dp[0], dp[1]));
    rep(i, 2, n) {
        dp[i] = max(dp[i-2] + arr[i], dp[i-1]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

// O(1) space.
ll no_two_adjacentsumsubsequence_2(vll& arr) {
    ll incl, excl, excl_next;
    incl = arr[0];
    excl = 0;
    ll n = sz(arr);
    ll ans = INT_MIN;
    rep(i, 1, n) {
        excl_next = max(incl, excl);
        incl = excl + arr[i];
        excl = excl_next;
    }
    ans = max(excl, incl);
    return ans;
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
        cin>>n;
        vll arr(n, 0);
        rep(i, 0, n) cin>>arr[i];
        cout<<no_two_adjacentsumsubsequence_2(arr);
        newl;

    }

    return 0;
}

/*
2
4
0 1 0 1
5
0 0 1 0 0
*/