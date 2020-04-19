//
// Created by kumaran on 4/15/20.
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

// ans vector may contain more than 1 of each duplicate
vll findduplicates_1(vll& arr) {
    vll ans;
    n = sz(arr);
    rep(i, 0, n) {
        int ti = abs(arr[i]);
        if(arr[ti] >= 0) arr[ti] = - arr[ti];
        else ans.pb(ti);
    }
    if(sz(ans) == 0) ans.pb(-1);
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
        sort(all(arr));

        ll ans = INT_MAX;

        ll i = 0, j = n-1;
        while(i < j) {
            if(abs(ans) > abs(arr[i] + arr[j]))
                ans = arr[i] + arr[j];
            if(arr[i] + arr[j] == 0) {
                ans = 0;
                break;
            } else if (arr[i] + arr[j] < 0) {
                i++;
            } else {
                j++;
            }
        }

        cout<<ans;
        newl;

    }


    return 0;
}

/*
3
3
-8 -66 -60
6
-21 -67 -37 -18 4 -65
2
-24 -73
*/
