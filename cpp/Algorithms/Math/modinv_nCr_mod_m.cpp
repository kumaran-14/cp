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


// [1, MOD-1], when MOD is prime.
vll inv(MOD, 1);

ll N = MAXN;
ll M = MOD;
vll fact(N+1, 1);


// O(M)
void precompute_inv() {
	inv[1] = 1;
	foi(i, 2, M) {
		inv[i] = (M - (M/i)*(inv[M%i]) % M)%M;
	}
}

// O(N)
void precompute_fact_mod_p() {
	fact[0] = 1;
	foii(i, 1, N) {
		fact[i] = fact[i-1]*i % M;
	}

}

// O(1)
ll nCr_mod_m(ll n, ll r) {
	if(r == 0) return 1;
	return (fact[n] * inv[fact[r]] % M * inv[fact[n-r]] % M) % M;
	// nCr mod M = (n! / ((n-r)!*(r!)) mod M;
	// which is the same as n! * (n-r!)^-1 *(r!)^-1 mod M;
}


int main()
{
	fast_io();
	freopen("./input.txt", "r", stdin);
	freopen("./output.txt", "w", stdout);
	return 0;

        /*
          Fermat little theorem
          when p is prime,
          x^(p-1) = 1 mod p
         */

        // hence, x^(p-2) = x^(-1) mod p
        // Therefore, [ inv(x) mod p ] is [ x^(p-2) mod p ]

}

// remember to read galen_colin codechef tutorial on mod inv
