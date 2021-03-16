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

const ll mxN = 1e2 + 5;
const ll mxM = 1e2 + 7;
ll inf = 1e14 + 7;
ll mod = 1e9 + 7;


int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  cin>>n;
  vll x(n), y(n), z(n);
  auto comp = [&](ll i, ll j) {
    if(x[i] == x[j]) {
      if(y[i] == y[j]) {
        return z[i] < z[j];
      } else {
        return y[i] < y[j];
      }
    } else {
      return x[i] < x[j];
    }
  };

  rep(i, 0, n) {
    cin>>x[i]>>y[i]>>z[i];
  }
  vll ind(n);
  iota(all(ind), 0);

  sort(all(ind), comp);

  for(int i = 0; i < n; i += 2) {
    cout<<ind[i]+1<<" "<<ind[i+1]+1;
    newl;
  }

  return 0;
}
