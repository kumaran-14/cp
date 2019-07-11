// kumaran_14
// https://www.hackerrank.com/challenges/count-luck/problem
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
#define vvi vector<vector<int>>
// vector<vector<int>> v(10, vector<int>(10,1)); 2d vector initialization.
// Initialization value is 1.
#define si set<int>
#define mii map<int, int>
#define mll map<long long, long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pcc pair<char, char>
#define pdd pair<double, double>

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

ll cans;
ll tc, n, m, i, j, k;
pll start, dest;

bool isoutofbounds(pll pos)
{
  if (pos.f < 0 || pos.s < 0 || pos.f >= n || pos.s >= m)
    return true;
  return false;
}

int choices(pll pos, vector<vector<char>> &graph, map<pll, bool> &path)
{
  int interim = 0;
  ll i, j;
  i = pos.f;
  j = pos.s;

  if (!isoutofbounds(mp(i - 1, j)) && graph[i - 1][j] == '.' && !path[mp(i - 1, j)] && !(i - 1 == dest.f && j == dest.s))
    interim++;
  if (!isoutofbounds(mp(i, j + 1)) && graph[i][j + 1] == '.' && !path[mp(i, j + 1)] && !(i == dest.f && j + 1 == dest.s))
    interim++;
  if (!isoutofbounds(mp(i + 1, j)) && graph[i + 1][j] == '.' && !path[mp(i + 1, j)] && !(i + 1 == dest.f && j == dest.s))
    interim++;
  if (!isoutofbounds(mp(i, j - 1)) && graph[i][j - 1] == '.' && !path[mp(i, j - 1)] && !(i == dest.f && j - 1 == dest.s))
    interim++;
  return interim;
}

bool dfs(vector<vector<char>> &graph, map<pll, bool> &path, pll &start)
{
  if (isoutofbounds(start))
    return false;
  if (start.f == dest.f && start.s == dest.s)
  {
    return true;
  }
  ll i, j;
  i = start.f;
  j = start.s;
  if (graph[i][j] != '.' || path.find(mp(i, j)) != path.end())
    return false;
  path[mp(i, j)] = true;
  pll north = mp(i - 1, j);
  pll east = mp(i, j + 1);
  pll south = mp(i + 1, j);
  pll west = mp(i, j - 1);
  ll found = 0;
  if (dfs(graph, path, west))
  {
    return true;
    found = 1;
  }
  if (dfs(graph, path, east))
  {
    return true;
    found = 1;
  }
  if (dfs(graph, path, south))
  {
    return true;
    found = 1;
  }
  if (dfs(graph, path, north))
  {
    return true;
    found = 1;
  }
  if (found)
    return true;
  path[mp(i, j)] = false;
  return false;
}

int main()
{
  fast_io();
  cin >> tc;
  while (tc--)
  {
    cin >> n >> m;
    string str;
    vector<vector<char>> graph(n, vector<char>(m));
    map<pll, bool> path;
    foi(i, 0, n)
    {
      cin >> str;
      foi(j, 0, m)
      {
        if (str[j] == '*')
        {
          dest = mp(i, j);
          str[j] = '.';
        }
        if (str[j] == 'M')
        {
          start = mp(i, j);
          str[j] = '.';
        }
        graph[i][j] = str[j];
      }
    }
    cin >> k;
    cans = 0;
    bool res = false;
    res = dfs(graph, path, start);
    for (auto x : path)
    {
      if (x.s)
      {
        if (choices(x.f, graph, path) > 0)
          cans++;
      }
    }

    if (cans == k)
    {
      cout << "Impressed" << endl;
    }
    else
    {
      cout << "Oops!" << endl;
    }
  }
  return 0;
}
