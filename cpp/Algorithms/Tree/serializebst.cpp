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


class Codec {
public:

  TreeNode* newnode(int val) {
    auto root = new TreeNode(val);
    root->left = root->right = nullptr;
    return root;
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if(!root) return "";
    return to_string(root->val) +"," +serialize(root->left) +"," + serialize(root->right);
  }

  TreeNode* buildtree(stringstream& ss, int left = INT_MIN, int right = INT_MAX) {
    if(!ss.good()) return nullptr;
    string str;
    getline(ss, str, ',');
    if(!str.size()) return nullptr;
    int num = stoi(str);
    if( num < left || num > right) return nullptr;
    auto root = newnode(num);

    root->left = buildtree(ss, left, num-1);
    root->right = buildtree(ss, num+1, right);
    return root;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss(data);
    return buildtree(ss);
  }

};

int main() {
  auto sol = Codec();

  auto root = sol.newnode(1);
  root->left = sol.newnode(2);
  root->right = sol.newnode(3);

  auto str = sol.serialize(root);

  auto head = sol.deserialize(str);
  sol.preorder(head);



//  debug(res);
}