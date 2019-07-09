// kumaran_14
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define p push
#define mp make_pair
#define pb push_back
#define foi(i, a, n) for (i = (a); i < (n); ++i)
#define sz(x) ((int)(x).size())

#define ll long long
#define vi vector<int>

void buildsegtree(vi &tree, vi &v, ll treeidx, ll l, ll r)
{
  if (l == r)
  {
    tree[treeidx] = v[l];
  }
  else
  {
    ll mid = l + ((r - l) / 2);
    buildsegtree(tree, v, 2 * treeidx, l, mid);
    buildsegtree(tree, v, 2 * treeidx + 1, mid + 1, r);
    tree[treeidx] = tree[2 * treeidx] + tree[2 * treeidx + 1];
  }
}

void updatesegtree(vi &tree, vi &v, ll treeidx, ll l, ll r, ll vidx, ll incdata)
{
  if (l == r)
  {
    v[vidx] += incdata;
    tree[treeidx] += incdata;
  }
  else
  {
    ll mid = l + ((r - l) / 2);
    if (l <= vidx && vidx <= mid)
    {
      updatesegtree(tree, v, 2 * treeidx, l, mid, vidx, incdata);
    }
    else
    {
      updatesegtree(tree, v, 2 * treeidx + 1, mid + 1, r, vidx, incdata);
    }
    tree[treeidx] = tree[2 * treeidx] + tree[2 * treeidx + 1];
  }
}
// l , r refers to node range. qstart and qend refers to query range.
ll querytree(vi &tree, ll treeidx, ll l, ll r, ll qstart, ll qend)
{
  if (qend < l || qstart > r)
  {
    return 0;
  }
  if (l >= qstart && qend >= r)
  {
    return tree[treeidx];
  }
  ll mid = l + ((r - l) / 2);
  ll p1 = querytree(tree, 2LL * treeidx, l, mid, qstart, qend);
  ll p2 = querytree(tree, 2 * treeidx + 1, mid + 1, r, qstart, qend);
  return p1 + p2;
}

int main()
{
  vi v = {1, 30, 50, 700, 1000, 5000};
  vi tree(4 * sz(v), 0LL);
  tree[0] = -1;
  // tree, origin array, tree head index, array start, array end;
  buildsegtree(tree, v, 1LL, 0, sz(v) - 1);
  // tree, origin array, tree head index, array start, array end, update arr index, value to increment;
  // tree, tree head index, tree head range -start and end, query left and query right.
  ll sum = querytree(tree, 1, 0, sz(v) - 1, 1, 3);
  cout << "Sum: " << sum << endl;
  // updatesegtree(tree, v, 1, 0, (sz(v) - 1), 1, 7);
  sum = querytree(tree, 1, 0, (sz(v) - 1), 1, 3);
  cout << "sum: " << sum << endl;
  for (auto x : tree)
    cout << " " << x;
  return 0;
}
