#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
  treeNode *left, *right;
  int data;
  treeNode(int data)
  {
    this->data = data;
    this->left = this->right = nullptr;
  }
};

class tree
{
public:
  treeNode *head;
  tree()
  {
    this->head = nullptr;
  }
  treeNode *addNode(treeNode *head, int data)
  {
    if (head == nullptr)
    {
      treeNode *newNode = new treeNode(data);
      head = newNode;
      return newNode;
    }
    if (head->data < data)
    {
      head->right = addNode(head->right, data);
    }
    else
    {
      head->left = addNode(head->left, data);
    }
    return head;
  }

  void preOrder(treeNode *head)
  {
    if (head != nullptr)
    {
      cout << head->data << " ";
      preOrder(head->left);
      preOrder(head->right);
    }
  }
  void postOrder(treeNode *head)
  {
    if (head != nullptr)
    {
      postOrder(head->left);
      postOrder(head->right);
      cout << head->data << " ";
    }
  }
  void inOrder(treeNode *head)
  {
    if (head != nullptr)
    {
      inOrder(head->left);
      cout << head->data << " ";
      inOrder(head->right);
    }
  }
  void levelOrder(treeNode *root)
  {
    queue<treeNode *> treeq;
    treeq.push(root);
    while (!treeq.empty())
    {
      treeNode *temp = treeq.front();
      cout << temp->data << " ";
      treeq.pop();
      if (temp->left != nullptr)
        treeq.push(temp->left);
      if (temp->right != nullptr)
        treeq.push(temp->right);
    }
  }

  void topView(treeNode *root)
  {
    queue<pair<int, treeNode *>> treeq;
    treeq.push(make_pair(0, root));
    map<int, treeNode *> treemap;
    while (!treeq.empty())
    {
      pair<int, treeNode *> temp = treeq.front();
      treemap.insert(temp);
      treeq.pop();
      if (temp.second->left != nullptr)
        treeq.push(make_pair(temp.first - 1, temp.second->left));
      if (temp.second->right != nullptr)
        treeq.push(make_pair(temp.first + 1, temp.second->right));
    }
    for (auto x : treemap)
    {
      cout << x.second->data << " ";
    }
  }

  int height(treeNode *root)
  {
    // Write your code here.
    if (root == nullptr)
    {
      return -1;
    }
    return 1 + max(height(root->left), height(root->right));
  }

  int diameter(treeNode *head)
  {
    if (head == nullptr)
    {
      return 0;
    }
    int lh = height(head->left);
    int rh = height(head->right);

    int ldia = diameter(head->left);
    int rdia = diameter(head->right);

    return max(lh + rh + 1, max(ldia, rdia));
  }

  bool checkBST(treeNode *root, int min, int max)
  {
    if (root == nullptr)
      return true;
    if (root->data < min || root->data > max)
      return false;
    return (checkBST(root->left, min, root->data - 1) && checkBST(root->right, root->data + 1, max));
  }

  bool checkBST(treeNode *root)
  {
    return checkBST(root, 0, 10000);
  }
};

int main()
{
  tree temp;
  temp.head = temp.addNode(temp.head, 22);
  temp.addNode(temp.head, 10);
  // temp.addNode(temp.head, 41);
  // temp.addNode(temp.head, 8);
  // temp.head = temp.addNode(temp.head, 9);
  temp.preOrder(temp.head);
  cout << endl;
  temp.postOrder(temp.head);
  cout << endl;
  temp.inOrder(temp.head);
  return 0;
}
