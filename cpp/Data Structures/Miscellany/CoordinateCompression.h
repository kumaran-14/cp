/**
 * coordinate compression, get index of x by counting # of elements < x
 */
// v1
template <class T> void nor(vector<T> &v) {
  sort(all(v));
  v.erase(unique(all(v)), end(v));
}
template <class T> int ind(vector<T> &v, T x) {
  return lower_bound(all(v), x) - begin(v);
}

// v2
map<int, int> compressed, decompress;
for (int i = 1; i <= n; i++) {
  cin >> a[i];
  compressed[a[i]] = 0;
}
int index = 1;
for (auto &i : compressed) {
  i.second = index++;
  decompress[i.second] = i.first;
}
