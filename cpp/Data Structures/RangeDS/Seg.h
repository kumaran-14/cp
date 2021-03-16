/*
 * Note usage of comb function
 * Note usage of ID, default value, set correct values for corresponding
 * associate functions
 *
 * How to initialise?
 * Seg<long long int> st;
 * st.init(n+1);
 * st.init_roots();
 *
 * swap qry with upd for range update, and point qry;
 *
 * use qry code in upd, for range update;
 *
 * It is a perfect tree only if size is power of 2, else it is a collection of perfect tree, with many roots;
 // check for i<<i. only i<<1 and i<<1^1 is correct;
 */

template <class T> struct Seg {
  const T ID = 0;
  // comb(ID,b) = b
  T comb(T a, T b) { return max(a, b); }
  vector<int> roots;
  int n;
  vector<T> seg;
  void init(int _n) {
    n = _n;
    seg.assign(2*n, ID);
  }

  void init_roots(){
    vector<int> roots_r;
    for(auto l = n, r = n<<1; l < r; l >>= 1, r >>= 1){
      if(l & 1) roots.push_back(l++);
      if(r & 1) roots_r.push_back(--r);
    }
    roots.insert(roots.end(), roots_r.rbegin(), roots_r.rend());
  }

  void pull(int p) { seg[p] = comb(seg[p<<1], seg[p<<1^1]); }

  void upd(int p, T val) { // set val at position p
    seg[p += n] = val;
    for (p = p>>1; p; p = p>>1) pull(p);
  }

  T qry(int l, int r) { // on interval [l, r]
    T ra = ID, rb = ID;
    for (l += n, r += n + 1; l < r; l = l>>1, r = r>>1) {
      if (l & 1) ra = comb(ra, seg[l++]);
      if (r & 1) rb = comb(seg[--r], rb);
    }
    return comb(ra, rb);
  }

  // below three functions, calculate first el, greater than given val, using max segment tree;
  //
  // log(n) * log(n)
  ll findfirst_1(ll rn) {
    int l = -1, r = n-1;
    while(r-l > 1) {
      auto mid = (r+l)>>1;
      if(qry(0, mid) < rn) l = mid;
      else r = mid;
    }
    if(qry(r, r) >= rn) return r;
    return -1;
  }

  // log(n); need biggest power of 2 in iterative segment tree, greater than equal to n;
  ll findfirst_2(ll x) {
    // return any value from [0, n-1] if present; else return -1;
    ll ans = -1;
    ll i = 1;
    while(i < n && seg[i] >= x) {
      if(seg[i<<1] >= x) i = i<<1;
      else if(seg[i<<1^1] >= x) i = i<<1^1;
      else return -1;
    }
    if(seg[i] >= x) return i-n;
    return -1;
  }

  // log(n), does not need n to be power of 2
  ll findfirst_3(ll x) {
    if(qry(0, n-1) < x) return -1;
    ll j = 0; // iterate every root; j = 0 because, roots is vector of root_values, which will always be > 0, as tree root is > 0
    while(j < seg.size() && seg[roots[j]] < x) {
      j++;
    }
    // found the first root, containing el>=x;
    ll i = roots[j];
    while(i < n && seg[i] >= x) {
      if(seg[i<<1] >= x) i = i<<1;
      else i = i<<1^1;
    }
    return i-n;
  }

  // findfirst index on sum seg tree; orderstatistic tree
  ll findfirst(ll ps) {
    int j = 0;
    while(seg[roots[j]] < ps) {
      ps -= seg[roots[j++]];
    }
    int i = roots[j];
    while(i < n) {
      if(seg[i<<1] < ps) {
        ps -= seg[i<<1], i = i<<1^1;
      } else i<<=1;
    }
    assert(i-n >= 0);
    assert(i-n < n);
    return i-n;
  }
};

// cses, hotel queries

// cses prefix sum;
/*
 struct node {
  ll sum = 0, pref = 0;
  node(ll _sum, ll _pref) :sum(_sum), pref(_pref) {};
  };
  T comb(T a, T b) {
    return node(a.sum+b.sum, max(a.pref, a.sum+b.pref));
  }

 */

/*

 cses subarray queries;

 struct node {
  ll sum, pref, suff, ss;
  node(){};
  node(ll _sum, ll _pref, ll _suff, ll _ss)
      : sum(_sum), pref(_pref), suff(_suff), ss(_ss) {};
};

  const T ID = node(0, 0, 0, 0);
  // comb(ID,b) = b
  T comb(T a, T b) {
    node root;
    root.sum = a.sum + b.sum;
    root.pref = max(a.pref, a.sum+b.pref);
    root.suff = max(a.suff+b.sum, b.suff);
    root.ss = max({a.suff+b.pref, root.pref, root.suff, a.ss, b.ss});
    return root;
  }
 */

/*

 */