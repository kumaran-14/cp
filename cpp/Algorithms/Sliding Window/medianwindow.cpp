#include <bits/stdc++.h>
using namespace std;

// clang-format off
// trace template and ostream overloads
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while(!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(
    vector<string> __attribute__ ((unused)) args,
    __attribute__ ((unused)) int idx,
    __attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss; ss << (H);
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
template<typename C,
    typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
    typename std::enable_if<!std::is_same<C, std::string>::value>::type* = nullptr
>
std::ostream &operator<<(std::ostream &os, const C &container){
  bool first = true;
  std::stringstream ss;
  ss << '[';
  for(const auto &x : container){
    if (!first){
      ss << ", ";
    }
    first = false;
    ss << x;
  }
  ss << ']';
  return os << ss.str();
}

template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << '{' << p.first << ", " << p.second << '}'; return os;}

// stdout
#define db(x) cout << '>' << #x << ':' << x << endl;
// stderr
#ifndef ONLINE_JUDGE
#define tr(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define tr(...) ;
#endif

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define sz(x) ((int)(x).size())
#define nl cout << "\n"
#define all(v) v.begin(), v.end()
#define ret return

#define ll long long int
#define ld long double
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long, long long>

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// input overloads
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}

// clang-format on

ll tc, n, m, k;
const ll mxN = 2e5 + 7;
const ll mxM = 5e4 + 7;
ll inf = 1e13;

ll tr[mxN];
void upd(ll i, ll x) {
  i++;
  while(i < mxN) {
    tr[i] += x;
    i += -i&i;
  }
}

ll qry(ll i) {
  i++;
  ll sum = 0;
  while(i > 0) {
    sum += tr[i];
    i -= -i&i;
  }
  return sum;
}

map<ll, ll> comp, decomp;

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
//  freopen("../output.txt", "w", stderr);
#endif


  cin>>n>>k;
  vll v(n);
  cin>>v;

  rep(i, 0, n) {
    comp[v[i]] = 0;
  }
  ll x = 0;
  for(auto& el:comp) {
    el.s = x++;
    decomp[el.s] = el.f;
  }

  ll y = k/2 + (k&1);

  rep(i, 0, n) {
    upd(comp[v[i]], 1);
    if(i >= k) upd(comp[v[i-k]], -1);
    if(i >= k-1) {
      ll lo = 0; ll hi = n;
      while(hi-lo > 1) {
        ll mid = (lo+hi)/2;
        if(qry(mid) < y) lo = mid;
        else hi = mid;
      }
      if(qry(lo) < y) {
        cout<<decomp[lo+1];
      } else {
        cout<<decomp[lo];
      }
      cout<<" ";
    }
  }




#ifndef ONLINE_JUDGE
  cerr << "\nExecution time: " << 1.0 * clock() / CLOCKS_PER_SEC
       << " seconds.\n";
#endif
  return 0;
}
