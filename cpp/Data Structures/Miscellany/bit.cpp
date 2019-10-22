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

//print binary representation
string binary(unsigned n) 
{ 
  unsigned i; 
  string str = "";
  for (i = 1 << 31; i > 0; i = i>>1) 
    (n & i)? str[i]+= '1': str[i] += '0'; 
  return str;
} 

unsigned rightmostSetBit(ll n) {
  //position
  return log2((n)&(-n))+1;
}

ll rightmostDifferentBit(ll n, ll m) {
  return rightmostSetBit(n^m);
}

void toggleBitsInRange(ll left, ll right) {
  right--;
  ll bitmask = ((1<<left)-1)^((1<<right)-1);
  ll z = (n^bitmask);
  // print toggled bits
  binary(z);

}

ll binary_to_gray(ll n) {
  return (n)^(n>>1);
}

ll gray_to_binary(ll n)
{
  ll ans=0;
  for(;n;n=n>>1)
    ans^=n;
  return ans;
}


//count set bits
ll csb(ll n) {
  ll ans = 0;
  ll i = 1;
  while(n >= (1<<i)) {
    if(n&(1<<i)) ans++;
    i++;
  }
  return ans;
}

bool isKthBitSet(ll n, ll k) {
  return(n&(1<<k));
}


int main()
{
  fast_io();
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  cin>>tc;
  while(tc--) {
    cin>>n;
    ll m = log2(n)+1;
    ll i;
    bool sparse = true;
    foi(i, 0, m) {
      if(isKthBitSet(n, i) && (isKthBitSet(n, i+1)))
      {
        sparse = false;
        break;
      }
    }
    cout<<sparse<<endl;
  }
  return 0;
}
