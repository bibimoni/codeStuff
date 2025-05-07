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
  vector<vector<int>> e;
public:
  Dsu() {}
 
  Dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    e.resize(n);
    for (int i = 1; i <= n; i++) {
      e[i].push_back(i);
    }
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
      for (int i : e[b]) {
        e[a].push_back(i);
      }
      return true;
    } else {
      return false;
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  Dsu dsu(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    dsu.unite(u, v);
  }
  vector<int> dp(n + 1, 0);
  auto dfs = [&] (auto &&self, int src, int u, int p) -> int {
    if (u == src) {
      return 1;
    }
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      self(self, src, v, u);
      dp[u] += dp[v];
    }
    return dp[u];
  };
  for (int i = 1; i <= n; i++) {
    
  }
}


