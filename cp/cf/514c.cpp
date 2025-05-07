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

struct Node {
  Node *pt[3];
  int cnt, exist;
  Node() {
    for(int i = 0; i < 3; i++) {
      pt[i] = nullptr;
    }
    cnt = 0;
    exist = 0;
  }
};

struct Trie {
  Node *root;
  Trie() {
    root = new Node();
  }
  void insert(string s) {
    insert(root, s);
  }
  bool query(string &s) {
    return query(root, s, false, 0, false);
  }
  void insert(Node *cur, string s) {
    for(char i : s) {
      int c = i - 'a';
      if(cur->pt[c] == nullptr)
        cur->pt[c] = new Node();
      cur = cur->pt[c];
      cur->cnt++;
    }
    cur->exist++;
  }
  bool query(Node *cur, string &s, bool diff, int idx, bool exist) {
    if(idx == s.size() && diff && exist)
      return true;
    bool ok = false;
    for(char nxt : {'a', 'b', 'c'}) {
      int c = nxt - 'a';
      if(cur->pt[c] == nullptr || cur->pt[c]->cnt == 0)
        continue;
      if(idx == s.size() - 1)
        exist = (cur->pt[c]->exist > 0);
      if(nxt == s[idx]) {
        ok |= query(cur->pt[c], s, diff, idx + 1, exist);
      }
      else if(!diff) {
        ok |= query(cur->pt[c], s, true, idx + 1, exist);
      }
    }
    return ok;
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  Trie trie;
  cin >> n >> m;
  vector<string> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    trie.insert(a[i]);
  }
  while(m--) {
    string s;
    cin >> s;
    cout << (trie.query(s) ? "YES\n" : "NO\n");
  }
}

