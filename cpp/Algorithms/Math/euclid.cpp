// kumaran_14

// #include <boost/multiprecision/cpp_int.hpp> 
// using boost::multiprecision::cpp_int;  
#include <bits/stdc++.h>
using namespace std;
// ¯\_(ツ)_/¯ 
#define f first
// #define s second
#define p push
#define mp make_pair
#define pb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl "\n"
#define MAXN 100005
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18
// ¯\_(ツ)_/¯ 
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define vll vector<long long>
#define pll pair<long long, long long>
#define vvll vector<vll>
#define vvdd vector<vdd>
//vector<vector<int>> v(10, vector<int>(20,500)); 10 rows, 20 cols, val = 500;

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

  /*

   template<typename T>
    T gcd(T a, T b) {
        while((a %= b) && (b %= a));
        return a | b;
    }
  */

ll tc, n, m, k;

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a%b));};

inline ll gcd(ll a, ll b) {
    if(a&&b)
        while((a%=b)&&(b%=a));
    return a^b;
}

ll lcm(ll a, ll b) {return (a*(b/gcd(a, b)));}

ll xgcd(ll a, ll b, ll *x, ll* y) {
  
  ll x1, y1, g;

  if(b>a) return xgcd(b, a, y, x);

  //base case
  if(b == 0) {
    *x = 1;
    *y = 0;
    return a;
  }

  g = xgcd(b, a%b, &x1, &y1);

  *x = y1;
  *y = (x1-(a/b)*y1);
  return g;

}


int main() {
  fast_io();
  #ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  #endif
  //begin code.

  ll a = 100;
  ll b = 3;
  ll x, y;
  ll g = 19;
  g = xgcd(b, a, &x, &y);
  debug(g);
  debug(x);
  debug(y);
  //end code.
  return 0;
}
