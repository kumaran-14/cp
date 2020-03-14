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


int main()
{
    fast_io();
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

//     Beginning of solution
// input format: pairs of numbers, each number of pair in newline
/*
 Example: 123
          256
 */
    string s1, s2;
    while(cin>>s1 && cin>>s2) {
        vll v1, v2, prod;
        // store it vector
        rep(i, 0, sz(s1)) {
            v1.pb(s1[i] - '0');
        }
        rep(i, 0, sz(s2)) {
            v2.pb(s2[i]- '0');
        }

        // push back 1st set
        rep(j, 0, sz(v1)) {
            prod.pb(v1[j] * v2[0]);
        }
        // calc all others
        rep(i, 1, sz(v2)) {
            rep(j, 0, sz(v1)) {
                if(j == sz(v1) -1) {
                    prod.pb(v1[j]*v2[i]);
                } else {
                    prod[i+j] += v1[j]*v2[i];
                }
            }
        }

//        rep(i, 0, sz(prod)) {
//            debug(prod[i])
//        }

        // calculate carry overs
        vll ans;
        ll val = 0;
        rep(i, sz(prod), 0) {
            val += prod[i];
            ans.pb(val%10);
            val  = (val/10);
        }

        // last carry over is not 0
        while(val != 0) {
            ans.pb(val%10);
            val = val/10;
        }
        reverse(all(ans));
        string str = "";
        rep(i, 0, sz(ans)) {
            str += (char)(48 + ans[i]);
        }
        str.erase(0, str.find_first_not_of('0'));
        cout<<(str == "" ? "0" : str);
        newl;
    }

    // End of solution
    return 0;
}
