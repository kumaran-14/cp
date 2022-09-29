
const ll mxN = 1e5 + 7;
// values should start from index 1
ll arr[mxN];

struct node {
  ll el;
};
node seg[4*mxN]; // seg[1] -> for biggest range [1, n] in arr

node combine(node a, node b){
  return node{max(a.el, b.el)}; // max tree;
}
// closely connected to combine function
ll COMBINE_OUT_OF_BOUNDS = -(1e9+7);

// build(1, 1, n) -> seg[1] represents range arr[1] to arr[n]
void build(ll i, ll l, ll r) {
  if(l == r) {
    seg[i] = node{arr[l]};
    return;
  }
  ll m2 = (l+r)/2;
  build(i<<1, l, m2);
  build(i<<1|1, m2+1, r);
  seg[i] = combine(seg[i<<1], seg[i<<1|1]);
}

void update(ll qi, ll x, ll i, ll l, ll r) {
  if (l < r) {
    ll m2 = (l+r)/2;
    if(qi <= m2) update(qi, x, i<<1, l, m2);
    else update(qi, x, i<<1|1, m2+1, r);
    seg[i] = combine(seg[i<<1], seg[i<<1|1]);
  } else {
    seg[i] = node{x};
    arr[l] = x;
  };
}

node query(ll ql, ll qr, ll i, ll l, ll r) {
  if( qr < l || r < ql) return node{COMBINE_OUT_OF_BOUNDS};
  if(ql <= l && r <= qr) return seg[i];
  ll m2 = (l+r)/2;
  return combine(
      query(ql, qr, i<<1, l, m2),
      query(ql, qr, i<<1|1, m2+1, r)
  );
}


ll findfirst(ll ql, ll qr, ll x, ll i, ll l, ll r) {
  if(seg[i].el < x) return -1;
  if( qr < l || r < ql) return -1;
  if(l == r) return l;
  ll m2= (l+r)/2;
  ll temp = findfirst(ql, qr, x, i<<1, l, m2);
  if(temp == -1)
    temp = findfirst(ql, qr, x, i<<1|1, m2+1, r);
  return temp;
}

// public functions:
// querying range [L, R], max possible range [1, n]
node qry(ll ql, ll qr) {
  return query(ql, qr,  1, 1, n);
}

// point update [i], possible i lies in [1, n]
void upd(ll qi, ll x) {
  update(qi, x, 1, 1, n);
}

// find first index, whose value >= x, in range [ql, qr] or return -1;
ll ffirst(ll ql, ll qr, ll x) {
  return findfirst(ql, qr, x, 1, 1, n);
}
