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
ll i, j;
// ll ans = 0, c = 0;
// ll a, b;
// ll x, y;

// vector<vector<pll>> adjgraph(100005);
// vll dist(100005, INFLL);
vvll adjmat(1005, vll(1005, 0));
vvll dist(1005, vll(1005, INFLL));
vll rows = {0, 0, 1, -1};
vll cols = {1, -1, 0, 0};

void dijkstra(ll x, ll y)
{
  dist[x][y] = 0;
  //pll => {dist, {x, y}}
  set<pair<ll, pll>> q;
  //optimization: we dont need to store pair, only vertex. Overload with custom comparator for set which compares based on dist.
  q.insert({0, {x, y}});
  while (!q.empty())
  {
    pll v = q.begin()->s;
    q.erase(q.begin());
    ll curri = v.f;
    ll currj = v.s;
    foi(k, 0, 4)
    {
      ll nexti = curri + rows[k];
      ll nextj = currj + cols[k];
      if (nexti >= 1 && nexti <= n && nextj >= 1 && nextj <= m && adjmat[nexti][nextj])
      {
        if (dist[curri][currj] + 1 < dist[nexti][nextj])
        {
          q.erase({dist[nexti][nextj], {nexti, nextj}});
          dist[nexti][nextj] = dist[curri][currj] + 1;
          q.insert({dist[nexti][nextj], {nexti, nextj}});
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
  //2d matrix. so n should be reasonable
  n = 1005;

  return 0;
}
