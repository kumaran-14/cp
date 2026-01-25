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
ll tc, n, m, k;
const ll mxN = 2e5 + 7;
const ll mxM = 5e4 + 7;
ll inf = 1e13;
ll mod =  1e9 + 7;



/*

 ###############################################################

  SEE README.md for brushing up leetcode from scratch.

###############################################################
 */



struct node {
  int elm;
  // 3
//  bool operator<(const node& other) {
//    return elm < other.elm;
//  }

  //4
//  bool operator()(const node& a, const node& b) {
//    return a.elm < b.elm;
//  }

  // priority q related function
  node(): elm(-1){} // default constructor
  node(int v):elm(v){}
  bool operator()(const node& a, const node& b) {
    return a.elm < b.elm;
  }
  // pq4, custom operator: note the const in the function
  bool operator<(const node& other ) const {
    return elm < other.elm;
  }
};
bool compare(const node& a, const node& b) {
  return a.elm < b.elm;
}

struct Comp {
  bool operator()(const node& a, const node& b) {
    return a.elm < b.elm;
  }
};

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
//  freopen("../output.txt", "w", stderr);
#endif

  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  cout<<INT_MAX<<endl;
  cout<<INT_MIN<<endl;

  n = 10;

  vll arr(n) ;
  for(auto& el:arr) {
    el = std::rand()%100+1;
  }
  db(arr);
  int i = std::distance(arr.begin(), max_element(all(arr)));
  int j = max_element(all(arr)) - arr.begin();
  db(i);
  db(j);
  nl;

  db(max({10, 20, 2, 3}));

  ll sum = 0;
  sum = accumulate(arr.begin(), arr.end(), 0);
  db(sum)
  vll newarr(n);
  iota(newarr.begin(), newarr.end(), 1);
  db(newarr);


  // types of vector initializations
  vll a1(3, 334);
  vll a2{4, 5, 6};
  vector<int> a3 = {1, 2, 3};

  db(a1)
  db(a2)
  db(a3)


  node a{98};
  db(a.elm)

  vector<node> myarr(n);


  for(auto& it: myarr) {
    it.elm = std::rand()%100+1;
  }
  for(auto it: myarr) {
    cout<<it.elm<<" ";
  }
  nl;

  // 1. lambda function
//  sort(all(myarr), [&](const node& a1, const node& b1){
//    return a1.elm < b1.elm;
//  });

  // 1.1: with instead of auto
//  std::function<bool(const node& a1, const node& b1)> sortFn = [&](const node& a1, const node& b1) {
//    return a1.elm < b1.elm;
//  };
//  sort(all(myarr), sortFn);

  // 2. with custom fucntion, note this does not work in leetcode style, where only class exists
//  sort(all(myarr), compare);

  // 3. operator overload
//  sort(all(myarr));

  // 4. () operator
//  sort(all(myarr), Comp());
  for(auto it: myarr) {
    cout<<it.elm<<" ";
  }
  nl;

  // 1. max heap
  priority_queue<ll> pq1;
  pq1.push(3);
  pq1.push(4);
  pq1.push(5);
  while(!pq1.empty())  {
    db(pq1.top());
    pq1.pop();
  }

// 2. min heap
  priority_queue<ll, vll, greater<>> pq2;
  pq2.push(3);
  pq2.push(4);
  pq2.push(5);
  while(!pq2.empty())  {
    db(pq2.top());
    pq2.pop();
  }

  // 3. custom lambda function in pq for custom node
  auto fn = [&](const node& a1, const node& b1) {
    return a1.elm < b1.elm;
  };
  priority_queue<node, vector<node>, decltype(fn)> pq3(fn);
  pq3.push(node(30));
  pq3.push(node(40));
  pq3.push(node(50));

  while(!pq3.empty())  {
    db(pq3.top().elm);
    pq3.pop();
  }

  // 3_1: using outside function, not the asterisk below in decltype

  priority_queue<node, vector<node>, decltype(compare)*> pq3_1(compare);
  pq3_1.push(node(30));
  pq3_1.push(node(40));
  pq3_1.push(node(50));

  while(!pq3_1.empty())  {
    db(pq3_1.top().elm);
    pq3_1.pop();
  }


//   4. custom node, without lambda, but simple function
  priority_queue<node> pq4;
  pq4.push(node(330));
  pq4.push(node(440));
  pq4.push(node(550));

  while(!pq4.empty())  {
    db(pq4.top().elm);
    pq4.pop();
  }


  // coordinate compression
  vll varr{9, 9, 1, 1, 5, 6, 8, 4, 4, 3, 3, 3, 3};
  db(varr)
  // step 1: sort
  sort(all(varr));
  db(varr)
  // gives the first duplicate item's pointer
  auto it = unique(all(varr));
  db(varr)
  int jj = distance(varr.begin(), it);
  db(*it);
  db(jj);
  // step 2: resize
  varr.resize(jj);
  db(varr)


  //or step2: erase

  vll dup{9, 9, 1, 1, 5, 6, 8, 4, 4, 3, 3, 3, 3};
  sort(all(dup));
  dup.erase(unique(all(dup)), dup.end());
  db(dup);

  // See CoordinateCompression.h file for two ways of compress/decompress

  // see bit manip











#ifndef ONLINE_JUDGE
  cerr << "\nExecution time: " << 1.0 * clock() / CLOCKS_PER_SEC
       << " seconds.\n";
#endif
  return 0;
}
