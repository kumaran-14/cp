#include <random>
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
void mulMat(vector<vector<ll>>& m1, vector<vector<ll>>& m2, vector<vector<ld>>& res) {
    int r1 = m1.size();
    int c1 = m1[0].size();
    int r2 = m2.size();
    int c2 = m2[0].size();

    if (c1 != r2) {
        cout << "Invalid Input" << endl;
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

//void pm(vvll& mat) {
//  cout<<
//}v
ll tc, n, m, k;
const ll mxN = 2e5 + 7;
const ll mxM = 5e4 + 7;
ll inf = 1e13;
ll mod =  1e9 + 7;



int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
//  freopen("../output.txt", "w", stderr);
#endif
  ll minv = -10000, maxv = 10000 ;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> gen(minv, maxv);
  ll N = 5, M = 11;
  ll ming = 0, maxg = N*M +1;
  vvll G(N, vll(M, 0));
  ll val = maxg;
  rep(i, 0, M) {
    rep(j, 0, N) {
      G[j][i] = val--;
    }
  }
  rep(i, 0, N) G[i][0] *= 1000;



  rep(i, 0, N) db(G[i])
  vvll V(1, vll(N, 1));
  vector<vector<ld>> C(1, vector<ld>(M, 0)) ;
  ll iter = 100 ;
  while(iter--) {
    nl ;
    rep(i, 0, N) {
      V[0][i] = gen(rng);
    }
    db(V)
    mulMat(V, G, C);
//    db(C)
    rep(i, 0, M) C[0][i] /=1000;
    sort(all(C[0]), [&](ll a, ll b) {
      return abs(a) > abs(b);
    });
    db(C)
    ld numerator = (ld) abs(C[0][0]);
    ld denominator = (ld) abs(C[0][3]);
    ld mh = numerator/denominator ;
    db(mh)
  }
#ifndef ONLINE_JUDGE


  cerr << "\nExecution time: " << 1.0 * clock() / CLOCKS_PER_SEC
       << " seconds.\n";
#endif
  return 0;
}
