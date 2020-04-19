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
//#define l long int
//#define d double
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vll>
#define vvld vector<vector<ld>>

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


void heapify(vll& arr, ll treeidx, ll heapsize) {
    ll maxidx = treeidx;
    ll leftidx = maxidx*2 + 1;
    ll rightidx = maxidx*2 + 2;

    if(leftidx < heapsize && arr[leftidx] > arr[maxidx])
        maxidx = leftidx;

    if(rightidx < heapsize && arr[rightidx] > arr[maxidx])
        maxidx = rightidx;

    if(maxidx != treeidx) {
        swap(arr[maxidx], arr[treeidx]);
        heapify(arr, maxidx, heapsize);
    }
}

void buildheap(vll& arr) {
    ll n = sz(arr);
    ll firstNonLeafIndex = (n/2) - 1;
    rep(i, firstNonLeafIndex+1, 0)
        heapify(arr, i, sz(arr));
}


void heapsort(vll& arr) {
    rep(i, 0, sz(arr)) {
        swap(arr[0], arr[sz(arr)-1-i]);
        heapify(arr, 0, sz(arr)-1-i);
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
        vll arr(n, 0);
        rep(i, 0, n) cin>>arr[i];
        buildheap(arr);

        for(auto x: arr) cout<<x<< " ";
        heapsort(arr);
        newl;
        for(auto x: arr) cout<<x<< " ";

    }


    return 0;
}

/*
2
4
0 1 0 1
5
0 0 1 0 0
*/