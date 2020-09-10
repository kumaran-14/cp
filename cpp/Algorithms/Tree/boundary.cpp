#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mxN 1e7
#define newl cout << "\n"
#define vi vector<int>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
  void boundary(TreeNode *root){
    if (root == nullptr)
      return;

    function<void(TreeNode*)> leftb = [&](TreeNode* root) {
      if(!root)
        return;
      if(root->left || root->right) cout<<root->val<<" ";
      if(root->left) leftb(root->left);
      else leftb(root->right);
    };

    function<void(TreeNode*)> rightb = [&](TreeNode* root) {
      if(!root)
        return;
      if(root->right) rightb(root->right);
      else rightb(root->left);
      if(root->left || root->right) cout<<root->val<<" ";
    };

    function<void(TreeNode*)> bottomb = [&](TreeNode* root) {
      if(!root) return;
      if(!root->left && !root->right) cout<<root->val<<" ";
      bottomb(root->left);
      bottomb(root->right);
    };


    cout<<root->val<<" ";

    leftb(root->left);

    bottomb(root->left);
    bottomb(root->right);

    rightb(root->right);

  };

};

void traverse(TreeNode *root) {
  if (!root)
    return;
  traverse(root->left);
  cout << root->val << " ";
  traverse(root->right);
  return;
}

int main() {
  auto sol = Solution();
  //  vector<int> arr = {3, 2, 1, 6, 0, 5};
  auto root = new TreeNode(20);
  root->left = new TreeNode(8);
  root->right = new TreeNode(22);
  root->right->right = new TreeNode(25);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(12);
  root->left->right->left = new TreeNode(10);
  root->left->right->right = new TreeNode(14);
  sol.boundary(root);

  //  auto root = sol.sumOfDistancesInTree(arr);
  //  traverse(root);
}