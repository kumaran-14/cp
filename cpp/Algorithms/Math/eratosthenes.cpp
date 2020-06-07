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
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vull vector<ull>
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


//minimum prime factor.
vll mpf(MAXN, 0);
vll pr;


//primenumbers less than n;
void eratosthenes(ll n) {
  foii(i, 2, n) {
    if(mpf[i] == 0) {
      mpf[i] = i;
      pr.pb(i);
    }
    for(j = 0; j < sz(pr) && pr[j] <= mpf[i] && i*pr[j] <= n; ++j) {
      mpf[i*pr[j]] = pr[j];
    }
  }
}

// not used in solution yet. Check edge cases alone - 1, 2 and n-1, n
void basic_eratosthenes(ll n) {
    // all are primes
    vector<bool> sieve(n+1, true);
    // for every num - cancel out all its multiples.
    for(int num = 2; num*num < n; num++) {
        if(!sieve[num]) continue; // not prime
        // first multiple to start is num*num, since all multiples lower than that will be marked by earlier numbers;
        for(int multiple = num*num; multiple < n; multiple += num) {
            sieve[multiple] = false;
        }
    }
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  m = 100;
  eratosthenes(m);
  for(auto x:pr) cout<<x<<" ";
  return 0;
}
