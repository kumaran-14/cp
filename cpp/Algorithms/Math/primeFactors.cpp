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
// ll i, j;
// ll a, b;
// ll x, y;
#define PRIME_N 10000000
ll _sieve_size;
bitset<(PRIME_N + 10)> bs; //10^7 + extrabits
vll primes;

//O(N log log N )
void sieve(ll upperbound) {
  ll i, j;
  _sieve_size = upperbound + 1;
  
  bs.reset();
  bs.flip(); // set all to 1;
  // 0 and 1 are not primes;
  bs.set(0, false);
  bs.set(1, false);
  
  foii(i, 2, _sieve_size) {
    if(bs.test((size_t)i)) {
      //if prime, cross out its multiples.
      /*
        This algorithm does approximately (N × (1/2 + 1/3 + 1/5 + 1/7 + ... + 1/last prime in range ≤ N )) operations. 
        Using ‘sum of reciprocals of primes up to n’, we end up with the time complexity of roughly O(N log log N )
        O(N log log N )
      */
      for(j = i*i; j <=_sieve_size; j+=i)
        bs.set((size_t)j, false);
      primes.pb(i);
    }
  }
}

// works for "last prime"^2 in primes[];
// upto 9999991^2; nearly upto 10^14; 
bool isPrime(ll N) {
  ll i;
  // for N < 10^7 
  if(N <_sieve_size)
    return bs.test(N);
  
  /*
  The number of primes ≤ M, M = sqrt(N) – denoted by π(M ) – is bounded by O(M/(ln(M ) − 1)),
  so the complexity of this prime testing function is about O( sqrt(N)/ln(sqrt(N) )).
  O( sqrt(N)/ln(sqrt(N) ))
  */
  // for N > 10^7 
  for(auto x:primes) 
    if(N%x == 0)
      return false;
  return true;
}

//divide and conquer
// N = PrimeFactor * (N/PrimeFactor);
/*
In the worst case – when N is prime, this prime factoring algorithm with trial division requires
testing all smaller primes up to N, mathematically denoted as O(π( sqrt(N) )) = O( sqrt(N) /ln sqrt(N) ).

 No of primes less or == to N = sqrt(N) /ln sqrt(N);
 So it takes O(no of primes less than or == N)

 */
// r
vll primeFactors(ll N) {
  vll factors;
  ll PF_idx = 0;
  ll PF = primes[PF_idx];
  while(N != 1 && (PF*PF <= N)) {
    while(N%PF == 0) {
      N /= PF;
      factors.pb(PF);
    }
    PF = primes[++PF_idx];
  }
  // prime number case
  if(N != 1) factors.pb(N);
  return factors;
}


vll uniquePrimeFactors(ll N) {
  // same as primeFactors();
  vll factors;
  ll PF_idx = 0;
  ll PF = primes[PF_idx];
  while(N != 1 && (PF*PF <= N)) {
    while(N%PF == 0) {
      N /= PF;
      factors.pb(PF);
    }
    PF = primes[++PF_idx];
  }
  // prime number case
  if(N != 1) factors.pb(N);
  // std::unique removes cosecutive duplicates, doesnt resize container.
  auto it = unique(all(factors));
  factors.resize(distance(factors.begin(), it));
  return factors;
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  sieve(PRIME_N); //10^7
  // cout<<"123123123123243 is "<<(isPrime(123123123123243) ? "" : "not ")<<"a prime";
  // for(auto x:primes) cout<<x<<" ";
  // cout<<"No of primes upto 10^7"<<sz(primes);
  vll pf = primeFactors(2);
  for(auto x:pf) cout<<x<<" ";
  cout<<endl;
  vll upf = uniquePrimeFactors(2);
  for(auto x:upf) cout<<x<<" ";
  cout<<endl;
  return 0;
}

/*
 code for prime factorization of a number X
 */

/*
 Generate divisors of a Number X, from prime factorization of X
 */
/*
cin >> n;
vector<pair<int, int>> primes;
for( int p = 2; p * p <= n; p++ ){
    if( n % p == 0 ){
        int cnt = 0;
        // p should never start from 1
        while( n % p == 0 ) cnt++, n /= p;
        primes.push_back( { p, cnt } );
    }
}

if( n > 1 ){
    primes.push_back( { n, 1 } );
}

vector<int> d;
d.push_back( 1 );

for( int i = 0; i < primes.size(); i++ ){
    int size = d.size();
    int p_pow = 1;
    for( int j = 0; j < primes[i].second; j++ ){
        p_pow *= primes[i].first;
        for( int k = 0; k < size; k++ ){
            d.push_back( d[k] * p_pow );
        }
    }
}
*/
