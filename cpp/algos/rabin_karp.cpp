// kumaran_14
#include <bits/stdc++.h>
using namespace std;

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

// polynomial rolling hash function, for lowercase letters
// collision probability is 1/M;
vll rabin_karp(string const& pattern, string const& text) {
  ll P = 31;
  ll M = 1e9 + 9;
  ll T = sz(text);
  ll S = sz(pattern);
  vll p_pow(T, 1);
  //precompte powers of P
  p_pow[0] = 1;
  foi(i, 1, T) {
    p_pow[i] = (p_pow[i-1]*P)%M;
  }
  // precompute prefix hash. 1-indexed. h[i] = hash of text[0....i];
  vll h(T+1, 0);
  foi(i, 0, T) {
    h[i+1] = (h[i] + (text[i]-'a' + 1)*p_pow[i])%M;
  }
  // compute pattern hash;
  ll h_s = 0;
  foi(i, 0, S) {
    h_s += ((pattern[i]-'a'+1)*p_pow[i])%M;
  }
  //find occurences;
  vll occs;
  for(i = 0; i + S <= T; ++i) {
    ll curr_h = (h[i+S] + m -h[i])%M;
    if(curr_h == (h_s*p_pow[i] % M)) {
      occs.pb(i);
    }
  }
  return occs;
}


int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  string S = "asdf", T = "asdfqwtafgkzvasdfisdfhugjasfasdufdfafjdzfasdkjfhqepeqasdfasdwrqasjdkfaadfsadsfsdf";
  vll ans = rabin_karp(S, T);
  for(auto x:ans) cout<<x<<" ";
  return 0;
}
