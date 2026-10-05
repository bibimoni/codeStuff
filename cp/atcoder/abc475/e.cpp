/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t


struct Node {
  Node *pt[2];
  int cnt;
  int id;
  Node(int _id) {
    for (int i = 0; i < 2; i++) {
      pt[i] = nullptr;
    }
    cnt = 0;
    id = _id;
  }
};

struct Trie {
  Node *root;
  vector<vector<int>> mask;
  int label = 0;
  Trie(int n, int k){ 
    root = new Node(label); 
    vector<int> p(n);
    mask = vector<vector<int>>(n, vector<int>(k, -1));
  }
  vector<int> convert(string x) {
    vector<int> v(x.size());
    for (int i = 0; i < int(v.size()); i++) {
      v[i] = x[i] == 'x';
    }
    return v;
  }
  void insert(string x, int id) { 
    insert(root, convert(x), 0, id); 
  }
  bool query(string x, int id, int m) { 
    return query(root, convert(x), 0, id, m); 
  }
  void remove(string x, int id) {
    remove(root, convert(x), 0, id); 
  }
private: 
  bool remove(Node *cur, vector<int> x, int b, int id) {
    if (x.size() == (size_t)b) {
      return true;
    }
    int c = x[b];
    cur = cur->pt[c];
    mask[id][b] = -1;
    cur->cnt -= 1;
    return remove(cur, x, b + 1, id);
  }
  bool insert(Node *cur, vector<int> x, int b, int id) {
    if (x.size() == (size_t)b)
      return true;
    int c = x[b];
    if (cur->pt[c] == nullptr) {
      cur->pt[c] = new Node(++label);
    }
    cur = cur->pt[c];
    mask[id][b] = cur->id;
    cur->cnt += 1;
    return insert(cur, x, b + 1, id);
  }
  bool query(Node *cur, vector<int> x, int b, int id, int m) {
    if (x.size() == (size_t)b) {
      return false;
    }
    int c= x[b];
    Node *nxt = cur->pt[c];
    if (nxt == nullptr) {
      if (cur->pt[1 ^ c] == nullptr) 
        return false;
      return query(cur->pt[1 ^ c], x, b + 1, id, m);
    }
    if (m - nxt->cnt < 0) {
      return query(nxt, x, b + 1, id, m); 
    }

    m -= nxt->cnt;
    if (mask[id][b] == nxt->id) {
      return true;
    }
    if (m == 0 || cur->pt[1 ^ c] == nullptr) {
      return false;
    }
    return query(cur->pt[1 ^ c], x, b + 1, id, m);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  string t;
  cin >> t;
  vector<string> s(n);
  Trie trie(n, k);
  for (int i = 0; i < n; i++){
    cin >> s[i];
    trie.insert(s[i], i);
  }

  int q;
  cin >> q;
  vector<pair<int, int>> que(q);
  while (q--) {
    int u, v;
    cin >> u >> v;
    u -= 1;
    v -= 1;
    trie.remove(s[u], u);
    s[u][v] = s[u][v] == 'x' ? 'o' : 'x';
    trie.insert(s[u], u);
    cout << (trie.query(t, u, m) ? "Yes\n" : "No\n");
  }
}
