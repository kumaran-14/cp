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

// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };

class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    bool ans = false;
    stack<TreeNode*> increasing, decreasing;

    function<void()> moveright = [&]() {
      if(increasing.empty()) return;
      auto top = increasing.top(); increasing.pop();
      auto ptr = top->right;
      while(right) {
        increasing.push(ptr);
        ptr = ptr->left;
      };
    };

    function<void()> moveleft = [&]() {
      if(decreasing.empty()) return;
      auto top = decreasing.top(); decreasing.pop();
      auto ptr = top->left;
      while(ptr) {
        decreasing.push(ptr);
        ptr = ptr->right;
      };
    };

    auto temp = root;
// initialize increasing stack with lowest value of BST at top
    while(temp) {
      increasing.push(temp);
      temp = temp->left;
    }
    temp = root;
  // initialize decreasing stack with highest value of BST at top
    while(temp) {
      decreasing.push(temp);
      temp = temp->right;
    }

  // two pointer technique
    while(!ans && !increasing.empty() && !decreasing.empty()) {
      auto v1 = increasing.top()->val, v2 = decreasing.top()->val;
      if(v1 + v2 == k && increasing.top() != decreasing.top()) {
        ans = true;
        break;
      }
      if(v1 > v2) break;
      if(v1+v2 < k) {
        moveright();
      } else {
        moveleft();
      }
    }

    return ans;
  }
};