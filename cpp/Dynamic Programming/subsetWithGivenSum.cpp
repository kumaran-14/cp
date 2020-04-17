// kumaran_14

// #include <boost/multiprecision/cpp_int.hpp> 
// using boost::multiprecision::cpp_int;  
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
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vull vector<ull>
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

ll tc;
// ll ans = 0, c = 0;
ll i, j;
// ll a, b;
// ll x, y;

ll n, k;
vll arr;


// vll arr(MAXN, 0);
// vector<vector<bool>> dp(101, vector<bool>(101, false));
// vvll subset;

// void printRecSubsum(ll n, ll sum, vll ansarr = {}) {
                                                                    //version 1  (prunes impossible branches)
//   if(sum == 0) {
//     subset.pb(ansarr);
//     return;
//   }
//   if(sum < 0) return;
//   if(dp[n][sum]) {                                               // use the boolean(OR) version of subsetsum function.
//     printRecSubsum(n-1, sum, ansarr);
//     ansarr.pb(arr[n-1]);
//     printRecSubsum(n-1, sum-arr[n-1], ansarr);
//   } else {
//     return;
//   }
                                                                    // version 2,  O(2^n)
    // if(sum == 0) {
    // subset.pb(ansarr);
    // return;
    // }
    // if(n == 0) return;
    
    // printRecSubsum(n-1, sum, ansarr);
    // ansarr.pb(arr[n-1]);
    // printRecSubsum(n-1, sum-arr[n-1], ansarr);
// }


// state is {n, curr
// _sum}
int recursiveSubsetSum(ll n, ll curr_sum) {
  if(curr_sum == 0) return 1;
  if(n == 0) return 0;
  if(arr[n-1] > curr_sum) {
    return recursiveSubsetSum(n-1, curr_sum);
  }
  return recursiveSubsetSum(n-1, curr_sum-arr[n-1]) + recursiveSubsetSum(n-1, curr_sum);
}

// state {i, j} == {n, sum}
// space : O(sum*n)
int dpSubsetSum(ll n, ll sum) {
  vvll dp(n+1, vll(sum+1, 0));
  //base case, any number of elements left and sum is 0;
  foii(i, 0, n) {
    dp[i][0] = 1;
  }
  // run out of elements ,while sum != 0;
  foii(i, 1, sum) {
    dp[0][i] = 0;
  }
  foii(i, 1, n) {
    foii(j, 0, sum) {
      dp[i][j] = dp[i-1][j];
      if(arr[i-1] <= j) {
        dp[i][j] += dp[i-1][j - arr[i-1]];
      }
    }
  }
  return dp[n][sum];

  /* split array to two subset, such that diff between them is minimized.*/
  /*
    rep(i, sum/2+1, 0) {
        if(dp[n][i])
         cout<<((sum-j)-j)<<endl;
         break;
   }

   */
}


// state {i, j} == {n, sum}
//space: O(sum)
int dpSubsetSum_2(ll n, ll sum) {
  vvll dp(2, vll(sum+1, 0));
  dp[0][0] = 1;
  dp[1][0] = 1;
  foii(i, 1, n) {
    foii(j, 1, sum) {
      dp[1][j] = dp[0][j];
      if(arr[i-1] <= j) {
        dp[1][j] += dp[0][j-arr[i-1]];
      }
    }
    if(j != sum) {
      dp[0] = dp[1];
    }
  }
  return dp[1][sum];
}


int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    ll n;
    cin>>n;
    arr.resize(n, 0);
    foi(i, 0, n) {
      cin>>arr[i];
    }
    ll k;
    cin>>k;
    ll ans = INT_MAX;
    // ans = recursiveSubsetSum(n, k);
    // ans = dpSubsetSum(n, k);
    // ans = dpSubsetSum_2(n, k);
    cout<<ans<<endl;
  }
  return 0;
}


/*
input
1  // testcases
6  //arr size
4 34 7 12 5 3 // arr el
9 // sum:9. Find subset with sum =9;
*/