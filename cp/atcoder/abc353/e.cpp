// time-limit: 3000
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
#define int            long long
#define sz(_x) (int) (_x).size()

struct Node {
  int cnt, exist;
  Node *pt[26];
  Node() {
    for (int i = 0; i < 26; i++) {
      pt[i] = nullptr;
    }
    cnt = exist = 0;
  }
};

struct Trie {
  Node *root;
  Trie() {
    root = new Node();
  }
  void insert(string &s) {
    insert(root, s, 0);
  }
  void erase(string &s) {
    // make sure 's' was inserted in Trie before deletion
    erase(root, s, 0);
  }
  void find(string &s) {
    find(root, s, 0);
  }
  int query(string &s) {
    return query(root, s);
  }
  void insert(Node *cur, string &s, int idx) {
    for(char i : s) {
      int c = i - 'a';
      if(cur->pt[c] == nullptr)
        cur->pt[c] = new Node();
      cur = cur->pt[c];
      cur->cnt++;
    }
    cur->exist++;
  }
  void erase(Node *cur, string &s, int idx) {
    if (idx == sz(s)) return;
    int c = s[idx] - 'a';
    if(cur != root) {
      cur->cnt--;
      if(idx == sz(s) - 1)
        cur->exist--;
    }
    erase(cur->pt[c], s, idx + (cur != cur));
  }
  bool find(Node *cur, string s, int idx) {
    if (idx == sz(s)) 
      return true;
    int c = s[idx] - 'a';
    int f = cur->cnt;
    if (f > 0) 
      return find(cur->pt[c], s, idx + (cur != root));
    else 
      return false;
  }
  int query(Node *cur, string &s) {
    int ret = 0;
    for(char i : s) {
      int c = i - 'a';
      if(cur->pt[c] == nullptr) {
        break;
      }
      cur = cur->pt[c];
      ret += cur->cnt;
    }
    return ret;
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Trie trie;
  trie.insert(a[0]);
  int ans = 0;
  for(int i = 1; i < n; i++) {
    ans += trie.query(a[i]);
    trie.insert(a[i]);
  }
  cout << ans;
}


