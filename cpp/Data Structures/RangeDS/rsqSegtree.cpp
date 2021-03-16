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
const int lg = 22;

ll t[2*mxN];

void build() {
  for(int i = n-1; i > 0; i--) {
    t[i] = t[i*2]+t[i*2 + 1];
  }
}
void upd(ll i, ll val) {
  t[i+=n] = val;
  for(i /= 2; i; i /= 2) {
    t[i] = t[i*2]+t[i*2+1];
  }
}

// sum on interval [l, r]
ll qry(ll l, ll r) {
  ll ra = 0, rb = 0;
  // r+=n  if needed sum on interval [l, r);
  for(l += n, r += n+1; l < r; l /=2, r /= 2) {
    if(l&1) ra += t[l++];
    if(r&1) rb += t[--r];
  }
  return (ra+rb);
}


int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  ll q;
  cin >> n >> q;

  rep(i, 0, n) {
    cin>>t[i+n];
  }

  build();

  while (q--) {
    ll type;
    cin>>type;
    if(type == 1) {
      ll k, u;
      cin>>k>>u;
      k--;
      upd(k, u);
    } else {
      ll L, R; cin>>L>>R; L--, R--;
      cout<<qry(L, R);
      newl;
    }
  }


  return 0;
}