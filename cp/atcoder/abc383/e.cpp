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

class Dsu {
  vector<int> parent, size;

public:
  Dsu() {}
 
  Dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(parent.begin(), parent.end(), 0ll);
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
      return true;
    } else {
      return false;
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<array<int, 3>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }
  vector<int> a(k), cnt_a(n + 1);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    cnt_a[a[i]] += 1;
  }
  vector<int> b(k), cnt_b(n + 1);
  for (int i = 0; i < k; i++) {
    cin >> b[i];
    cnt_b[b[i]] += 1;
  }
  sort(edges.begin(), edges.end());
  Dsu dsu(n + 1);
  vector<vector<pair<int, int>>> adj(n + 1);
  int ans = 0;
  for (auto p : edges) {
    int ra = dsu.find(p[1]);
    int rb = dsu.find(p[2]);
    if (ra == rb) {
      continue;
    }
    dsu.unite(ra, rb);
    int rn = dsu.find(ra);
    cnt_a[rn] = cnt_a[ra] + cnt_a[rb];
    cnt_b[rn] = cnt_b[ra] + cnt_b[rb];
    ans += p[0] * min(cnt_a[rn], cnt_b[rn]);
    int pp = min(cnt_a[rn], cnt_b[rn]);
    cnt_a[rn] -= pp;
    cnt_b[rn] -= pp;
  }
  cout << ans << '\n';
}