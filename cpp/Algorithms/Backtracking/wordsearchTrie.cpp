#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
  bool isEnd;
  vector<Trie *> nodes;

  Trie() {
    nodes.resize(26, nullptr);
    isEnd = false;
  }

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
};

class Solution {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    int n = board.size();
    if (n == 0)
      return vector<string>();
    int m = board[0].size();

    Trie *root = new Trie();
    for (auto str : words)
      root->insert(str);

    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    set<string> hs;
    function<void(Trie *, int, int, string)> dfs = [&](Trie *head, int i, int j,
                                                       string word) {
      if (head == nullptr || head->nodes[board[i][j] - 'a'] == nullptr)
        return;
      word.push_back(board[i][j]);
      if (head->nodes[board[i][j] - 'a']->isEnd) {
        hs.insert(word);
        head->isEnd = false;
      }
      vis[i][j] = true;
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x < 0 || y < 0 || x >= n || y >= m)
          continue;
        if (!vis[x][y]) {
          dfs(head->nodes[board[i][j] - 'a'], x, y, word);
        }
      }
      vis[i][j] = false;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dfs(root, i, j, "");
      }
    }
    vector<string> vec(hs.begin(), hs.end());
    return vec;
  }
};

// using trie(searching for all words with prefix, for a ch in board)
// not using trie  - brute force, every ch in board, dfs for every word O(n*m*(wordlist length)*dfs time*)
//