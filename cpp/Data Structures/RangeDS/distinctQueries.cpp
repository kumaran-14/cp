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
#define all(v) v.begin(), v.end()

#define ll long long int
#define vi vector<int>
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long, long long>

#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

const int mxN = 2e5 + 5;
const int mxM = 2e5 + 7;
const int lg = 22;

struct Fenwick {
  int n;
  vector<ll> tree;
  // 0 is not part of any range.
  // tree range is from [1....n-1];
  Fenwick(ll _n) : n(_n), tree(_n) {}

  void Update(ll i, ll delta) {
    i++;
    while (i < tree.size()) {
      tree[i] += delta;
      i += i & (-i);
    }
  }
  //[1....i], both inclusive.
  ll Query(ll i) {
    i++;
    ll sum = 0;
    while (i > 0) {
      sum += tree[i];
      i -= i & (-i);
    }
    return sum;
  }
};

ll tc, n, m, q;

Fenwick ft(mxN);

ll arr[mxN], last[mxN];
ll ans[mxN];

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  memset(last, -1, sizeof last);
  cin >> n >> tc;

  vll v;

  rep(i, 0, n) {
    ll x;
    cin >> x;
    arr[i] = x;
    v.pb(x);
  }

  sort(all(v));
  v.erase(unique(all(v)), v.end());

  auto ind = [&](ll x) { return lower_bound(all(v), x) - v.begin(); };

  struct query {
    ll l, r, idx;
  };
  vector<query> qs;

  rep(i, 0, tc) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    query q;
    q.l = a, q.r = b, q.idx = i;
    qs.pb(q);
  }

  auto comp = [&](query a, query b) { return a.r < b.r; };

  sort(all(qs), comp);

  ll k = 0;
  rep(i, 0, n) {
    auto x = ind(arr[i]);

    if(last[x] == -1) {
      last[x] = i;
      ft.Update(i, 1);
    } else {
      ft.Update(last[x], -1);
      ft.Update(i, 1);
      last[x] = i;
    }

    while(k < qs.size() && qs[k].r == i) {
      auto q = qs[k];
      ans[q.idx] = ft.Query(q.r)-ft.Query(q.l-1);
      k++;
    }
  }
  rep(i, 0, tc) cout<<ans[i]<<"\n";

  return 0;
}


