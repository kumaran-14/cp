// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl " \n"
#define newl cout<<"\n"
#define MAXN 100005
//#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long, long long>

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

ll tc, n, m, k;


//Also there is a formula for prefix xors 0 ^ 1 ^ .... ^ k:
int xorUpToK(int k) {
    switch (k % 4) {
        case 0: return k;
        case 1: return 1;
        case 2: return k + 1;
        case 3: return 0;
    }
}


int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    //https://codeforces.com/contest/424/problem/C
    cin>>n;
    vll arr(n, 0);
    rep(i, 0, n) cin>>arr[i];
    vll pre(n+1, 0);
    pre[0] = 0;
    rep(i, 1, n+1) {
        pre[i] = pre[i-1]^i;
    }
    ll ans = 0;
    rep(i, 1, n+1) {
        ans ^= arr[i-1];
        ll times = n/i;
        ll rem = n - i*times;
        if(times%2) {
            ans ^= (pre[i-1]^pre[rem]);
        } else {
            ans ^= (pre[rem]);
        }
    }
    cout<<ans;;


    return 0;
}

