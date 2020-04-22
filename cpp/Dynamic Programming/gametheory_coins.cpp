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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl " \n"
#define newl cout<<"\n"
#define MAXN 100005
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18
// ¯\_(ツ)_/¯
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define vll vector<long long>
#define vvll vector<vll>
//vector<vector<int>> v(10, vector<int>(20,500)); 2d vector initialization. of 10 rows and 20 columns, with value 500.
#define pll pair<long long, long long>

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

ll tc, n, m, k;

int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // atcoder dp contest.


    cin>>n>>k;
    vll dp(k+1, 0);
    vll arr(n, 0);
    rep(i, 0, n) cin>>arr[i];

    // no more moves - losing state for any player
    dp[0] = 0;
    rep(state, 1, k+1) {
        // for a given state, there exist a move,
        // such that playing the move leads to a losing state for next player.
        // So it is a win for current player (since we play optimally).
        rep(j, 0, n) {
            if(state - arr[j] >= 0 && !dp[state-arr[j]])
                dp[state] = 1;
        }
    }

    if(dp[k] == 1) cout<<"First";
    else cout<<"Second";

    /*
     Winning state : there exists at least one move to transition to losing state
     Losing state: No moves exists, which will transition to losing state.


     */

    return 0;
}

/*

3 21
1 2 3
*/