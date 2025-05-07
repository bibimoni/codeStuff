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

struct Node {
  Node *pt[26];
  int cnt, exists;
  Node() {
    for (int i = 0; i < 26; i++) {
      pt[i] = nullptr;
    }
    cnt = exists = 0;
  }
};

struct Trie {
  Node *root;
  Trie() {
    root = new Node();
  }
  void insert(string &s) {
    Node *cur = root;
    for (char i : s) {
      int c = i - 'A';
      if (cur->pt[c] == nullptr) {
        cur->pt[c] = new Node();
      }
      cur = cur->pt[c];
      cur->cnt += 1;
    }
    cur->exists += 1;
  }
  void del(string &s) {
    Node *cur = root;
    for (char i : s) {
      int c = i - 'A';
      assert(cur->pt[c] != nullptr);
      cur = cur->pt[c];
      cur->cnt -= 1;
    }
    cur->exists -= 1;
  }
  bool find(string &s) {
    Node *cur = root;
    for (char i : s) {
      int c = i - 'A';
      if (!cur->pt[c]) {
        return false;
      }
      cur = cur->pt[c];
      if (cur->cnt == 0) {
        return false;
      }
    }
    return cur->exists > 0;
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  Trie trie;
  string s;
  cin >> s;
  int n = s.size();
  vector<string> blocks;
  string cur = "";
  for (int i = 0; i < n; i++) {
    if (cur.size() == 0 || cur.back() > s[i]) {
      cur += s[i];
    } else {
      blocks.push_back(cur);
      cur = s[i];
    }
  }
  if (cur.size() != 0) {
    blocks.push_back(cur);
  }
  // while (true) {
    int m = blocks.size();
    vector<int> was(m, 0);
    vector<string> n_blocks;
    for (int i = 0; i < m; i++) {
      dbg(i, blocks[i], n_blocks);
      if (was[i]) {
        continue;
      }
      if (n_blocks.size() == 0) {
        n_blocks.push_back(blocks[i]);
        trie.insert(n_blocks.back());
        continue;
      } 
      dbg(n_blocks, blocks[i]);
      if (n_blocks.size() && n_blocks.back() > blocks[i]) {
        string cur = n_blocks.back() + blocks[i];
        trie.del(n_blocks.back());
        n_blocks.pop_back();
        n_blocks.push_back(cur);
        trie.insert(cur);
        dbg(n_blocks);
        continue;
      }
      int j = i + 1;
      while (trie.find(blocks[i])) {
        if (j == m) {
          break;
        }
        blocks[i] += blocks[j];
        was[j] = 1;
        j += 1;
      }
      trie.insert(blocks[i]);
      n_blocks.push_back(blocks[i]);
    } 
    dbg(n_blocks);
  // }
}

