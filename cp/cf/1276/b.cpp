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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> joint(n + 1, 0);
    vector<int> num(n + 1, 0), low(n + 1, 0);
    int timeDfs = 0;
    auto dfs = [&] (auto &&self, int u, int p) -> void {
      num[u] = low[u] = ++timeDfs;
      int child = 0;
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        if (!num[v]) {
          self(self, v, u);
          low[u] = min(low[v], low[u]);
          child += 1;
          if (u == p) {
            if (child > 1) {
              joint[u] = 1;
            }
          }
          else if (low[v] >= num[u]) {
            joint[u] = 1;
          }
        } else {
          low[u] = min(num[v], low[u]);
        }
      }
    };
    dfs(dfs, 1, 1);

    if (!joint[a] || !joint[b]) {
      cout << "0\n";
      continue;
    }

    auto getSet = [&] (int src) -> vector<int> {
      queue<int> q;
      vector<int> was(n + 1);
      q.push(src);
      while (q.size()) {
        int u = q.front();
        q.pop();
        if (was[u] || (u != src && (u == a || u == b))) {
          continue;
        } 
        was[u] = 1;
        for (int v : adj[u]) {
          q.push(v);
        }
      }
      return was;
    };

    vector<int> mark(n + 1, 0);    
    mark[a] = mark[b] = 1;
    auto da = getSet(a);
    auto db = getSet(b);
    for (int i = 1; i <= n; i++) {
      if (da[i] + db[i] == 2) {
        mark[i] = 1;
      }
    }
    auto findSz = [&] (int src) -> int {
      int sz = 0;
      queue<int> q;
      vector<int> was(n + 1, 0);
      q.push(src);
      while (q.size()) {
        int u = q.front();
        q.pop();
        if (was[u] || (mark[u] && u != src)) {
          continue;
        }
        was[u] = 1;
        sz += (u != src);
        for (int v : adj[u]) {
          q.push(v);
        }
      }
      return sz;
    };
    int ans = findSz(a) * findSz(b);
    cout << ans << '\n';
  }
}

