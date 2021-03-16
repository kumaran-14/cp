// kumaran_14
#include <bits/stdc++.h>
using namespace std;

//minimum prime factor.
vll mpf(MAXN, 0);
vll pr;

// time complexity = nloglogn
//primenumbers less than n = n/logn
void eratosthenes(ll n) {
  rep(i, 2, n+1) {
    if(mpf[i] == 0) {
      mpf[i] = i;
      pr.pb(i);
    }
    for(ll j = 0; j < sz(pr) && pr[j] <= mpf[i] && i*pr[j] <= n; ++j) {
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
