#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mxN 1e7
#define newl cout<<"\n"
#define vi vector<int>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return nullptr;
    if(root->val > key) {
      root->left = deleteNode(root->left, key);
    }
    else if(root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      if(!root->left) {
        return root->right;
      }
      if(!root->right) {
        return root->left;
      }
      auto head = root->right;
      while(head->left) head = head->left;
      int data = root->val;
      root->val = head->val;
      head->val = data;
      root->right = deleteNode(root->right, data);
    }
    return root;
  }
};

int main() {
  auto sol = Solution();
//  debug(res);
}