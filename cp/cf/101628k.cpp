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
#define int long long
#define sz(_x) (_x).size()

const int INF = (int) 1e18;

struct Node {
  Node *pt[26];
  set<int> cnt;
  set<int> exist;
  Node() {
    for (int i = 0; i < 26; i++) {
      pt[i] = nullptr;
    }
    cnt.clear();
    exist.clear();
  }
};

struct Trie {
  Node *root;
  Trie() {
    root = new Node();
  }
  void insert(string s, int pos) {
    insert(root, s, pos);
  }
  void erase(string s, int pos) {
    erase(root, s, pos);
  }
  bool vPrefix(string s, int l, int r) {
    return vPrefix(root, s, l, r);
  }
  bool sPrefix(string s, int l, int r) {
    return sPrefix(root, s, l, r);
  }
  void insert(Node *cur, string s, int pos) {
    for(char i : s) {
      int c = i - 'a';
      cur->cnt.insert(pos);
      if(cur->pt[c] == nullptr) {
        cur->pt[c] = new Node();
      }
      cur = cur->pt[c];
    }
    cur->cnt.insert(pos);
    cur->exist.insert(pos);
  }
  void erase(Node *cur, string s, int pos) {
    for(char i : s) {
      int c = i - 'a';
      cur->cnt.erase(pos);
      cur = cur->pt[c];
    }
    cur->cnt.erase(pos);
    cur->exist.erase(pos);
  }
  bool has(set<int> &s, int l, int r) {
    auto pos = s.lower_bound(l);
    return s.size() && pos != s.end() && *pos <= r;
  }
  bool vPrefix(Node *cur, string s, int l, int r) {
    for(char i : s) {
      int c = i - 'a';
      if(cur->pt[c] == nullptr) {
        return false;
      }
      cur = cur->pt[c];
      if(has(cur->exist, l, r)) {
        return true;
      }
    }
    return false;
  }
  bool sPrefix(Node *cur, string s, int l, int r) {
    // dbg(s);
    for(char i : s) {
      int c = i - 'a';
      if(cur->pt[c] == nullptr) {
        return false;
      }
      cur = cur->pt[c];
      if(!has(cur->cnt,l ,r)) {
        return false;
      }
    }
    return true;
  }
};

Trie trie;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for(int i = 1; i <= n; i++) {
    trie.insert(s[i], i);
  }
  int q;
  cin >> q;
  while(q--) {
    int type;
    cin >> type;
    if(type == 1) {
      int i; string t;
      cin >> i >> t;
      trie.erase(s[i], i);
      s[i] = t;
      trie.insert(s[i], i);
    }
    else if(type == 2) {
      int l, r;
      string s;
      cin >> l >> r >> s;
      cout << (trie.vPrefix(s, l, r) ? "Y\n" : "N\n");
    }
    else if(type == 3) {
      int l, r;
      string s;
      cin >> l >> r >> s;
      cout << (trie.sPrefix(s, l, r) ? "Y\n" : "N\n");
    }
  }
}