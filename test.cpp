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

//height of max binary tree is 21.
// max nodes in a level is 2^20; 
ll PN = pow(2, 20);
vll fact(PN+1, -1);
vll levelcount(PN+1, 1);
vll prefixlc(PN+1, 1);
ll evnc, oddc;

void precomputefact() {
  fact[0] = 1;
  foii(i, 1, PN) {
    fact[i] = fact[i-1] * i % MOD;
  }
}

ll power(ll x, ll y, ll P) {
  ll res = 1;
  x = x % P;
  while(y > 0) {
    if(y&1) {
      res = (res*x) % P;
    }
    y = y>>1;
    x = (x*x)%P;
  }
  return res;
}

ll mod_inv(ll n, ll P) {
  return power(n, P-2, P);
}

ll nCr(ll n, ll r, ll P = MOD) {
  if(r == 0) return 1;
  return fact[n]* mod_inv(fact[r], P) % P * mod_inv(fact[n-r], P) % P % P;
}


void precomputelevelcount() {
  foii(i, 2, PN) {
    levelcount[i] = ((levelcount[i-1]*2)%MOD);
  }
  foii(i, 1, PN){
    prefixlc[i] = (levelcount[i]+prefixlc[i-1])%MOD;
  }
}

ll getproduct(ll y, ll x) {
  return (nCr(y, x)%MOD )* fact[x] % MOD;
}

ll oddtreecount(ll height, ll evnc, ll oddc) {
  ll ways = 1;
  ll x = prefixlc[height-1];
  ways = getproduct(oddc, x);
  ways = ways*getproduct(evnc, x-1)%MOD;

  ways = ways*getproduct(levelcount[height], oddc-x) % MOD;
  ways = ways*getproduct(levelcount[height], evnc - (x-1)) % MOD;
  return ways;
}


ll evntreecount(ll height, ll evnc, ll oddc, bool isevn) {
  ll ways = 1;
  ll x = prefixlc[height-1];
  ways = getproduct(evnc, x);
  ways = ways*getproduct(oddc, x-1)%MOD;

  ways = ways*getproduct(levelcount[height], evnc-x) % MOD;
  ways = ways*getproduct(max(levelcount[height], oddc - (x-1)), min(levelcount[height], oddc - (x-1))) % MOD;

   if(isevn) {
    ways = ways << 1;
    ways = ways%MOD;
    return ways;
   } else {
    if(oddc > prefixlc[height]-1) {
      //not a complete binary tree;
      ways = 0;
    }
    ways = (ways + oddtreecount(height, evnc, oddc) % MOD);
    ways = ways % MOD;
    return ways;
   }
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  precomputefact();
  precomputelevelcount();
  cin>>tc;
  while(tc--) {
    cin>>k;
    ll evnc, oddc;
    ll height = floor(log2(k));
    if(k & 1) {
      oddc = (k>>1) + 1;
      evnc = (k>>1);
    } else {
      evnc = (k>>1);
      oddc = (k>>1);
    }
    ll ways = 1;
    if(k != 1)
      ways = evntreecount(height, evnc, oddc, (k&1?false:true));
    cout<<ways<<endl;
  }
  return 0;
}
