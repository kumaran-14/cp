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

ll kadane(vll& arr) {
    ll n = sz(arr);
    ll mend = arr[0];
    ll ans = mend;
    rep(i, 1, n) {
        mend = max(arr[i], mend + arr[i]);
        ans = max(ans, mend);
    }
    return ans;
}

// O(n4) - explicit col interval sum calculation.
ll maxRectSum(vvll& mat, ll rows, ll cols) {
    ll ans = INT_MIN;
    rep(cs, 0, cols)
        rep(ce, cs, cols) {
            vll colsumarr;
            rep(i, 0, rows) {
                int sum = 0;
                rep(j, cs, ce+1)
                    sum += mat[i][j];
                colsumarr.pb(sum);
            }
            ans = max(ans, kadane(colsumarr));
        }
    return ans;
}

// O(n3)
ll maxRectSum_2(vvll& mat, ll rows, ll cols) {
    ll ans = INT_MIN;
    vll colsumarr(rows, 0);
    rep(cs, 0, cols) {
        fill(all(colsumarr), 0);
        rep(ce, cs, cols) {
            rep(i, 0, rows) {
                colsumarr[i] += mat[i][ce];
            }
            ans = max(ans, kadane(colsumarr));
        }
    }
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
        ll rows, cols;
        cin>>rows>>cols;
        vvll mat(rows, vll(cols, 0));
        rep(i, 0, rows)
            rep(j, 0, cols)
                cin>>mat[i][j];
        cout<<maxRectSum_2(mat, rows, cols);
        newl;
    }
    return 0;
}

/*
1
4 5
1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6

*/