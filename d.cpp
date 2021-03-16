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

const int mxN = 2e5 + 5;
const int mxM = 2e5 + 7;
const int lg = 22;

ll n, m, tc, q;

ll arr[4*mxN+5];
ll pref[4*mxN+5];

struct node {
  vector<ll> v = {};
  vector<ll> vp = {};
};

node seg[4*mxN+5];

void build(ll i, ll l, ll r) {
  if(l == r) {
    seg[i].v.pb(arr[l]);
    seg[i].vp.pb(arr[l]);
    return;
  }
  ll m = (l+r)/2;
  build(i<<1, l, m);
  build(i<<1^1, m+1, r);
  node temp = seg[i<<1];
  for(auto x:seg[i<<1^1].v) {
    ll prev = temp.v.back();
    auto y = x;
    if(prev - x > 0) y += abs(prev-x);
    temp.v.pb(y);
    temp.vp.pb(y+temp.vp.back());
  }
  seg[i] = temp;
}


pair<ll, ll> query(ll ql, ll qr, ll i, ll l, ll r) {
  if(qr < l|| r < ql) {
    return {0, 0};
  }
  if(ql <= l && r <= qr) {
    return {seg[i].v.back(), seg[i].vp.back()};
  }
  ll m = (l+r)/2;
  auto left = query(ql, qr, i<<1, l, m);
  auto right = query(ql, qr, i<<1^1, m+1, r);

  // combine;
  ll mergesum = 0;
  int z = min(r, qr) - (m+1) + 1;
  if(z <= 0) return {max(left.f, right.f), left.s+right.s};

  auto it = lower_bound(seg[i<<1^1].v.begin(), seg[i<<1^1].v.begin()+(z-1), left.f);
  int ind = it-seg[i<<1^1].v.begin();
  if(ind >= 0 && ind < z) {
    while(ind >= 0 && seg[i<<1^1].v[ind] >= left.f) ind--;
  }
  // ind last el < left.f;
  if(ind >= 0) {
    mergesum = (ind+1)*left.f - (ind >= 0 ? seg[i<<1^1].vp[ind] : 0);
  }

  return {max(left.f, right.f), left.s +right.s + mergesum};
}

ll qry(ll ql, ll qr) {
  auto [mx, sum] = query(ql, qr, 1, 1, n);
  return sum - (pref[qr]-pref[ql-1]);
}

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif



  cin>>n>>q;
  rep(i, 1, n+1) {
    cin>>arr[i];
    pref[i] = pref[i-1]+arr[i];
  }

  build(1, 1, n);

  while(q--) {
    ll a, b; cin>>a>>b;
    ll ans = qry(a, b);
    cout<<ans;
    newl;
  }

  return 0;
}