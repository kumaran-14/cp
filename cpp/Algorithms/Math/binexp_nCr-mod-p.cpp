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

// ll tc, n, m, k;
// ll ans = 0, c = 0;
ll i, j;
// ll a, b;
// ll x, y;
ll PN = pow(2, 20);
vll fact(PN+1, -1);



void precomputefac() {
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

ll nCrModPFermat(ll n, ll r, ll P) {
	if(r == 0) return 1;
	return (fact[n]* mod_inv(fact[r], P) % P * mod_inv(fact[n-r], P) % P) % P;
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  precomputefac();
  cout<<"50C32"<<nCrModPFermat(50, 32, MOD);
  return 0;
}
