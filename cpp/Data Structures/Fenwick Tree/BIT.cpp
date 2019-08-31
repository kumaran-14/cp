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

// ll tc, n, m, k, i, j, x, y, a, b, ans = 0, c = 0;
ll tc, n;
// fentree starts from index 1.
vll fentree(100001, 0);
// arr also starts from index 1;
vll arr(100001, 0);

void updatetree(ll i, ll val)
{
  for (; i <= n; i += i & (-i))
  {
    fentree[i] += val;
  }
}

ll querytree(ll i)
{
  ll sum = 0;
  for (; i > 0; i -= i & (-i))
  {
    sum += fentree[i];
  }
  return sum;
}

int main()
{
  fast_io();
  fentree[0] = -1;
  arr[0] = -1;
  // both not part of array;
  n = 6;
  arr[1] = 1;
  arr[2] = 30;
  //4th element
  arr[3] = 50;
  arr[4] = 700;
  arr[5] = 1000;
  arr[6] = 5000;
  ll i;
  foii(i, 1, n)
  {
    updatetree(i, arr[i]);
  }
  // query 2nd to 5th element. [2, 5]
  ll ans = querytree(5) - querytree(1);
  cout << ans;
  //increase last element by 4000;
  updatetree(n, 4000);
  cout << endl;
  cout << querytree(n) - querytree(n - 1);
  // freopen("./input.txt", "r", stdin);
  // freopen("./output.txt", "w", stdout);

  // note the BIT tree size : 100001;
  return 0;
}
