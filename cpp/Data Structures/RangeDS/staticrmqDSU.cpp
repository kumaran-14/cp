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
const int mxN = 2e5 + 7;
const int mxM = 500;

// static rmq using dsu
ll par[mxN];
ll arr[mxN];
ll rmq[mxN];

struct query {
  ll id, L, R;
};
vector<query> qs[mxN];

ll root(ll u) {
  if (par[u] == u)
    return u;
  return par[u] = root(par[u]);
}

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif


  iota(par, par + mxN, 0);
  ll q;
  cin >> n >> q;
  rep(i, 0, n) cin >> arr[i];

  rep(qid, 0, q) {
    ll L, R;
    cin >> L >> R; L--, R--;
    query qq;
    qq.L = L, qq.id = qid, qq.R = R;
    qs[R].pb(qq);
  }
  // stack of indices
  stack<ll> st;
  rep(R, 0, n) {
    // strictly increasing stack;
    while (!st.empty() && arr[st.top()] > arr[R]) {
      par[st.top()] = R;
      st.pop();
    }
    st.push(R);
    for (auto qq : qs[R]) {
      rmq[qq.id] = arr[root(qq.L)];
    }
  }

  rep(qid, 0, q) {
    cout << rmq[qid];
    newl;
  }

  return 0;
}