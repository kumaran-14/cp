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

    cin>>tc;
    while(tc--) {
        vll visx(8, 0), visy(8, 0);
        vvll vis(8, vll(8, 0));
        ll xi, yi;
        cin>>xi>>yi; --xi; --yi;
        visx[xi] = 1;
        visy[yi] = 1;
        vis[xi][yi] = 1;

        vvll ans;
        ll z = 0;


        function<bool(ll, ll)> canbequeen = [&](ll x, ll y) {
            if(visx[x] || visy[y]) return false;
            else {
                bool pos = false;
                vll dx = {-1, -1, 1, 1};
                vll dy = {-1, 1, -1, 1};
                rep(count, 1, 8) {
                    rep(i, 0, 4) {
                        pll u = {x+dx[i]*count, y+dy[i]*count};
                        if(u.f < 0 || u.f >= 8 || u.s < 0 || u.s >= 8) continue;
                        pos |= (vis[u.f][u.s]);
                    }
                }
                return !pos;
            }
        };

        function<void(ll)> dfs = [&](ll row) {
            if(row == 8) {
                ans.pb({});
                rep(j, 0, 8)rep(i, 0, 8) if (vis[i][j]) {
                            ans[z].pb(i+1);
                            continue;
                        }
                z++;
                return;
            }
            if(visx[row]) {
                dfs(row+1);
            } else {
                rep(col, 0, 8) {
                    if(canbequeen(row, col)) {
                        visx[row] = 1;
                        visy[col] = 1;
                        vis[row][col] = 1;

                        dfs(row+1);

                        vis[row][col] = 0;
                        visx[row] = 0;
                        visy[col] = 0;
                    }
                }
            }

        };
        dfs(0);

        sort(all(ans));

        cout<<"SOLN       COLUMN";
        newl;
        cout<<" #      1 2 3 4 5 6 7 8";
        newl;
        newl;
        rep(i, 0, sz(ans)) {
            if(i+1 < 10) cout<<" ";
            cout<<i+1<<"      ";
            rep(j, 0, sz(ans[i])) cout<<ans[i][j]<<endl[j==sz(ans[i])-1];
        }
        if(tc)
            newl;
    }

    return 0;
}

