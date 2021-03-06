// kumaran_14
//https://www.hackerrank.com/challenges/short-palindrome/problem
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define p push
#define mp make_pair
#define pb push_back
#define foi(i, a, n) for (i = (a); i < (n); ++i)
#define foii(i, a, n) for (i = (a); i <= (n); ++i)
#define fod(i, a, n) for (i = (a); i > (n); --i)
#define fodd(i, a, n) for (i = (a); i >= (n); --i)
#define gcd __gcd
#define mem(a, b) memset(a, b, sizeof a)
#define all(v) v.begin(), v.end()
#define println(a) cout << (a) << endl
#define sz(x) ((int)(x).size())
#define PI 3.141592653589793238L
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000
#define INFLL 1000000000000000000ll

// #define l long int
#define d double
#define ll long long int
#define ld long double
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vll vector<long long>
#define vvi vector<vector<int>>
// vector<vector<int>> v(10, vector<int>(10,1)); 2d vector initialization.
// Initialization value is 1.
#define si set<int>
#define mii map<int, int>
#define mll map<long long, long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pcc pair<char, char>
#define pdd pair<double, double>

#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

int main() {
  fast_io();
  ll i, j, ans;
  string str;
  vll freq(26, 0), palindrome(26, 0);
  vector<vector<ll>> pairfreq(26, vector<ll>(26, 0));
  cin >> str;
  foi(i, 0, sz(str)) {
    ll index = str[i] - 'a';
    ans = (ans + palindrome[index]) % MOD;
    foi(j, 0, 26) {
      palindrome[j] += (pairfreq[j][index]);
      palindrome[j] = (palindrome[j]%MOD);

      pairfreq[j][index] += freq[j];
      pairfreq[j][index] = (pairfreq[j][index] % MOD);
    }
    freq[index]++;
  }
  cout<<ans;
  return 0;
}
