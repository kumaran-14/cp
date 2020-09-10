#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mxN 1e7
#define newl cout << "\n"
#define vi vector<int>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


typedef pair<int, pair<int, int>> threepair;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& arr) {
    vector<vi> ans;
    int n = arr.size();
    rep(mask, 0, 1<<n) {
      vi vec;
      rep(i, 0, n) {
        bool set = (n&1<<i);
        if(set) vec.push_back(arr[i]);
      }
      ans.push_back(vec);
    }
    return ans;
  }
};

int main() {
  auto sol = Solution();
  vector<vector<int>> arr = {{0,1,0}, {1,1,1}, {0,1,0}};
  vector<int> vec = {2, 3, 4};
  int n = arr.size();
//  auto res = sol.numSubmatrixSumTarget(arr, 0);
//  debug(res);
//  vector<int> v;

}