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

// https://leetcode.com/articles/next-permutation/
// works for string arr, num arr.
bool next_perm(vll& arr) {
    ll m = sz(arr);
    int i = m-2;
    while(i >= 0 && arr[i+1] <= arr[i]) i--;
    if(i >= 0) {
        int j = m-1;
        while(j >= 0 && arr[j] <= arr[i]) j--;
        swap(arr[i], arr[j]);
        reverse(arr.begin() + i+1, arr.end());
        return true;
    } else return false;
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
        string str;
        cin>>str;
        n = sz(str);
        vll arr(n, 0);
        rep(i, 0, sz(arr)) {
            arr[i] = (str[i]);
        }
        bool val = false;
        // specific to a problem - find next even perm
        val = next_perm(arr);
        while(val && (arr[n-1]-48)%2 == 1) val = next_perm(arr);
        string ans = "";
        for(auto x:arr) ans += (x);
        if(!val) cout<<-1;
        else cout<<ans;
        newl;
    }


    return 0;
}

/*
2
76632810777910
111
*/