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

// O(n^2)
pair<vll, vll> trivial(ll T, string str) {
  vll d1(T), d2(T);
  foi(i, 0, T) {
    //odd length;
    d1[i] = 1;
    while(i-d1[i] >= 0 && i+d1[i] <= T-1 && str[i-d1[i]] == str[i+d1[i]]) {
      d1[i]++;
    }
    //even length;
    d2[i] = 0;
    while(i-d2[i] -1 >= 0 && i + d2[i] <= T-1 && str[i-d2[i]-1] == str[i+d2[i]]) {
      d2[i]++;  
    }
  }
  return {d1, d2};
}

//O(n)
pair<vll, vll> manacher(ll T, string str) {
  vll d1(T), d2(T);

  // odd
  ll left = 0;
  ll right = -1;
  foi(i, 0, T) {
    ll k = i > right ? 0 : min(d1[left + right-i], right - i +1);
    while( i - k >= 0 && i + k <= T-1 && str[i-k] == str[i+k]) {
      k++;
    }
    d1[i] = k--;
    if(i+k> right) {
      left = i - k;
      right = i + k;
    }
  }

  //even
  left = 0;
  right = -1;
  foi(i, 0, T) {
    ll k = i > right ? 0 : min(d2[left + right-i+1], right - i +1);
    while( i - k -1 >= 0 && i + k <= T-1 && str[i-k-1] == str[i+k]) {
      k++;
    }
    d2[i] = k--;
    if(i+k> right) {
      left = i - k -1;
      right = i + k;
    }
  }
  return {d1, d2};
}

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    string str;
    cin>>str;
    pair<vll, vll> ans = manacher(sz(str), str);
    for(auto x:ans.f) cout<<x<<" ";
      cout<<endl;
    for(auto y:ans.s) cout<<y<<" ";
  }
  return 0;
}
