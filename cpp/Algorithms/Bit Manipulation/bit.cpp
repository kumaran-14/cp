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

/*
 Answer these questions first, solution given below
 1. print number in binary
 2. get left most set bit
 3. get right most set bit
 4. make bit 0 at index i
 5. make bit 1 at index i
 6. get bit at index i
 7. flip bit at index i
 8. count set bits - 2 ways
 */

//print binary representation
void binary(unsigned n) 
{ 
  unsigned i; 
  string str = "";
  for (i = 1 << 31; i > 0; i = i>>1) {
    if((n&i)) str += '1';
    else str += '0'; 
  }
  cout<<str<<endl;
}

// most significant set bit from left
int msb(unsigned n) {
  return (int)log2(n);
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
  ll i = 0;
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
  rep(i, 1, 1024) cout<<msb(i)<<endl;
  return 0;
}

/*
https://raw.githubusercontent.com/mostafa-saad/ArabicCompetitiveProgramming/master/15%20C%2B%2B%20Programming%204%20Competitions/41%20C%2B%2B%20Programming%204%20Competitions%20-%20Bits.cpp


Generally:	X%(2^n)  = X & (2^n -1)
 so x%16 = x & 15

Even test

if(n%2 == 1)		-> Fails of n is negative
if( (n&1) == 1)	-> Works always


void printNumber(int n, int len)
{
	if(!len)
		return ;

	printNumber(n>>1, len-1);	// remove last bit
	cout<<(n&1);						// print last bit
}


// Let's count bits

int countNumBits1(int mask) {	// O(bits Length)
	int ret = 0;	//1101001 -> 110100 -> 11010 -> 1101 -> 110 -> 11 -> 1 -> 0
	while (mask) {
		if(mask&1)
			ret++;
		mask >>= 1;
	}
	return ret;
}

// Get bit
int getBit(int num, int idx) {
  return ((num >> idx) & 1) == 1;		// 110100, idx = 4  -->  110 & 1 = 0
}

 make bit as 1, aka set bit
int setBit1(int num, int idx) {
	return num | (1<<idx);
}

Note: ~ is not same as minus (-)
 make bit as 0 aka unset set bit
int setBit0(int num, int idx) {
	return num & ~(1<<idx);				// 110100, idx = 3  -->  110100 & ~000100 = 110100 & 111011
}

int flipBit(int num, int idx) {
	return num ^ (1<<idx);
}


X-1 is very important!

X 	= 840 	= 01101001000
X-1 = 839 	= 01101000111		What happened? First bit 16=(2^4) is removed, and 15=2^4-1 is added.

X & (X-1) 	= 01101000000		first bit from right removed

X & ~(X-1) 	= 01101001000 & 10010111000 = 00000001000	value of 1<<SmaintestBitIdx



int countNumBits2(int mask) {	//	O(bits Count)		__builtin_popcount
    int ret = 0;
    while (mask) 	{
        mask &= (mask-1);
        ++ret;	// Simply remove the last bit and so on
    }
    return ret;
}





*/