/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

const int INF = 1e9 + 7;

struct Node {
  vector<int> dp;
  vector<Node *>nxt;
  Node() {
    dp.assign(26, INF);
    nxt = vector<Node*>(26, nullptr);
  }
};

struct Trie {
  Node *root;
  Trie() {
    root = new Node();
  }

  int insert(string &s) {
    return insert(root, s);
  }

  int insert(Node *cur, string &s) {
    int ans = s.size();
    for (int i = 0; i < int(s.size()); i++) {
      int c = s[i] - 'a';
      if (cur->nxt[c] == nullptr) {
        cur->nxt[c] = new Node();
      }
      cur = cur->nxt[c];
      ans = min(ans, cur->dp[c] + (int)s.size() - 2 * i - 2);
      cur->dp[c] = min(cur->dp[c], (int)s.size());
    }
    return ans;
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  Trie trie;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    cout << trie.insert(s) << '\n';
  }
}

