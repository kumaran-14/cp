// maximize xor of subset of array

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


ll tc, n, m, k;

// most significant set bit from left
int msb(unsigned n) {
  return (int)log2(n);
}

ull check_bit(ull N,int POS){return (N & (1ULL<<POS));}


int main() {
  fast_io();
  #ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  #endif
  //begin code.

  cin>>tc;
  while(tc--) {
    cin>>n;
    vector<ull> arr(n);
    rep(i, 0, n) cin>>arr[i];

    sort(all(arr), greater<ll>());

    ll bitpos = msb(arr[0]);
    int ind = 0;
    rep(i, bitpos+1, 0) {
      // find first index of number whose bitpos is set.
      int x = ind;
      while(x<n && msb(arr[x])!=i)
        x++;
      if(x==n) continue;

      swap(arr[x], arr[ind]);
      // xor all other numbers whose bitpos is set;
      rep(j, 0, n) {
        if(j != ind && msb(arr[j])==i) arr[j] ^= arr[ind];
      }
      ind++;
    }
    // //xor all elements of array to find the ans
    ull ans = 0;
    rep(i, 0, n) ans = max(ans, ans^arr[i]);
    cout<<ans<<endl;
  }


  //end code.
  return 0;
}


/**
 * input format
 *
3
3
2 4 5 
3
33 73 64
9
5 633 64 43 131 51 87 999 23 

 */
