#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define f first
#define s second
#define pb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define db(x) cout << '>' << #x << ':' << x << endl;
#define sz(x) ((int)(x).size())
#define newl cout << "\n"
#define all(v) v.begin(), v.end()

#define ll long long int
#define ld long double
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long, long long>

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// clang-format on
ll tc, n, m, k;

const ll mxN = 2e5 + 7;

void solve() {
  ll A, B; cin>>A>>B>>n;
 
  ll ma[n], mb[n];
  rep(i, 0, n) cin>>ma[i];
  rep(i, 0, n) cin>>mb[i];
  ll h = B;
  rep(i, 0, n) {
    ld x = ceil((ld)mb[i]/(ld)A);
    ll y = ceil((ld)h/(ld)(ma[i]));
    if(y < x) {
      cout<<"NO";
      newl;
      return;
    }
    h -= x*ma[i];
  }
  cout<<"YES";
  newl;
}

int main() {
  fast_io();
//#ifndef ONLINE_JUDGE
//  freopen("../input.txt", "r", stdin);
//  freopen("../output.txt", "w", stdout);
//#endif

  tc = 1;
//  cin>>tc;
  while(tc--) {
    solve();
  }

  return 0;
}
