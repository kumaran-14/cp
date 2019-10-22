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

ll tc, n, m, k;
// ll ans = 0, c = 0;
// ll i, j;
// ll a, b;
// ll x, y;

ll sumofnat(ll x) {
  //sum of first x num, 1 + 2 + 3 + ...
  return (x*(x+1))/2;
}


int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);

  cin>>n;
/*

sort(all(arr));
if(arr[0] == arr[1] && arr[1] == arr[2]) {
  // all are same
  ll ans = 0;
  if(arr[0]%2 == 0) {
    //even
    ans += (arr[0]/2)*3;
  } else {
    //odd
    ans += (arr[0]/2)*3 + 1;
  }
  ll sub = arr[0];
  rep(i, 0, n) {
    arr[i] -= sub;
  }
  // debug(ans);
  // rep(i, 0, n) cout<<arr[i]<<" ";
  ans += min(arr[1], arr[2]);
  // debug(ans); P

  cout<<ans<<endl;

} else if(arr[0] == arr[1] && arr[1] != arr[2]) {
  // first two same, next is are distinct.
  ll ans = min(arr[2], 2*arr[0]);
  // debug(ans);
  // cout<<ans<<endl;
  if(arr[0]%2 == 0) {
    //even
    vll temp(3, arr[0]);
    ans = max(ans, allsame(temp));

  } else {
    //odd
    vll temp(3, arr[0]);
    ans = max(ans, allsame(temp)+1);
  }
  cout<<ans<<endl;


} else if (arr[0] != arr[1] && arr[1] == arr[2]) {
  // last two are same, first two are distinct.
  ll newans = arr[1];
  arr[1] -= newans;
  arr[2] -= newans;

  ll ans = 0;
  if(arr[0]%2 == 0) {
    //even
    ans += (arr[0]/2)*3;
  } else {
    //odd
    ans += (arr[0]/2)*3 + 1;
  }
  ll sub = arr[0];
  rep(i, 0, n) {
    arr[i] -= sub;
  }
  // debug(ans);
  // rep(i, 0, n) cout<<arr[i]<<" ";
  ans += min(arr[1], arr[2]);
  // debug(ans);
  // debug(newans + ans);
  cout<<ans+newans<<endl;;


} else {
  // all three are distinct.
  ll ans = arr[1] - arr[0];
  arr[1] -= ans;
  arr[2] -= ans;
  ll newans = min(arr[2], 2*arr[0]);
  // debug(ans);
  // cout<<ans<<endl;
  //arr[0] == arr[1], third different;
  if(arr[0]%2 == 0) {
    //even
    vll temp(3, arr[0]);
    ans = ans + max(newans, allsame(temp));

  } else {
    //odd
    vll temp(3, arr[0]);
    ans = ans + max(newans, allsame(temp)+1);
  }
  cout<<ans<<endl;

}
*/  

  return 0;
}
