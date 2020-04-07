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

// GRAHAM SCAN required functions/data structure
struct Point {
    int x, y;
    Point(int a, int b): x(a), y(b) {}
    Point() {};
} p0;


// 0 for collinear
// 1 for clockwise
// -1 for anticlockwise
int orientation(Point a, Point b, Point c) {
    int res = (b.y - a.y)*(c.x-b.x) - (b.x - a.x)*(c.y - b.y);
    if(res == 0) return 0;
    if(res > 0) return 1;
    if(res < 0) return -1;
}

bool customcompare(Point& a, Point& b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int euclidDist(Point p1, Point p2) {
    //(x2-x1)^2 + (y2-y1)^2
    return (p2.x-p1.x)*(p2.x-p1.x) +
           (p2.y-p1.y)*(p2.y-p1.y);
}

int qsortCompare(const void* v1, const void* v2) {
    Point* p1 = (Point*)v1;
    Point* p2 = (Point*)v2;

    int o = orientation(p0, *p1, *p2);
    if(o == 0) {
        return (euclidDist(p0, *p1) <= euclidDist(p0, *p2) ? -1 : 1);
    }
    // qsort() expects the comparison function to return:
    //    a negative result if val1 < val2
    //    0 if val1 == val2
    //    a positive result if val1 > val2
    return (o == -1) ? -1: 1;
}

void pointSwap(Point& p1, Point& p2) {
    Point temp = p2;
    p2 = p1;
    p1 = temp;
}

Point beforeTop(stack<Point>& S)
{
    Point p1 = S.top();
    S.pop();
    Point res = S.top();
    S.push(p1);
    return res;
}

// GRAHAM SCAN required end.

// GRAHAM SCAN ALGORITHM

void grahamScan(Point parr[], int n) {
    // 1.find left-bottommost point
    int y_minIndex = 0;
    int y_min = parr[y_minIndex].y;
    rep(i, 1, n) {
        int y_curr = parr[i].y;
        if(y_curr < y_min || (y_curr == y_min && parr[i].x < parr[y_minIndex].x)) {
            y_min = y_curr;
            y_minIndex = i;
        }
    }

    // 2.make that point first;
    swap(parr[0], parr[y_minIndex]);

    /*
       3.Sort n-1 points with respect to the first point.
         A point p1 comes before p2 in sorted output if p2
         has larger polar angle (in counterclockwise
         direction) than p1, or
         p1 has least distance from 'first point' than p2;
     */
    p0 = parr[0];
    qsort(&parr[1], n-1, sizeof(Point), qsortCompare);

    /*
     4. If two or more points have same angle, keep the farthest only.
      (farthest is towards end according to qsortcompare)
      We are transforming array inplace;
     */
    int m = 1;

    rep(i, 1, n) {

        while(i < n-1 && orientation(p0, parr[i], parr[i+1]) == 0)
            i++;

        parr[m++] = parr[i];
    }

    // m is the size of modified array

    if(m < 3) return;

    stack<Point> S;
    S.p(parr[0]); S.p(parr[1]); S.p(parr[2]);


    // 5. Keep removing top while the angle formed by
    // points next-to-top, top, and points[i] makes
    // a non-left turn (pop, if clockwise)
    rep(i, 3, m) {
        while(orientation(beforeTop(S), S.top(), parr[i]) != -1)
            S.pop();
        S.push(parr[i]);
    }

    // Stack has the convex hull in anticlockwise manner (bottom to top)

    // do whatever needed from stack
    while (!S.empty())
    {
        Point p1 = S.top();
        cout << "(" << p1.x << ", " << p1.y <<")" << endl;
        S.pop();
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
        Point parr[n];
        rep(i,0,n) {
            int u, v;
            cin>>u>>v;
            parr[i] = Point(u,v);
        }
        grahamScan(parr, n);
    }

    return 0;
}


/*

1
8
0 3 1 1 2 2 4 4 0 0 1 2 3 1 3 3

 */