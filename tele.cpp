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

ll arr[mxN];

struct node {
  ll sum, inc, setx;
  bool assign;
};

class Seg {
  int n = 0;
  vector<node> seg;

  void apply(ll i, ll w, ll inc, ll setx, bool assign) {
    if(assign) {
      // assign and increment;
      seg[i] = node{w*(inc+setx), inc, setx, assign};
    } else {
      seg[i].sum += w*inc;
      seg[i].inc += inc;
    }
  }

  void push(ll i, ll l, ll r){
    ll m = (l+r)/2;
    apply(i<<1, m-l+1, seg[i].inc, seg[i].setx, seg[i].assign);
    apply(i<<1^1, r-m, seg[i].inc, seg[i].setx, seg[i].assign);
    seg[i].inc = seg[i].setx = seg[i].assign = 0;
  }

  void modify(ll ql, ll qr, ll inc, ll setx, ll assign, ll i, ll l, ll r) {
    if(r < ql || qr < l ) return;
    if(ql <= l && r <= qr) {
      apply(i, r-l+1, inc, setx, assign);
    }
    push(i, l, r);
    ll m = (l+r)/2;
    modify(ql, qr, inc, setx, assign, i<<1, l, m);
    modify(ql, qr, inc, setx, assign, i<<1^1, m+1, r);
    seg[i].sum = seg[i<<1].sum + seg[i<<1^1].sum;
  }

  ll query(ll ql, ll qr, ll i, ll l, ll r) {
    if(r < ql || qr < l ) return 0;
    if(ql <= l && r <= qr) {
      return seg[i].sum;
    }
    push(i, l, r);
    ll m = (l+r)/2;
    return query(ql, qr, i<<1, l, m) + query(ql, qr, i<<1^1, m+1, r);
  }

public:
  void init(int _n) {
    n = _n;
    seg.assign(4*n+5, node());
  }

  // both 1 based indexing. build(1, 1, n)
  void build(ll i, ll l, ll r) {
    if(l == r) {
      seg[i] = node{arr[l], 0, 0, false};
      return;
    }
    int m = (l+r)/2;
    build(i<<1, l, m);
    build(i<<1^1, m+1, r);
  }

  void increment(ll ql, ll qr, ll dx) {
    modify(ql, qr, dx, 0, false, 1, 1, n);
  }

  void assign(ll ql, ll qr, ll x) {
    modify(ql, qr, 0, x, true, 1, 1, n);
  }

  ll qry(ll ql, ll qr) {
    return query(ql, qr, 1, 1, n);
  }

};

Seg st;


int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif



  return 0;
}