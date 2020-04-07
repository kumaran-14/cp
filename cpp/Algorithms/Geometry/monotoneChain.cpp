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

// required functions/data structure
struct Point {
    int x, y;
    Point(int a, int b): x(a), y(b) {}
    Point() {};
} p0;

// 0 for collinear
// 1 for clockwise
// -1 for anticlockwise
int orientation(Point& a, Point& b, Point& c) {
    return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x);
}
bool customcompare(Point& a, Point& b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}


// MONOTONE CHAIN ALGORITHM

vector<Point> mchain(vector<Point>& points) {
    // Andrew's monotone chain method
    int n = points.size();
    vector<Point> ans;
    sort(points.begin(), points.end(), customcompare);
    // left to right
    for (int i = 0; i < n; ++i) {
        while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0)
            ans.pop_back();
        ans.pb(points[i]);
    }
    // if all points along a line, ans.size() is n after left to right procedure
    if (ans.size() == n) return ans;
    // right to left
    for (int i = n-2; i >= 0; --i) {
        while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0)
            ans.pop_back();
        ans.pb(points[i]);
    }
    ans.pop_back();
    return ans;
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
        vector<Point> parr(n);
        rep(i,0,n) {
            int u, v;
            cin>>u>>v;
            parr[i] = Point(u,v);
        }
        debug(sz(parr));
        auto hull = mchain(parr);
        for(auto q:hull) cout<<"("<<q.x<<", "<<q.y<<")"<<endl;
    }

    return 0;
}

/*

1
18
1 2
2 1
3 0
4 0
5 0
6 1
7 2
7 3
7 4
6 5
5 5
4 5
3 5
2 5
1 4
0 3
1 3
4 2
 */