// Increasing Array Queries (https://cses.fi/problemset/task/2416)
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <unistd.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define repr(a, b) for (int a = b; a >= 0; --a)

using namespace std;

using ll = long long;

char buf[1 << 26];
char* iptr = &buf[0];

int read() {
  int v = 0;
  while (*iptr <= ' ') ++iptr;
  while (*iptr > ' ')
    v = 10 * v + (*iptr++ - '0');
  return v;
}

constexpr int N = 200'000, Q = N;
int x[N], flank[N];
ll xsuff[N + 1], ans[Q], flanksuff[N];
vector<pair<int, int>> qs[N];
int fi = -1;

int main() {
  read(STDIN_FILENO, buf, sizeof(buf));

  int n = read();
  int q = read();
  rep(i, n) x[i] = read();
  rep(i, q) {
    int l = read() - 1;
    int r = read();
    qs[l].emplace_back(r, i);
  }
  repr(i, n - 1)
    xsuff[i] = x[i] + xsuff[i + 1];

  repr(i, n - 1) {
    while (fi >= 0 && x[flank[fi]] <= x[i])
      --fi;
    int r = fi >= 0 ? flank[fi] : n;
    ll suff = fi >= 0 ? flanksuff[fi] : 0ll;
    flank[++fi] = i;
    flanksuff[fi] = (r - i) * ll(x[i]) + suff;

    for (auto [qr, qi] : qs[i]) {
      ans[qi] = flanksuff[fi] - xsuff[i] + xsuff[qr];
      reverse_iterator itb(&flank[fi + 1]), ite(&flank[0]);
      auto it = lower_bound(itb, ite, qr);
      if (it != ite)
        ans[qi] -= flanksuff[fi - (it - itb)];
      ans[qi] -= ll((it == ite ? n : *it) - qr) * x[*prev(it)];
    }
  }

  char* optr = &buf[0];
  rep(i, q) {
    auto start = optr;
    do
      *optr++ = '0' + ans[i] % 10, ans[i] /= 10;
    while (ans[i]);
    reverse(start, optr);
    *optr++ = '\n';
  }
  write(STDOUT_FILENO, buf, optr - buf);

  return 0;
}