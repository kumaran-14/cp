// kumaran_14
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define p push
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define foi(i, a, n) for (i = (a); i < (n); ++i)
#define foii(i, a, n) for (i = (a); i <= (n); ++i)
#define fod(i, a, n) for (i = (a); i > (n); --i)
#define fodd(i, a, n) for (i = (a); i >= (n); --i)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl " \n"
#define MAXN 100005
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18

#define l long int
#define d double
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vll>
//vector<vector<int>> v(10, vector<int>(20,500)); 2d vector initialization. of 10 rows and 20 columns, with value 500.
#define mii map<int, int>
#define mll map<long long, long long>
#define pii pair<int, int>
#define pll pair<long long, long long>

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

ll tc, n, m, k;
// ll ans = 0, c = 0;
ll i, j;
// ll a, b;
// ll x, y;

const ll K = 25; //(2^25)
// st[5][4] = [5, 5+2^4 + -1] ==> [5, 20]
vvll st(MAXN, vll(K+1));
vll logarithm(MAXN+1);
vll arr(MAXN);

void precomputeRMQ() {
  // precompute log2(R-L+1);
  logarithm[1] = 0;
  foii(i, 2, MAXN) {
    logarithm[i] = logarithm[i/2] + 1;
  }

  foi(i, 0, n) {
    st[i][0] = arr[i];
  }
  foii(j, 1, K) {
    for(i=0; i + (1<<j) <= n;i++) {
      st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
      //[i, i+2^j +-1 ] = min([i, i+2^(j-1) +-1], [i+2^(j-1), (i+2^(j-1)) + 2^(j-1) -1])
    }
  }
}

ll RMQ(ll L, ll R) {
  // L <= R
  ll exp = logarithm[R-L+1];
  ll minans = min(st[L][exp], st[R-(1<<exp)+1][exp]);
  return minans; 
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>n;
  foi(i, 0, n) {
    cin>>arr[i];
  }
  precomputeRMQ();
  ll x, y;
  foi(x,0, n) {
    foi(y, x, n) {
      cout<<"RMQ("<<x<<","<<y<<"): ";
      cout<<RMQ(x, y)<<" ";
    }
    cout<<endl;
  }
  return 0;
}
