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


int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    enum color {black, white};
    cin>>tc;
    while(tc--) {
        cin>>n>>m;
        vvll adj(n);
        vll color(n, white);
        vll currBlacks;
        vll bestBlacks;

        rep(i, 0, m) {
            ll u, v;
            cin>>u>>v;
            --u, --v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        auto canbeblack = [&](ll x) {
            for(auto v:adj[x]) {
                if(v == x || color[v] == black) return false;
            }
            return true;
        };

        function<void(ll)>backtrack = [&](ll x) {
            if(sz(currBlacks) > sz(bestBlacks))
                bestBlacks = currBlacks;
            if(x == n) return;
            ll maxBlacks = n-x;
            if(maxBlacks+sz(currBlacks) <= sz(bestBlacks)) return;
            rep(i, x, n) {
                if(canbeblack(i)) {
                    currBlacks.pb(i);
                    color[i] = black;
                    backtrack(i+1);
                    currBlacks.pop_back();
                    color[i] = white;
                }
            }
        };
        backtrack(0);
        cout<<sz(bestBlacks);
        newl;
        rep(i, 0, sz(bestBlacks))cout<<bestBlacks[i]+1<<endl[i==sz(bestBlacks)-1];
    }

    return 0;
}

