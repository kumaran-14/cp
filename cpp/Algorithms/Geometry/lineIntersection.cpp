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
    // 21(y)32(x) - 21(x)32(y)
    int res = (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y);
    if(res == 0) return 0;
    else if(res > 0) return 1;
    else return -1;
}

// checks if p lies between a and b, given a, b, p are collinear
bool inLine(Point a, Point b, Point p1) {
    if(p1.x >= min(a.x, b.x) && p1.x <= max(a.x, b.x) && p1.y >= min(a.y, b.y) && p1.y <= max(a.y, b.y))
        return true;
    return false;
}


bool intersect(Point p1, Point p2, Point q1, Point q2) {
    int po1 = orientation(p1, p2, q1);
    int po2 = orientation(p1, p2, q2);

    int qo1 = orientation(q1, q2, p1);
    int qo2 = orientation(q1, q2, p2);

    if(po1 != po2 && qo1 != qo2) {
        return true;
    }

    if(po1 == 0 && inLine(p1, p2, q1)) return true;
    if(po2 == 0 && inLine(p1, p2, q2)) return true;
    if(qo1 == 0 && inLine(q1, q2, p1)) return true;
    if(qo2 == 0 && inLine(q1, q2, p2)) return true;
    return false;
}

bool pointLiesInPolygon(vector<Point>& polygon, Point& target) {
    Point extreme = Point(100000, target.y);
    int intersectionCount = 0;
    rep(i, 0, sz(polygon)-1) {
        if(intersect(polygon[i], polygon[i+1], target, extreme)) {
            // if collinear, check point lies on this polygon side
            if(orientation(polygon[i], polygon[i+1], target) == 0)
                return inLine(polygon[i], polygon[i+1], target);

            intersectionCount++;
        }
    }
    // odd -> true, lies inside
    //even -> false;
    return intersectionCount&1;
}


int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    //  p1, p2 line segment -> 1
    //  q1, q2 line segment -> 2
    // intersect(p1, p2, q2, q2);


    return 0;
}
