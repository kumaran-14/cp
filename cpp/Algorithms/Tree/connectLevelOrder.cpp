#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mxN 1e7
#define newl cout << "\n"
#define vi vector<int>

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  void util(Node *root, Node *next) {
    if (!root)
      return;
    root->next = next;
    Node *noice = nullptr;
    auto head = root->next;
    while (head) {
      if (head->left) {
        noice = head->left;
        break;
      } else if (head->right) {
        noice = head->right;
        break;
      } else {
        head = head->next;
      }
    }

    // reverse postorder important. Else, the above while will not go to the right end of a level every time.
    if (root->right)
      util(root->right, noice);

    if (root->left) {
      if (root->right)
        util(root->left, root->right);
      else
        util(root->left, noice);
    }
  }

  Node *connect(Node *root) {
    util(root, nullptr);
    return root;
  }
};

int main() { auto sol = Solution(); }