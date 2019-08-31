// kumaran_14

// #include <boost/multiprecision/cpp_int.hpp> 
// using boost::multiprecision::cpp_int;  
#include <bits/stdc++.h>
using namespace std;
// ¯\_(ツ)_/¯ 
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
// ¯\_(ツ)_/¯ 
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

ll tc, m, k;
// ll ans = 0, c = 0;
// ll i, j;
// ll a, b;
// ll x, y;

// (n*logn*logn) approach

string str = "banana";
ll n = sz(str);

vll suffixArr(n);
vector<pair<ll, pll>> suffixes(n);
vll indices(n);

bool customcompare(pair<ll, pll>& p1, pair<ll, pll>& p2) {
  if(p1.s.f == p2.s.f) {
    return p1.s.s < p2.s.s;
  } else {
    return p1.s.f < p2.s.f;
  }
  // sort based on lowest first and lowest second in a pair.
}

void buildSuffixArr() {
  ll i;

  foi(i, 0, n) {
    suffixes[i].f = i;
    suffixes[i].s.f = str[i]-'a';
    suffixes[i].s.s = ((i+1 < n) ? str[i+1]-'a' : -1);
  }
  // sort according to first two characters
  sort(all(suffixes), customcompare);

  // sort according to first 4, 8, 16, .. characters
  for(k = 4; k < 2*n; k = k*2) {
    // first suffix value;
    ll rank = 0;
    ll prev_rank = suffixes[0].s.f;
    suffixes[0].s.f = rank;
    indices[suffixes[0].f] = 0;

    foi(i, 1, n) {
      if(suffixes[i].s.f == prev_rank && suffixes[i].s.s == suffixes[i-1].s.s) {
        prev_rank = suffixes[i].s.f;
        suffixes[i].s.f = rank;
      } else {
        prev_rank = suffixes[i].s.f;
        suffixes[i].s.f = ++rank;
      }
      indices[suffixes[i].f] = i;
    }
    foi(i, 0, n) {
      ll nexti = suffixes[i].f + k/2;
      suffixes[i].s.s = (nexti < n) ? suffixes[indices[nexti]].s.f : -1;
    }
    sort(all(suffixes), customcompare);
  }

  // populate final ans as suffixArr
  i = 0;
  for(auto x:suffixes) suffixArr[i++] = x.f;
}


int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  // (n*logn*logn) approach
  buildSuffixArr();
  for(auto x:suffixArr) {
    cout<<x<<" ";
  }
  return 0;
}
