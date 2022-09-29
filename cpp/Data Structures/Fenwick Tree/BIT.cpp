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
ll ft[mxN];

ll tc, n, m, q;

// ---------------------- READ -----------------------
/*
 * Ft is easy when, range query, point update
 * or, range update and point qry;
 *
 * see rangeds for 2d fenwick tree with log(n)*log(n) complexity;
 */


void updatetree(ll i, ll val)
{
  i++;
  for (; i < mxN; i += i & (-i)) ft[i] += val;
}

ll querytree(ll i)
{
  i++;
  ll sum = 0;
  for (; i; i -= i & (-i)) sum += ft[i];
  return sum;
}

// lower_bound for a prefix sum k
ll get_kth(ll k) {
  ll sum = 0;
  ll pos = 0;
  for(int i = log2(mxN)+1; i>=0; i--) {
    if(pos + (1<<i) <= n && sum+ft[pos + (1<<i)] < k) {
      sum += ft[pos + (1<<i)];
      pos += (1<<i);
    }
  }
  assert(pos <= n);
  return pos+1;
}

// time complexity of operations is logn
// it is possible to construct fenwick tree in O(n) time complexity, instead of O(nlogn);
struct Fenwick {
  int n;
  vector<ll> tree;
  // 0 is not part of any range.
  // tree range is from [1....n-1];
  Fenwick(ll _n): n(_n), tree(_n) {}

  void upd(ll i, ll delta) {
    i++;
    while(i < tree.size()) {
      tree[i] += delta;
      i += i&(-i);
    }
  }
  //[1....i], both inclusive.
  // trick: sometimes total-qry(i) is useful to get suffix sum;
  ll qry(ll i) {
    i++;
    ll sum = 0;
    while(i > 0) {
      sum += tree[i];
      i -= i&(-i);
    }
    return sum;
  }
};


// incomplete range update tree. See in cp-algorithms.com
struct RangeFenwick {
  int n;
  Fenwick t1, t2;
  RangeFenwick(int _n):n(_n), t1(_n), t2(_n) {};
  void RangeUpdate(int l, int r, int x){
    t1.Update(l, x);
    t1.Update(r+1, -x);
    t2.Update(l, x*(l-1));
    t2.Update(r+1, -x*r);
  }

  int PrefixSum(int i){
    return t1.Query(i);
  }
  int RangeSum(int l, int r){
    return PrefixSum(r)-PrefixSum(l-1);
  }
};

int main()
{
  fast_io();
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  fentree[0] = -1;
  arr[0] = -1;
  // both not part of array;
  n = 6;
  arr[1] = 1;
  arr[2] = 30;
  //4th element
  arr[3] = 50;
  arr[4] = 700;
  arr[5] = 1000;
  arr[6] = 5000;
  ll i;
  rep(i, 1, n+1)
  {
    updatetree(i, arr[i]);
  }
  // query 2nd to 5th element. [2, 5]
  db(querytree(5) - querytree(1));
  db(querytree(n) - querytree(n - 1));

  //increase last element by 4000;
  updatetree(n, 4000);
  db(querytree(n) - querytree(n - 1));

  Fenwick t(7);
  rep(i, 1, n+1) t.Update(i, arr[i]);
  db(t.Query(5)-t.Query(1));
  newl; newl;

  RangeFenwick tt(15);
  tt.RangeUpdate(0, 9, 3);
  tt.RangeUpdate(6, 8, 9);
  tt.RangeUpdate(9 ,9, 3);
  tt.RangeUpdate(7, 7, 6);
  tt.RangeUpdate(5, 8, 1);
  tt.RangeUpdate(1, 2, 8);
  tt.RangeUpdate(8, 8, 2);
  tt.RangeUpdate(4, 4, 9);
  tt.RangeUpdate(3, 8, 9);
  tt.RangeUpdate(2, 2, 10);

  db(tt.PrefixSum(0));
  db(tt.PrefixSum(6));
  db(tt.PrefixSum(9));
  db(tt.PrefixSum(7));
  db(tt.PrefixSum(5));
  db(tt.PrefixSum(8));
  db(tt.PrefixSum(4));
  db(tt.PrefixSum(3));
  db(tt.PrefixSum(2));

  // note the BIT tree size : 100001;
  return 0;
}
