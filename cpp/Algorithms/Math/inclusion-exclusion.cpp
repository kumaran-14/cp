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

ll lcmArray(vll arr) {
    auto n = sz(arr);
    ll ans = arr[0];
    rep(i, 1, n) {
        ans = ((ans * arr[i] )/( __gcd(ans , arr[i])));
    }
    return ans;
}


int main()
{
    fast_io();
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    // SPOJ EASYMATH

    cin>>tc;
    while(tc--) {
        ll a, b;
        cin>>n>>m>>a>>b;
        ll ans = 0;
        ll arr[] = {a, a+b, a+2*b, a+3*b, a+4*b};
        ll ans1 = n-1, ans2 = m;
        ll sign = 1;
        ll range = 2<<5;
        rep(bitmask, 1, range) {
            auto num = __builtin_popcount(bitmask);
            if(num%2) sign = -1;
            else sign = 1;
            vll lcmarr;
            ll j = 0;
            ll bit = bitmask;
            while(bit > 0) {
                if(bit&1 == 1) {
                    lcmarr.pb(arr[j]);
                }
                j++;
                bit = bit >> 1;
            }
            ans1 += sign * ((n-1)/lcmArray((lcmarr)));
            ans2 += sign * (m/lcmArray((lcmarr)));
        }
        ans = ans2 - ans1;
        cout<<ans<<endl;
    }
    return 0;

}