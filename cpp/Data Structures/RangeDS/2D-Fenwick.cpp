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

ll tc, n, m, k;
const int mxN = 1e3 + 5;
const int mxM = 2e5 + 7;
const int lg = 22;

ll ft[mxN][mxN];

void upd(ll x, ll y, ll val) {
  x++, y++;
  for (int i = x; i < mxN; i += i & (-i)) {
    for (int j = y; j < mxN; j += j & (-j)) {
      ft[i][j] += val;
    }
  }
}

ll qry(ll x, ll y) {
  x++, y++;
  ll sum = 0;
  for (int i = x; i; i -= i & (-i)) {
    for (int j = y; j; j -= j & (-j)) {
      sum += ft[i][j];
    }
  }
  return sum;
}

// 2d rectangle sum
ll sum(ll x1, ll y1, ll x2, ll y2) {
  assert(x1 <= x2);
  assert(y1 <= y2);
  return qry(x2, y2) - qry(x2, y1 - 1) - qry(x1 - 1, y2) + qry(x1 - 1, y1 - 1);
}

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  // cses forest queries II

  ll q;
  cin >> n >> q;
  rep(i, 0, n) {
    string str;
    cin >> str;
    rep(j, 0, n) {
      if (str[j] == '*')
        upd(i, j, 1);
    }
  }

  while (q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll x, y; cin>>x>>y; x--, y--;
      if(sum(x, y, x, y)) upd(x, y, -1);
      else upd(x, y, 1);
    } else {

      ll x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1--, y1--, x2--, y2--;
      assert(x1 <= x2);
      assert(y1 <= y2);
      cout << sum(x1, y1, x2, y2);
      newl;
    }
  }

  return 0;
}