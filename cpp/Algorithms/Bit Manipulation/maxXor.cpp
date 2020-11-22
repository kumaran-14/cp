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

struct node {
  struct node* children[2];
  node() {
    children[0] = nullptr;
    children[1] = nullptr;
  }
};

class Solution {
public:
  int findMaximumXOR(vector<int>& arr) {
    int n = arr.size();
    // build tree;
    auto root = new node();
    // construct trie.
    rep(i, 0, n) {
      auto head = root;
      auto num = arr[i];
      rep(j, 31, 0) {
        auto currbit = ((num>>j) & 1);
        if(head->children[currbit] == nullptr) {
          head->children[currbit] = new node();
        }
        head = head->children[currbit];
      }
    }
    int ans = INT_MIN;
    // search tree;
    rep(i, 0, n) {
      auto num = arr[i];
      int currsum = 0;
      auto head = root;
      rep(j, 31, 0) {
        auto currbit = ((num>>j) & 1);
        if(head->children[currbit^1]) {
          currsum += (1<<j);
          head = head->children[currbit^1];
        } else {
          head = head->children[currbit];
        }

      }
      ans = max(ans, currsum);
    }
    return ans;
  }
};

void binary(unsigned n)
{
  unsigned i;
  string str = "";
  for (i = 1 << 3; i > 0; i = i>>1) {
    if((n&i)) str += '1';
    else str += '0';
  }
  cout<<str<<endl;
}

int main() {
  auto sol = Solution();
  vector<vector<int>> arr = {{0,1,0}, {1,1,1}, {0,1,0}};
  vector<int> vec = {2, 3, 4};
  int n = arr.size();
//  auto res = sol.numSubmatrixSumTarget(arr, 0);
//  debug(res);
//  vector<int> v;

  for(auto i = 0; i <= 5; i++) binary(i);

}