/*
This problem was asked by Alibaba.

Given an EVEN number (greater than 2), return two prime numbers whose sum will be equal to the given number.

A solution will always exist. See Goldbach’s conjecture.

Example:

Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, then

[a, b] < [c, d]
If a < c OR a==c AND b < d.
 */




// kumaran_14

// #include <boost/multiprecision/cpp_int.hpp> 
// using boost::multiprecision::cpp_int;  
#include <bits/stdc++.h>
using namespace std;
// ¯\_(ツ)_/¯ 
#define f first
// #define s second
#define p push
#define mp make_pair
#define pb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl "\n"
#define MAXN 100005
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18
// ¯\_(ツ)_/¯ 
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define vll vector<long long>
#define pll pair<long long, long long>
#define vvll vector<vll>
#define vvdd vector<vdd>
//vector<vector<int>> v(10, vector<int>(20,500)); 10 rows, 20 cols, val = 500;

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);


ll tc, n, m, k;


//minimum prime factor.
vll mpf(MAXN, 0);
vll pr;

//primenumbers less than n;
void eratosthenes(ll n) {
  rep(i, 2, n+1) {
    if(mpf[i] == 0) {
      mpf[i] = i;
      pr.pb(i);
    }
    for(int j = 0; j < sz(pr) && pr[j] <= mpf[i] && i*pr[j] <= n; ++j) {
      mpf[i*pr[j]] = pr[j];
    }
  }
}


int main() {
  fast_io();
  #ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif
  //begin code.

  eratosthenes(100000);
  unordered_map<ll, bool> hm;
  for(auto x:pr) hm[x] = true;

  cin>>tc;
  while(tc--) {
  	cin>>n;
  	ll ind = -1;
  	rep(i, 0, sz(pr)+1) {
  		if(hm[pr[i]] && hm[n-pr[i]]) {
  			ind = pr[i];
  			break;
  		}
  	}
  	if(ind != -1) {
  		cout<<ind<<" "<<n-ind<<endl;
  	} else {
  		cout<<-1<<endl;
  	}
  	// if(hm[3] && hm[17]) cout<<"lol yes";
  	// cout<<ind;
  	// debug("jui");
  }

  //end code.
  return 0;
}



/**
	https://codeforces.com/contest/584/problem/D
	https://practice.geeksforgeeks.org/problems/sum-of-prime/0
	
	Strong conjecture (unproven):  every even integer greater than 2 is the sum of two prime numbers.
	Weak conjecture: every odd integer greater than 5 is the sum of three odd primes. 
 */
