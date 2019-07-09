#include <bits/stdc++.h>
using namespace std;

#define foi(i, a, n) for ( i = (a); i < (n); ++i)


struct trienode {
  // struct trienode *children[26];
  unordered_map<char, struct trienode*> child;
  bool wordend;
};

typedef struct trienode trienode;

trienode* getNode() {
  trienode *newnode = new trienode;
  newnode->wordend = false;
  return newnode;
}

void insert(trienode *root, string s) {
  trienode *temp = root;
  for(auto x:s) {
    int i = x - 'a';
    if (temp->child.find(i) == temp->child.end() ) {
      temp->child[i] = getNode();
    }
    temp = temp->child[i];
  }
  temp->wordend = true;
}

bool search(trienode *root, string s) {
  trienode *temp = root;
  for(auto x:s) {
    int i = x - 'a';
    if(temp->child.find(i)== temp->child.end())
      return false;
    temp = temp->child[i];
  }
  return temp->wordend;
}

int main()
{
  string stringlist[] = {"kumaran", "kums", "kumara", "gokul"};
  trienode *root = getNode();
  for (auto s : stringlist)
    insert(root, s);
  cout << search(root, "gokull");
}
