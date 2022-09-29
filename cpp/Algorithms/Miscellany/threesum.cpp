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

// Extend methods for foursum.
// https://cses.fi/problemset/task/1642/
// sorting
bool f4sum_1(vll& arr, ll sum) {
    sort(all(arr));
    rep(i, 0, sz(arr)-2) {
        ll left = i+1;
        ll right = sz(arr)-1;
        while(left < right) {
            ll currsum = arr[i] + arr[left] + arr[right];
            if( currsum == sum) return true;
            else if(currsum < sum) left++;
            else right--;
        }
    }
    return false;
}

// hashing
bool f3sum_2(vll& arr, ll sum) {
    rep(i, 0, sz(arr)-2) {
        unordered_set<int> hs;
        ll targetsum = sum - arr[i];
        rep(j, i+1, sz(arr)) {
            if(hs.find(targetsum-arr[j]) != hs.end()) return true;
            hs.insert(arr[j]);
        }
    }
    return false;
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
        ll sum;
        cin>>n>>sum;
        vll arr(n, 0);
        rep(i, 0, n) cin>>arr[i];
        cout<<f3sum_2(arr, sum);
        newl;
    }


    return 0;
}

/*
2
6 13
1 4 45 6 10 8
5 10
1 2 4 3 6
*/
