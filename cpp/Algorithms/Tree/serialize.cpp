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
    if(!root) return "#";
    return to_string(root->val) +"," +serialize(root->left) +"," + serialize(root->right);
  }

  TreeNode* buildtree(stringstream& ss) {
    if(!ss.good()) return nullptr;
    string str;
    getline(ss, str, ',');
    if(!str.size()) return nullptr;
    if(str == "#") return nullptr;
    int num = stoi(str);
    auto root = newnode(stoi(str));
    root->left = buildtree(ss);
    root->right = buildtree(ss);
    return root;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<string> vec;
    stringstream ss(data);
//    while(ss.good()) {
//      string str;
//      getline(ss, str, ',');
//      if(str.size()) vec.push_back(str);
//    }

    return buildtree(ss);
  }

  void preorder(TreeNode* root) {
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
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


