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
#define int int64_t 

struct Node {
  Node *pt[2];
  int cnt, id;
  Node() {
    pt[0] = pt[1] = nullptr;
    cnt = id = 0;
  }
};


struct Triexor {
  Node *root;
  int LG;
  Triexor(int bit) : LG(bit) {
    root = new Node();
  }
  void insert(int val, int i) {
    insert(root, val, i);
  }
  void insert(Node *cur, int val, int i) {
    for (int j = LG - 1; j >= 0; j--) {
      int c = (val >> j) & 1;
      if (cur->pt[c] == nullptr) {
        cur->pt[c] = new Node();
      }
      cur = cur->pt[c];
      cur->cnt += 1;
    }
    cur->id = i;
  }
  void del(int val) {
    del(root, val);
  }
  void del(Node *cur, int val) {
    for (int j = LG - 1; j >= 0; j--) {
      int c = (val >> j) & 1;
      if (cur->pt[c] == nullptr) {
        break;
      }
      cur = cur->pt[c];
      cur->cnt -= 1;
    }
  }
  int min_xor(int val) {
    return min_xor(root, val);
  }
  int min_xor(Node *cur, int val) {
    for (int j = LG - 1; j >= 0; j--) {
      int c = (val >> j) & 1;
      if (cur->pt[c] != nullptr && cur->pt[c]->cnt > 0) {
        cur = cur->pt[c];
      } else {
        cur = cur->pt[1 ^ c];
      }
    }
    return cur->id;
  }
};

class Dsu {
  vector<int> parent, size;

public:
  vector<vector<int>> gr;
  Dsu() {}
 
  Dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(parent.begin(), parent.end(), 0ll);
    gr.resize(n);
    for (int i = 0; i < n; i++) {
      gr[i].push_back(i);
    }
  }
 
  int find(int v) {
    if (v == parent[v]) {
      return v;
    }
    return parent[v] = find(parent[v]);
  }
 
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) {
        swap(a, b);
      }
      parent[b] = a;
      size[a] += size[b];
      for (int i : gr[b]) {
        gr[a].push_back(i);
      }
      gr[b].clear();
      return true;
    } else {
      return false;
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("storm.inp", "r", stdin);
  freopen("storm.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> a;
  const int LG = 30, INF = 2e9;
  Triexor trie(LG);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  n = a.size();
  a.insert(a.begin(), 0);
  for (int i = 1; i <= n; i++) {
    trie.insert(a[i], i);
  }
  Dsu dsu(n + 1);
  int ans = 0, comps = n;
  vector<int> vis(n + 1);
  vector<pair<int, int>> edges(n + 1);
  while (comps > 1) {
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      edges[i] = {INF, -1};
    }
    for (int i = 1; i <= n; i++) {
      int id = dsu.find(i);
      if (vis[id]) {
        continue;
      }
      vis[id] = 1;
      for (int i : dsu.gr[id]) {
        trie.del(a[i]);
      }
      for (int u : dsu.gr[id]) {
        int v = trie.min_xor(a[u]);
        edges[id] = min(edges[id], {a[v] ^ a[u], v});
      }
      for (int i : dsu.gr[id]) {
        trie.insert(a[i], i);
      }
    }
    for (int i = 1; i <= n; i++) {
      auto [cost, j] = edges[dsu.find(i)];
      if (dsu.unite(i, j)) {
        comps -= 1;
        ans += cost;
      }
    }
  }
  cout << ans << '\n';
}


