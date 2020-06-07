// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define endl " \n"
#define newl cout<<"\n"
#define MAXN 100005
//#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000             // 10^9
#define INFLL 1000000000000000000ll //10^18
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long, long long>

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

ll tc, n, m, k;


int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // UVA 'Assemble'
    cin>>tc;
    while(tc--) {
        ll useprice;
        cin>>n>>useprice;
        unordered_map<string, vector<pll>> parts;
        rep(i, 0, n) {
            string s1, s2;
            ll u, v;
            cin>>s1>>s2>>u>>v;
            // price, quality.
            parts[s1].pb({u, v});
        }

        auto test = [&](ll testq) {
            ll totcost = 0;
            for(auto it:parts) {
                //it is one part;
                ll onecost = 1000000000;
                for(auto choice:it.s) {
                    if(choice.s >= testq) {
                        onecost = min(onecost, choice.f);
                    }
                }
                totcost += onecost;
                if(totcost>useprice) break;
            }
            return totcost <=  useprice;
        };

        ll startq = 0, endq = 1000000001;
        ll bestq = 0;
        while(endq-startq > 1) {
            ll midq = (startq+endq)/2;
            if(test(midq)) {
                startq = midq;
                bestq = max(bestq, midq);
            } else {
                endq = midq;
            }
        }
        cout<<bestq;
        newl;
    }


    return 0;
}

