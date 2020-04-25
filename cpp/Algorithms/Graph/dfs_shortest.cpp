// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;
#include <bits/stdc++.h>
using namespace std;
// ¯\_(ツ)_/¯
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
#define pll pair<long long, long long>

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

ll tc, n, m, k;


// knightwalk on chessboard.
vll dx = {-2, -1, 1, 2, 2, 1, -1, -2};
vll dy = {-1, -2, -2, -1, 1, 2, 2, 1};

bool check(pll& v) {
    return (v.f >= 0 && v.f < n && v.s >= 0 && v.s < m);
}

void dfs(pll u, vvll& adjgraph, pll& dest) {
    rep(i, 0, 8) {
        pll v = {u.f+dx[i], u.s+dy[i]};
        // not maintaining visited,                                      pruning works only because all paths takes 1 cost
        if(check(v) && adjgraph[v.f][v.s] > adjgraph[u.f][u.s] + 1 && adjgraph[dest.f][dest.s] > adjgraph[u.f][u.s] + 1 ) {
            adjgraph[v.f][v.s] = adjgraph[u.f][u.s] + 1;
            dfs(v, adjgraph, dest);
        }
    }
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
        m = n;
        ll x, y, tx, ty;
        cin>>x>>y>>tx>>ty;
        pll start = {--x, --y};
        pll dest = {--tx, --ty};

        vvll adjgraph(n, vll(m, INFI));
        adjgraph[start.f][start.s] = 0;
        ll ans = 0;
        if(start.f == dest.f && start.s == dest.s) {
            ans = 0;
        } else {
            dfs(start, adjgraph, dest);
        }
        ans = adjgraph[dest.f][dest.s];

        cout<<ans;
        newl;

    }

    return 0;
}

/*

2
6
4 5
1 1
20
5 7
15 20
*/