// kumaran_14
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define p push
#define mp make_pair
#define pb push_back
#define foi(i, a, n) for (i = (a); i < (n); ++i)
#define foii(i, a, n) for (i = (a); i <= (n); ++i)
#define fod(i, a, n) for (i = (a); i > (n); --i)
#define fodd(i, a, n) for (i = (a); i >= (n); --i)
#define gcd __gcd
#define mem(a, b) memset(a, b, sizeof a)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl "\n"
#define println(a) cout << (a) << endl
#define PI 3.141592653589793238L
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18

#define l long int
#define d double
#define ll long long int
#define ld long double
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vll>
//vector<vector<int>> v(10, vector<int>(20,500)); 2d vector initialization. of 10 rows and 20 columns.
// Initialization value is 500.
#define si set<int>
#define mii map<int, int>
#define mll map<long long, long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pcc pair<char, char>
#define pdd pair<double, double>

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

ll tc, n, m, k;
// ll ans = 0, c = 0;
ll i, j;
// ll a, b;
// ll x, y;

// 2d graph adj matrix. dist[i][j] is integer or INFLL, denoting path dist, or no path.
vvll dist(n + 1, vll(n + 1, INFLL));
vvll path(n + 1, vll(n + 1, n));

void floydwarshall()
{
  foii(i, 1, n)
  {
    dist[i][i] = 0;
    foii(j, 1, n)
    {
      path[i][j] = i;
    }
  }
  foii(k, 1, n)
  {
    foii(i, 1, n)
    {
      foii(j, 1, n)
      {
        //negative edge
        if (dist[i][k] < INFLL && dist[k][j] < INFLL)
        {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          path[i][j] = path[k][j];
        }
      }
    }
  }
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  n = 100;
  return 0;
}
