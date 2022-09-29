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
#define pb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define sz(x) ((int)(x).size())
#define nl cout << "\n"
#define all(v) v.begin(), v.end()

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
const ll mxN = 5e4 + 7;
const ll mxM = 5e4 + 7;
const ll mod = 998244353;
const ll inf = 1e18;
const ll mxK = 500+7;



int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
//  freopen("../output.txt", "w", stderr);
#endif





  string str; cin>>str;
  n = sz(str);
  vll sop(n+1), scp(n+1);

  stack<ll> st;
  rep(i, 1, n+1) {
    if(str[i-1] == '(') st.push(i);
    else {
      if(!st.empty()) {
        sop[st.top()]  = 1;
        scp[i] = 1;
        st.pop();
      }
    }
  }

  vll prefsop(n+1), prefscp(n+1);
  rep(i, 1, n+1) {
    prefsop[i] = prefsop[i-1]+sop[i];A
        prefscp[i] = prefscp[i-1]+scp[i];
  }

//  db(prefscp);
//  db(prefsop);

  auto qry = [&](ll L, ll R) {
    ll ans = 2*(max(0LL, prefscp[R]-prefsop[L-1]));
    return ans;
  };

  cin>>tc;
  while(tc--) {
    ll L, R;
    cin>>L>>R;
    cout<<qry(L, R);
    nl;
  }


















#ifndef ONLINE_JUDGE
  cerr << "\nExecution time: " << 1.0 * clock() / CLOCKS_PER_SEC
       << " seconds.\n";
#endif
  return 0;
}
