
const int maxn = 2e5 + 5;
int n, q, x, y, A[maxn], B[maxn];
vector<int> segtree[4 * maxn];

void build(int r, int s, int e) {
  if(s != e) {
    int mid = (s + e) / 2;
    build(r * 2, s, mid);
    build(r * 2 + 1, mid + 1, e);
    segtree[r].resize(e - s + 1);
    merge(segtree[r * 2].begin(), segtree[r * 2].end(), segtree[r * 2 + 1].begin(), segtree[r * 2 + 1].end(), segtree[r].begin());
  } else {
    segtree[r].push_back(B[s]);
  }
}

// count distinct elements in range L, R
int qr(int r, int s, int e, int i, int j) {
  if(e < i || s > j) return 0;
  if(i <= s && j >= e) {
    return segtree[r].end() - upper_bound(segtree[r].begin(), segtree[r].end(), j);
  }
  int mid = (s + e) / 2;
  return qr(r * 2, s, mid, i, j) + qr(r * 2 + 1, mid + 1, e, i, j);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;

  build(1, 1, n);
  // queries, 1 based indexing;
  for(int i = 0; i < q; i++) {
    cin >> x >> y;
    cout << qr(1, 1, n, x, y) << '\n';
  }
  return 0;
}