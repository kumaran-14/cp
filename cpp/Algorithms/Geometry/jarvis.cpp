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

struct Point {
    int x, y;
    Point(int a, int b): x(a), y(b) {}
};


// 0 for collinear
// 1 for clockwise
// -1 for anticlockwise
int orientation(Point a, Point b, Point c) {
    int res = (b.y - a.y)*(c.x-b.x) - (b.x - a.x)*(c.y - b.y);
    if(res == 0) return 0;
    if(res > 0) return 1;
    if(res < 0) return -1;
}

void jarvis(vector<Point>& parr, vector<Point>& hull) {
    if(n < 3) return;

    // left most point
    int j = 0;
    rep(i, 1, sz(parr)) {
        if(parr[i].x < parr[j].x) j = i;
    }

    int curr = j, next;
    do {
        hull.pb(parr[curr]);
        // point 'next',  such that all points 'x' is counterclockwise for (curr, x, next);
        next = (curr+1)%n;
        rep(i, 0, sz(parr)) {
            if(orientation(parr[curr], parr[i], parr[next]) == -1) next = i;
        }
        curr = next;
    } while(curr != j);

}

bool customcompare(Point& a, Point& b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
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
        vector<Point> parr;
        map<pair<int, int>, bool> hm;
        rep(i, 0, n) {
            int u, v;
            cin>>u>>v;
            auto newpoint = Point(u, v);
            if(hm.find(mp(u, v)) == hm.end()) {
                parr.pb(newpoint);
                auto pr = mp(u, v);
                hm[pr] = true;
            }
        }
        vector<Point> hull;
        jarvis(parr, hull);
        if(sz(parr) < 3) {
            cout<<"-1";
        } else {
            sort(all(hull), customcompare);
            rep(i, 0, sz(hull)) {
                cout<<hull[i].x<<" "<<hull[i].y;
                newl;
                if(i != sz(hull)-1) {
                    cout<<", ";
                }
            }
        }
        newl;
    }

    return 0;
}
