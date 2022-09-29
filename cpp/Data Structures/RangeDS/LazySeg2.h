const ll mxN = 1024000 + 7;

ll a[mxN];
ll s1[4 * mxN], s2[4 * mxN];

ll SET = 1, ZERO = 2, FLIP = 3, CLR = 0;

void build(ll i, ll l, ll r) {
  s2[i] = CLR;
  if (l == r) {
    s1[i] = a[l];
    return;
  }
  ll mid = (l + r) >> 1;
  build(i * 2, l, mid);
  build(i * 2 + 1, mid + 1, r);
  s1[i] = s1[i * 2] + s1[i * 2 + 1];
}


ll apply_flip(ll x) {
  if(x == SET) return ZERO;
  else if(x == ZERO) return SET;
  else if(x == FLIP) return CLR;
  return FLIP;
}
void prop(ll i, ll l, ll r) {
  // apply;
  if(s2[i] == CLR) return;
  else if(s2[i] == SET) {
    s1[i] = r-l+1;
  } else if(s2[i] == ZERO) {
    s1[i] = 0;
  } else {
    s1[i] = r-l+1-s1[i];
  }
  // propagate
  if(l != r) {
    ll lt = i*2, rt = i*2+1;
    if(s2[i] == SET || s2[i] == ZERO) {
      s2[lt] = s2[rt] = s2[i];
    } else {
      s2[lt] = apply_flip(s2[lt]);
      s2[rt] = apply_flip(s2[rt]);
    }
  }

  s2[i] = CLR;
}

ll query(ll ql, ll qr, ll i, ll l, ll r) {
  // prop -> apply and push;
  prop(i, l, r);
  if (qr < l || r < ql)
    return 0;
  if (ql <= l && r <= qr)
    return s1[i];
  ll lt = 2 * i, rt = 2 * i + 1, mid = (l + r) / 2;
  auto q1 = query(ql, qr, lt, l, mid);
  auto q2 = query(ql, qr, rt, mid + 1, r);
  return q1 + q2;
}
ll qry(ll L, ll R) { return query(L, R, 1, 1, n); }

void tree_set(ll ql, ll qr, ll i, ll l, ll r) {
  // prop -> apply and push;
  prop(i, l, r);
  if (qr < l || r < ql)
    return;
  if (l == r) {
    s1[i] = 1;
    return;
  }
  if (ql <= l && r <= qr) {
    s1[i] = r - l + 1;
    s2[i * 2] = s2[i * 2 + 1] = SET;
    return;

  }

  ll lt = 2 * i, rt = 2 * i + 1, mid = (l + r) / 2;
  tree_set(ql, qr, lt, l, mid);
  tree_set(ql, qr, rt, mid + 1, r);
  s1[i] = s1[lt] + s1[rt];
}
void tset(ll L, ll R) { tree_set(L, R, 1, 1, n); }

void tree_zero(ll ql, ll qr, ll i, ll l, ll r) {
  // prop -> apply and push;
  prop(i, l, r);
  if (qr < l || r < ql)
    return;
  if (l == r) {
    s1[i] = 0;
    return;
  }
  if (ql <= l && r <= qr) {
    s1[i] = 0;
    s2[i * 2] = s2[i * 2 + 1] = ZERO;
    return;

  }

  ll lt = 2 * i, rt = 2 * i + 1, mid = (l + r) / 2;
  tree_zero(ql, qr, lt, l, mid);
  tree_zero(ql, qr, rt, mid + 1, r);
  s1[i] = s1[lt] + s1[rt];
}
void tzero(ll L, ll R) { tree_zero(L, R, 1, 1, n); }

void tree_flip(ll ql, ll qr, ll i, ll l, ll r) {
  // prop -> apply and push;
  prop(i, l, r);
  if (qr < l || r < ql)
    return;
  if (l == r) {
    s1[i] = s1[i] == 1 ? 0 : 1;
    return;
  }
  if (ql <= l && r <= qr) {
    s1[i] = r - l + 1 - s1[i];
    s2[i * 2] = apply_flip(s2[i*2]);
    s2[i * 2 + 1] = apply_flip(s2[i*2+1]);
    return;
  }

  ll lt = 2 * i, rt = 2 * i + 1, mid = (l + r) / 2;
  tree_flip(ql, qr, lt, l, mid);
  tree_flip(ql, qr, rt, mid + 1, r);
  s1[i] = s1[lt] + s1[rt];
}
void tflip(ll L, ll R) { tree_flip(L, R, 1, 1, n); }


// http://lbv-pc.blogspot.com/2012/10/ahoy-pirates_24.html
/*
 propagate() {
  calculate curr tree node based on current modification
  only set children resultant modifier (need to combine child modifier with curr modifier to produce resultant modifier)
  reset current modifier to none;
 }

 modify () {
  propagate curr tree node(for existing modification);
  calculate tree node value based on current modification;
  only set children resultant modifier (need to combine child modifier with curr modifier to produce resultant modifier)
 }
 */
