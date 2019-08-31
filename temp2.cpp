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

int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    cin>>n>>m;
    vector<vector<pll>> adjmat(n, vector<pll>(m, {0, INFLL}));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    pll source, target;
    foi(i, 0, n) {
      foi(j, 0, m) {
        cin>>adjmat[i][j].f;
        if(adjmat[i][j].f == 2) {
          source = {i, j};
        } else if(adjmat[i][j].f == 3) {
          target = {i, j};
        }
      }
    }
    queue<pair<pll, ll>> q;
    pair<pll, ll> move, cmove;
    pll pos, cpos;
    // vertical
    foi(i, 0, n) {
      if(i != source.f && adjmat[i][source.s].f != 0) {
        pos = {i, source.s};
        move = {pos, abs(source.f - i)};
        q.p(move);

        vis[pos.f][pos.s] = true;
      
      }
    }
    //horizontal
    foi(j, 0, m) {
      if(j != source.s && adjmat[source.f][j].f != 0) {
        pos = {source.f, j};
        move = {pos, 0};
        q.p(move);
        vis[pos.f][pos.s] = true;
      }
    }
    while(!q.empty()) {
      cmove = q.front(); q.pop();
      cpos = cmove.f;
      //pseudo code
      /* for (all possible moves)
            if(valid move) {
                if(not visitied) {
                    push in queue;
                } else if (can be relaxed) {
                    relax;
                    push in queue;
                }
            }
      */
      //vertical
      foi(i, 0, n) {
        if(adjmat[i][cpos.s].f != 0) {
          if(!vis[i][cpos.s]) {
            q.p({{i, cpos.s}, max(cmove.s, abs(i-cpos.f))});
            vis[i][cpos.s] = true;
          } else if(adjmat[i][cpos.s].s > max(cmove.s, i-cpos.f)) {
            adjmat[i][cpos.s].s = max(cmove.s, abs(i-cpos.f));
            q.p({{i, cpos.s}, max(cmove.s, abs(i-cpos.f))});
          }
        }
      }
      // horizontal
      foi(j, 0, m) {
        //peudo code
        if(adjmat[cpos.f][j].f != 0) {
          if(!vis[cpos.f][j]) {
            q.p({{cpos.f, j},cmove.s});
            vis[cpos.f][j] = true;
          } else if(adjmat[cpos.f][j].s > cmove.s) {
            adjmat[cpos.f][j].s = cmove.s;
            q.p({{cpos.f, j}, cmove.s});
          }
        }

      }
    }
    cout<<adjmat[target.f][target.s].s<<endl;
    foi(i, 0, n) {
      foi(j, 0, m) {
        if(adjmat[i][j].s == INFLL) cout<<"X"<<endl[j==m-1];
        else
          cout<<adjmat[i][j].s<<endl[j==m-1];
      }
    }
  }
  return 0;
}
