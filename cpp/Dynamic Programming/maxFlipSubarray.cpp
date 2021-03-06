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
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    ll ans = 0;
    string str;
    cin>>str;
    n = sz(str);
    vll arr(n);
    foi(i, 0, n) {
      if(str[i] == 'R') {
        arr[i] = -1;
        ans++;
      } 
      else arr[i] = 1;
    }
    ll maxsum = INT_MIN;
    ll maxend = 0;
    k = 0;
    ll from = 0;
    ll to = 0;
    foi(i, 0, n) {
      maxend += arr[i];
      if(maxsum <= maxend) {
        maxsum = maxend;
        from = k;
        to = i;
      }
      if(maxend < 0) {
        maxend = 0;
        k = i+1;
      }
    }
    cout<<ans+maxsum<<endl;

  }
  return 0; 
}


/*

3
RKKRK
RKKR
KRKRKRKRKRRKRRKRRK

// get max R's by flipping a subarray.
K is 1;
R is -1;
get max contiguous subarray sum, add it with number of Rs in the original array.

*/

