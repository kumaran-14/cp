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
ll i, j;
// ll a, b;
// ll x, y;

// O(n^2)
void LIS_1() {
  cin>>n;
  vll arr(n+1, 0);
  foi(i, 0, n) cin>>arr[i];    
  vll dp(n+1, 0);
  dp[n-1] = 1;
  fodd(i, n-2, 0) {
    foi(j, i+1, n) {
      if(arr[i] < arr[j]) {
        dp[i] = max(dp[i], dp[j]);
      }
    }
    dp[i] += 1;
  }
  ll ans = *max_element(all(dp));
  cout<<ans<<endl;
}

// O(n2) solution
// LIS = LCS of (given array) and (increasing sorted array)


// O(nLogn)
int lengthOfLIS(vector<int>& nums) {
    vector<int> vec;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
        if(it == vec.end()) vec.push_back(nums[i]);
        else *it = nums[i];
    }
    return vec.size();
}
// to make it non-decreasing, change lower to upper

// How to form the longest increasing subsequence?
// Tip: see longestDivisileSubset. Its like recursive parent

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    
  }
  return 0; 
}


/*

2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

*/

