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
#define newl cout<<"\n"
#define MAXN 100005
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18
// ¯\_(ツ)_/¯
#define l long int
#define d double
#define ll long long int
#define ull unsigned long long int
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

// exponential
int matrixChain(vll& chain, int start, int end) {
    if(end-start <= 1) return 0;
    int curr = INT_MAX;
    rep(j, start+1, end) {
        int ans = matrixChain(chain, start, j);
        ans += matrixChain(chain, j, end);
        ans += chain[start]*chain[j]*chain[end];
        curr = min(curr, ans);
    }
    return curr;
}

// O(n3) soln
int dp_matrixChain(vll& chain, int start, int end) {
    vvll dp(n, vll(n, 0));
    rep(i, 0, n) dp[i][i] = 0;
    rep(len, 2, n+1) {
        for(int i = 0; i + len <= n; ++i) {
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            for(int k = i+1; k < j; ++k) {
                dp[i][j] = min(dp[i][j],
                        dp[i][k] + chain[i]*chain[k]*chain[j] + dp[k][j]
                );
            }
            if(dp[i][j] == INT_MAX) dp[i][j] = 0;
        }
    }

//    rep(i, 0, n) rep(j, 0, n) cout<<dp[i][j]<<endl[j==n-1];

    return dp[start][end];
}

// eg: ((A(BC))D)
void printChainOrder(vvll& ip, vector<char> lex, int start, int end) {
    if(ip[start][end] == -1){
        cout<<lex[start];
        return;
    }
    cout<<"(";
    fun(ip, lex, start, ip[start][end]);
    fun(ip, lex, ip[start][end], end);
    cout<<")";
}

void matrixChainSolve() {
    cin>>n;
    vll chain(n, 0);
    rep(i, 0, n) cin>>chain[i];
    vvll dp(n, vll(n, 0));
    vvll ip(n, vll(n));

    if(n == 2) {
        cout<<"A"<<endl;
        continue;
    }

    if(n == 3) {
        cout<<"(AB)"<<endl;
        continue;
    }

    rep(len, 2, n+1) {
        for(int i = 0; i + len < n+1; i++) {
            int j = i + len -1;
            dp[i][j] = INT_MAX;
            int index = -1;
            for(int k = i+1; k < j; k++) {
                int val = dp[i][k] + chain[i]*chain[k]*chain[j] + dp[k][j];
                if(dp[i][j] > val) {
                    dp[i][j] = val;
                    index = k;
                }
            }

            if(dp[i][j] == INT_MAX) {
                dp[i][j] = 0;
                index = -1;
            }
            ip[i][j] = index;
        }
    }

    vector<char> lex;
    rep(i, 0, 26) lex.pb(('A'+i));
    printChainOrder(ip, lex, 0, n-1);
}

int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cin>>tc;
    while(tc--) {
        cin>>n;
        vll chain(n);
        rep(i, 0, n) cin>>chain[i];
//        ll ans = matrixChain(chain, 0, n-1);
//        if(n == 2) {
//            cout<<chain[0]*chain[1]<<endl;
//        } else {
//            cout<<ans<<endl;
//        }


    }
    return 0;
}

/*

2
5
40 20 30 10 30
2
3 3
 */