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
#define vvld vector<vector<ld>>

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


// stackoverflow code for typename info, including compile time info, for c++ 11/14
// begin
        #include <cstddef>
        #include <stdexcept>
        #include <cstring>
        #include <ostream>

        #ifndef _MSC_VER
        #  if __cplusplus < 201103
        #    define CONSTEXPR11_TN
        #    define CONSTEXPR14_TN
        #    define NOEXCEPT_TN
        #  elif __cplusplus < 201402
        #    define CONSTEXPR11_TN constexpr
        #    define CONSTEXPR14_TN
        #    define NOEXCEPT_TN noexcept
        #  else
        #    define CONSTEXPR11_TN constexpr
        #    define CONSTEXPR14_TN constexpr
        #    define NOEXCEPT_TN noexcept
        #  endif
        #else  // _MSC_VER
        #  if _MSC_VER < 1900
        #    define CONSTEXPR11_TN
        #    define CONSTEXPR14_TN
        #    define NOEXCEPT_TN
        #  elif _MSC_VER < 2000
        #    define CONSTEXPR11_TN constexpr
        #    define CONSTEXPR14_TN
        #    define NOEXCEPT_TN noexcept
        #  else
        #    define CONSTEXPR11_TN constexpr
        #    define CONSTEXPR14_TN constexpr
        #    define NOEXCEPT_TN noexcept
        #  endif
        #endif  // _MSC_VER

        class static_string
        {
            const char* const p_;
            const std::size_t sz_;

        public:
            typedef const char* const_iterator;

            template <std::size_t N>
            CONSTEXPR11_TN static_string(const char(&a)[N]) NOEXCEPT_TN
                    : p_(a)
                    , sz_(N-1)
            {}

            CONSTEXPR11_TN static_string(const char* p, std::size_t N) NOEXCEPT_TN
                    : p_(p)
                    , sz_(N)
            {}

            CONSTEXPR11_TN const char* data() const NOEXCEPT_TN {return p_;}
            CONSTEXPR11_TN std::size_t size() const NOEXCEPT_TN {return sz_;}

            CONSTEXPR11_TN const_iterator begin() const NOEXCEPT_TN {return p_;}
            CONSTEXPR11_TN const_iterator end()   const NOEXCEPT_TN {return p_ + sz_;}

            CONSTEXPR11_TN char operator[](std::size_t n) const
            {
                return n < sz_ ? p_[n] : throw std::out_of_range("static_string");
            }
        };

        inline
        std::ostream&
        operator<<(std::ostream& os, static_string const& s)
        {
            return os.write(s.data(), s.size());
        }

        template <class T>
        CONSTEXPR14_TN
        static_string
        type_name()
        {
        #ifdef __clang__
            static_string p = __PRETTY_FUNCTION__;
            return static_string(p.data() + 31, p.size() - 31 - 1);
        #elif defined(__GNUC__)
            static_string p = __PRETTY_FUNCTION__;
        #  if __cplusplus < 201402
            return static_string(p.data() + 36, p.size() - 36 - 1);
        #  else
            return static_string(p.data() + 46, p.size() - 46 - 1);
        #  endif
        #elif defined(_MSC_VER)
            static_string p = __FUNCSIG__;
            return static_string(p.data() + 38, p.size() - 38 - 7);
        #endif
        }
// end

// for testing purposes
namespace funuser::superuser {
    struct batman {
        float arr[100];
    };

}
using namespace funuser::superuser;


int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    auto bruce = batman();
    vector<ll> ahah;
    auto ci = make_tuple(ahah, 04.0, "hola", 'a', bruce.arr, bruce);
    debug(type_name<decltype(ci)>());
    debug(type_name<decltype(mp(bruce, 10))>());
    debug(type_name<decltype(ahah)>());
    debug(type_name<decltype(100)>());

    return 0;
}

/*
 the output
>type_name<decltype(ci)>(): std::tuple<std::vector<long long int, std::allocator<long long int> >, double, const char*, char, float*, funuser::superuser::batman>
>type_name<decltype(mp(bruce, 10))>(): std::pair<funuser::superuser::batman, int>
>type_name<decltype(ahah)>(): std::vector<long long int>
>type_name<decltype(100)>(): int


*/