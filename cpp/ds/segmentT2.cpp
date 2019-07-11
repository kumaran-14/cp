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

ll tc, n;
// segtree indexes: 1-100000
vll segt(100001, 0);
// clear all values. fill(all(segt), 0);
vll arr(100001, 0);
// clear all values. fill(all(arr), 0);

//treeidx -> range between [left, right] of corresponding given array. inclusive. rl is rangeleft, rr is range right.
// Eg: tree[1] holds the range of all elements of given array. [0, n-1]
void buildsegtree(ll treeidx, ll rl, ll rr)
{
  if (rl == rr)
  {
    segt[treeidx] = arr[rl];
  }
  else
  {
    ll mid = rl + ((rr - rl) / 2);
    buildsegtree(2 * treeidx, rl, mid);
    buildsegtree(2 * treeidx + 1, mid + 1, rr);
    segt[treeidx] = segt[2 * treeidx] + segt[2 * treeidx + 1];
  }
}

// rr is rangeleft, rr is rangeright. for tree[1] = [0, n-1] (all elements)
void updatesegtree(ll treeidx, ll rl, ll rr, ll arridx, ll incdata)
{
  if (rl == rr)
  {
    arr[arridx] += incdata;
    segt[treeidx] += incdata;
  }
  else
  {
    ll mid = rl + ((rr - rl) / 2);
    if (rl <= arridx && arridx <= mid)
    {
      updatesegtree(2 * treeidx, rl, mid, arridx, incdata);
    }
    else
    {
      updatesegtree(2 * treeidx + 1, mid + 1, rr, arridx, incdata);
    }
    segt[treeidx] = segt[2 * treeidx] + segt[2 * treeidx + 1];
  }
}

// rr is rangeleft, rr is rangeright. for tree[1] = [0, n-1] (all elements)
// qstart and qleft is needed query range (inclusive). Eg: [0,3] (for first 4 elements). [3,3]: for the 4th element.
ll querytree(ll treeidx, ll rl, ll rr, ll qstart, ll qend)
{
  if (qend < rl || qstart > rr)
  {
    return 0;
  }
  if (rl >= qstart && qend >= rr)
  {
    return segt[treeidx];
  }
  ll mid = rl + ((rr - rl) / 2);
  ll p1 = querytree(2 * treeidx, rl, mid, qstart, qend);
  ll p2 = querytree(2 * treeidx + 1, mid + 1, rr, qstart, qend);
  return p1 + p2;
}

int main()
{
  fast_io();
  n = 6;
  arr[0] = 1;
  arr[1] = 30;
  arr[2] = 50;
  //4th element
  arr[3] = 700;
  arr[4] = 1000;
  arr[5] = 5000;
  // freopen("./input.txt", "r", stdin);
  // freopen("./output.txt", "w", stdout);
  buildsegtree(1LL, 0LL, n - 1);
  ll i, j;
  // ll sum = querytree(1LL, 0LL, n - 1, 3, 3); //4th element in given arr;
  ll sum = querytree(1LL, 0LL, n - 1, 1, 4); //2nd to 5th element. [1, 4]
  cout << sum << endl;
  ll maxTreeidx = 4 * n;
  foii(i, 1, maxTreeidx)
  {
    cout << segt[i] << " ";
  }
  cout << endl;
  //increase last element by 4000;
  updatesegtree(1LL, 0, n - 1, n - 1, 4000);
  foii(i, 1, maxTreeidx)
  {
    cout << segt[i] << " ";
  }
  cout << endl;
  //check if last element is updated;
  sum = querytree(1LL, 0LL, n - 1, n - 1, n - 1); //last element in given arr;

  return 0;
}
