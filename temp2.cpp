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
#define sz(x) ((int)(x).size())

#define ll long long
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

ll tc, n, m, k, i, j, x, y, a, b, ans = 0, c = 0;

void build(vll &t, vll &arr, ll v, ll tl, ll tr)
{
  if (tl == tr)
  {
    t[v] = arr[tl];
  }
  else
  {
    ll tm = (tl + tr) / 2;
    build(t, arr, v * 2, tl, tm);
    build(t, arr, v * 2 + 1, tm + 1, tr);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}

ll getmax(vll &t, ll v, ll tl, ll tr, ll l, ll r)
{
  if (l > r)
    return 0;
  if (l == tl && r == tr)
  {
    return t[v];
  }
  ll tm = (tl + tr) / 2;
  return max(getmax(t, v * 2, tl, tm, l, min(r, tm)), getmax(t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(vll& t, ll v, ll tl, ll tr, ll pos, ll new_val)
{
  if (tl == tr)
  {
    t[v] = 0;
  }
  else
  {
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
      update(t, v * 2, tl, tm, pos, 0);
    else
      update(t, v * 2 + 1, tm + 1, tr, pos, 0);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}

int main()
{
  fast_io();
  ll tc, n, m, k, i, j, x, y, a, b, q, ans = 0, c = 0;
  cin >> tc;
  while (tc--)
  {
    ans = 0;
    cin >> n >> q;
    vll v;
    foii(i, 1, n)
    {
      v.pb(i);
    }
    vll tree(4 * sz(v), 0LL);
    // tree[0] = -1;
    // tree, origin array, tree head index, array start, array end;
    build(tree, v, 1, 0, n-1);
    // for (auto x : tree)
    // {
    //   cout << x << " ";
    // }
    // cout << endl;
    // for (auto x : v)
    // {
    //   cout << x << " ";
    // }
    // cout << endl;
    while (q--)
    {
      cin >> k;
      if (k == 1)
      {
        // type 1 query;
        cin >> y;
        // cout << y << endl;
        y += ans;
        // tree, origin array, tree head index, array start, array end, update arr index, value to increment;
        update(tree, 1, 0, n-1, y-1, 0);
        // for (auto x : tree)
        // {
        //   cout << x << " ";
        // }
        // cout << endl;
        // for (auto x : v)
        // {
        //   cout << x << " ";
        // }
        // cout << endl;
      }
      else
      {
        //type 2 query;
        cin >> a >> b;
        // cout << a<<b << endl;
        a += ans;
        b += ans;
        // tree, tree head index, tree head range -start and end, query left and query right.
        c = getmax(tree, 1, 0, n-1, a-1, b-1);
        ans = ((ans + c) % n);
        cout << c << "\n";
      }
    }
  }
  return 0;
}
/*
1
7 3
2 2 5
1 0
2 -3 0
*/
