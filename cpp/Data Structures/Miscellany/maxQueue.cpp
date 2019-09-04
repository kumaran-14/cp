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
// ll i, j;
// ll a, b;
// ll x, y;

// algorithm:
/*
  push first k elements
  for every window:
    print min of window
    pop last min el;
    push new el;
  print min of last window.
*/

class MaxQueue_1 {
private:
  ll n, k;
  deque<ll> q;
  vll arr;

  ll maxQ() {
    return q.front();
  }
  void enqueue(ll el) {
    while(!q.empty() && q.back() < el)
      q.pop_back();
    q.pb(el);
  }

  void dequeue(ll el) {
    if(!q.empty() && q.front() == el)
      q.pop_front();
  }

public:
  MaxQueue_1() {
    cin>>n>>k;
    arr.resize(n);
    ll i;
    foi(i, 0, n) cin>>arr[i];
  }

  void maxOfSubarrays() {
    ll i;
    foi(i, 0, k) {
      enqueue(arr[i]);
    }
    foi(i, k, n) {
      cout<<maxQ()<<" ";
      dequeue(arr[i-k]);
      enqueue(arr[i]);
    }
    cout<<maxQ()<<endl;
  }
};


class MaxQueue_2 {
private:
  ll n, k;
  stack<pll> s1, s2;
  vll arr;

  ll maxQ() {
    ll maxEl;
    if(s1.empty() || s2.empty())
      maxEl = s1.empty() ? s2.top().s : s1.top().s;
    else
      maxEl = max(s1.top().s, s2.top().s);
  }

  void addEl(ll el) {
    ll maxEl = s1.empty() ? el : max(el, s1.top().s);
    s1.p({el, maxEl});
  }

  void removeEl(ll el) {
    if(s2.empty()) {
      while(!s1.empty()) {
        ll topEl = s1.top().f;
        s1.pop();
        ll maxEl = s2.empty() ? topEl : max(topEl, s2.top().s);
        s2.p({topEl, maxEl});
      }
    }
    s2.pop();
  }

public:
  MaxQueue_2() {
    cin>>n>>k;
    arr.resize(n);
    ll i;
    foi(i, 0, n) cin>>arr[i];
  }

  void maxOfSubarrays() {
    ll i;
    foi(i, 0, k) {
      addEl(arr[i]);
    }
    foi(i, k, n) {
      cout<<maxQ()<<" ";
      removeEl(arr[i-k]);
      addEl(arr[i]);
    }
    cout<<maxQ()<<endl;
  }
};


int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    // MaxQueue_1 solution;
    // solution.maxOfSubarrays();
    MaxQueue_2 solution;
    solution.maxOfSubarrays();
  }
  return 0;
}

/*
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13
*/