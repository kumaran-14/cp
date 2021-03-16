#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define db(x) cout << '>' << #x << ':' << x << endl;
#define sz(x) ((int)(x).size())
#define newl cout << "\n"

#define ll long long int
#define vi vector<int>
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long, long long>

#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

ll tc, m, k;

ll ans = 1e12+7;

void dfs(ll n, ll c) {
  if(n == 1) {
    ans = min(ans, c);
    return;
  }
  vector<pair<int, int>> primes;
  for (int p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      int cnt = 0;
      while (n % p == 0)
        cnt++, n /= p;
      primes.push_back({p, cnt});
    }
  }
  if (n > 1) {
    primes.push_back({n, 1});
  }
  if (primes.size() == 1) {
    if (primes[0].s == 1) {
      dfs(primes[0].f-1, c+1);
    } else {
      dfs(primes[0].f, c+1);
    }
  } else {
    for(auto x:primes) {
      dfs(x.f, c+1);
    }
  }
  return;
}

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  cin >> tc;
  ll n;
  while (tc--) {
    cin >> n;
    ans = 1e12+7;
    dfs(n, 0);
    cout << ans;
    newl;
  }

  return 0;

}


/*

13 30
1 6 5
2 7 3
3 8 4
4 11 4
5 12 3
6 1 5
6 7 8
6 9 5
7 2 2
7 6 7
7 8 4
7 10 7
8 3 4
8 7 6
9 6 6
9 10 3
9 12 7
10 6 4
10 7 5
10 9 3
10 11 5
11 4 4
11 8 5
11 10 5
11 13 10
12 5 2
12 9 7
12 13 6
13 11 10
13 12 5
 */