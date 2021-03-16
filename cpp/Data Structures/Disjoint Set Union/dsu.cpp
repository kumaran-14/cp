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
// ll i, j;
// ll a, b;
// ll x, y;

//vectors are indexed from 1;
vll setparent(100005, 0);
vll setrank(100005, -1);
vll setsize(100005, 1);

void makeset(ll v)
{
  setparent[v] = v;
  // setsize[v] = 1;
  setrank[v] = 0;
}

void initialize(ll n) {
  ll i;
  foi(i, 0, n) makeset(i);
}

//path compression.
ll findset(ll v) {
  if (setparent[v] == v) return v;
  return setparent[v] = findset(setparent[v]);
}

//union by rank. (depth of trees)
void unionsets_rank(ll a, ll b) {
  a = findset(a);
  b = findset(b);
  if (a != b) {
    if (setrank[a] < setrank[b]) {
      swap(a, b);
    }
    setparent[b] = a;
    if (setrank[a] == setrank[b]) {
      setrank[a]++;
    }
  }
}

void unionsets_size(ll a, ll b)
{
  a = findset(a);
  b = findset(b);
  if (a != b) {
    if (setsize[a] < setsize[b]) {
      swap(a, b);
    }
    setparent[b] = a;
    setsize[a] += setsize[b];
  }
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  unordered_map<ll, ll> um;
  ll i, j, u, v, n, m;
  foii(j, 1, n)
  {
    if (um.find(findset(j)) == um.end())
    {
      um[findset(j)] = setsize[findset(j)];
    }
  }
  return 0;
}
