#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*
 * O(r)
 */
ll ncr(ll n, ll r) {
  ll ans = 1;
  for (ll i = 1; i <= r; i++) {
    ans = ans * (n - i + 1) / i;
  }
  return ans;
}

/*
 * dp method
 */

const ll mxN = 1e4+7;
ll C[mxN][mxN];

int main() {

  for(ll i = 0; i < mxN; i++)
    C[i][0] = 1;
  for (ll i = 1; i < mxN; i++) {
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  //https://discuss.codechef.com/t/need-some-explanation-on-the-combinatorics-formula-ncr-n-1cr-n-1cr-1/13834
  // nCr = ways after nth item belongs to group of r items + ways after nth item does not belong to group of r items
  // nCr = n-1 C r-1                                   +   N-1 C r
  return 0;
}
