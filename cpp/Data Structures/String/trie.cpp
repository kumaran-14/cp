#include <bits/stdc++.h>
using namespace std;

#define foi(i, a, n) for (i = (a); i < (n); ++i)

struct trienode {
  struct trienode *children[26];
  bool wordend;
};

typedef struct trienode trienode;

trienode *getNode() {
  trienode *newnode = new trienode;
  int i;
  foi(i, 0, 26) { newnode->children[i] = nullptr; }
  newnode->wordend = false;
  return newnode;
}

void insert(trienode *root, string s) {
  trienode *temp = root;
  for (auto x : s) {
    int i = x - 'a';
    if (temp->children[i] == nullptr) {
      temp->children[i] = getNode();
    }
    temp = temp->children[i];
  }
  temp->wordend = true;
}

bool search(trienode *root, string s) {
  trienode *temp = root;
  for (auto x : s) {
    int i = x - 'a';
    if (temp->children[i] == nullptr)
      return false;
    temp = temp->children[i];
  }
  return temp->wordend;
}

int main() {
  string stringlist[] = {"kumaran", "kums", "kumara", "gokul"};
  trienode *root = getNode();
  for (auto s : stringlist)
    insert(root, s);
  cout << search(root, "gokul");
}

/*
#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
  bool isEnd;
  vector<Trie *> nodes;

public:
  //  Initialize your data structure here.
  Trie() {
    nodes.resize(26, nullptr);
    isEnd = false;
  }

  // Inserts a word into the trie

  void insert(string word) {
    Trie *next = this;
    for (auto ch : word) {
      ch -= 'a';
      if (!next->nodes[ch])
        next->nodes[ch] = new Trie();
      next = next->nodes[ch];
    }
    next->isEnd = true;
  }

  // Returns if the word is in the trie
  bool search(string word) {
    auto next = this;
    for (auto ch : word) {
      ch -= 'a';
      if (!next->nodes[ch])
        return false;
      next = next->nodes[ch];
    }
    return next->isEnd;
  }

  // Returns if there is any word in the trie that starts with the given prefix

  bool startsWith(string prefix) {
    auto next = this;
    for (auto ch : prefix) {
      ch -= 'a';
      if (!next->nodes[ch])
        return false;
      next = next->nodes[ch];
    }
    return true;
  }
};

*/