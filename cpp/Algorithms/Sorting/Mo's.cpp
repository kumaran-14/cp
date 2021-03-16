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

ll tc, n, m, k;

const ll maxn = 2e5 + 5;
vvll graph(maxn);
ll timer = 0;
vll tin(maxn), tout(maxn), inputcolor(maxn), col(maxn);
vll eutour(2*maxn);

void dfs(ll u, ll p) {
  tin[u] = ++timer;
  for (auto v : graph[u]) {
    if (v == p)
      continue;
    dfs(v, u);
  }
  tout[u] = ++timer;
}

// Mo node
const int BLOCK = sqrt(maxn);
struct moquery {
  int l, r, id;
};

bool moqrycomp(moquery A, moquery B) {
  if (A.l / BLOCK != B.l / BLOCK) {
    return A.l < B.l;
  }
  return A.l / BLOCK % 2 ? A.r > B.r : A.r < B.r;
}

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  cin >> n;
  int colorid = 0;
  map<int, int> hm;
  // coordinate compression; from 1e9 to 1e5
  rep(u, 1, n + 1) {
    cin >> inputcolor[u];
    if (hm.find(inputcolor[u]) != hm.end()) {
      // seen color
      col[u] = hm[inputcolor[u]];
    } else {
      //  unseen color
      col[u] = hm[inputcolor[u]] = colorid++;
    }
  }

  rep(u, 0, n - 1) {
    ll a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(1, 1);

  // eutour;
  rep(u, 1, n+1) {
    eutour[tin[u]] = eutour[tout[u]] = col[u];
  }
  // mo's algorithm;
  vector<moquery> qs(n+1); // for n nodes;
  rep(u, 1, n+1) {
    int l = tin[u], r = tout[u], qid = u;
    qs[u].l = l, qs[u].r = r, qs[u].id = qid;
  }
  sort(qs.begin(), qs.end(), moqrycomp);

  int cnt = 0;
  vll ds(colorid); // mo query datastructure, here it is a map for counting unique nodes;

  auto add = [&](int eut) {
    if(ds[eutour[eut]] == 0) cnt++;
    ds[eutour[eut]]++;
  };

  auto remove = [&](int eut) {
    if(ds[eutour[eut]] == 1) cnt--;
    ds[eutour[eut]]--;
  };

  vll ans(n+1);
  int currL = 0, currR = 0;
  rep(i, 1, n+1) {
    int L = qs[i].l, R = qs[i].r, id = qs[i].id;
    while(currL < L) {
      remove(currL);
      currL++;
    }
    while(currL > L) {
      currL--;
      add(currL);
    }
    while(currR < R) {
      currR++;
      add(currR);
    }
    while(currR > R) {
      remove(currR);
      currR--;
    }
    ans[id] = cnt;
  }
  rep(u, 1, n+1) cout<<ans[u]<<" ";

  return 0;
}

// cses problem distinct queries