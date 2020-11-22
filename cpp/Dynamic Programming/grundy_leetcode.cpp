#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define db(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mxN 1e7
#define newl cout << "\n"
#define vi vector<int>
#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

class Solution {
public:
  bool canIWin(int n, int target) {
    if(target <= n)
      return true;
    if((n*(n+1))/2 < target)
      return false;
    if((n*(n+1))/2 == target) return n%2;

    vector<bool> num(n+1, 0);

    unordered_map<int, bool> hm;
    auto configtohash = [&](const vector<bool>& config) {
      int hash = 0;
      for(int i = 1; i <= n; i++) {
        if(config[i]) {
          hash += (1<<i);
        }
      }
      return hash;
    };
    // function is always just before 1st players move.
    function<bool(int, vector<bool>)> dfs = [&](int sum, vector<bool> arr) {
      auto hash = configtohash(arr);
      if(hm.find(hash) != hm.end()) return hm[hash];
      // before I play, the game is won. So I lose;
      if(sum >= target) return false;
      bool move = false;
      for(int x = 1; x <= n; x++) {
        if(arr[x] == 0) {
          arr[x] = 1;
          auto test = dfs(sum+x, arr);
          // there exists a move, such that opponent loses(no matter what he does, he loses); Its optimal move and I play this;
          if(!test) {
            hm[hash] = true;
            return true;
          }
          arr[x] = 0;
        }
      }
      // no move exists for me to win. I will always lose;
      hm[hash] = false;
      return false;
    };
    return dfs(0, num);
  }
};

int main() {
  freopen("../output.txt", "w", stdout);
  auto sol = Solution();
  vector<vector<int>> arr = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
  vector<int> vec = {2, 3, 4};
  int n = arr.size();
  auto res = sol.canIWin(10, 11);
  db(res);
  //  vector<int> v;
}