// kumaran_14
// kumaran_14
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define p push
#define mp make_pair
#define pb push_back
#define foi(i, a, n) for ( i = (a); i < (n); ++i)
#define foii(i, a, n) for (i = (a); i <= (n); ++i)
#define fod(i, a, n) for (i = (a); i > (n); --i)
#define fodd(i, a, n) for (i = (a); i >= (n); --i)
#define gcd __gcd
#define mem(a, b) memset(a, b, sizeof a)
#define all(v) v.begin(), v.end()
#define println(a) cout << (a) << endl
#define sz(x) ((int)(x).size())
#define PI 3.141592653589793238L
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000
#define INFLL 1000000000000000000ll

// #define l long int
#define d double
#define ll long long int
#define ld long double
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vll vector<long long>
#define vvi vector<vector <int>>
#define si set<int>
#define mii map<int, int>
#define mll map<long long, long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pcc pair<char, char>
#define pdd pair<double, double>

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main() {
  fast_io();
  ll n, tc, flag;
  int x, y;
  cin >> tc;
  while(tc--) {
      cin>>n;
      vector<pii> v;
      ll i, j;
      foi(j, 0, n) {
          cin>>x>>y;
          if(v.empty()) {
            v.pb(mp(x, y));
          } else {
            flag = 0;
            foi(i, 0, sz(v) - 1)
            {
              if(v[i].f >= x && v[i].f <= y) {
                flag = 1;
                v[i].f = min(v[i].f, x);
                v[i].s = max(v[i].s, y);
                cout << "hi";
                break;
              } else if(v[i].s >= x && v[i].s <= y) {
                flag = 1;
                v[i].f = min(v[i].f, x);
                v[i].s = max(v[i].s, y);
                cout << "olo";

                break;
              } else {
                continue;
              }
            }
            if(!flag) {
              v.pb(mp(x, y));
            }
          }
      }
      for(auto x:v)
        cout << x.f << " " << x.s << " ";
      cout << endl;
  }
}
