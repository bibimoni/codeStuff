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

const int N = 1e5 + 5;

vector<vector<int>> adj(N + 1);
vector<int> a(N + 1);
vector<int> root(N + 1);
stack<int> st;
vector<int> low(N + 1), id(N + 1);
vector<int> was(N + 1, 0);
vector<int> val(N + 1, 0);
int time_dfs = 0, sccs = 0;
void dfs(int u) {
  time_dfs += 1;
  low[u] = id[u] = time_dfs;
  st.push(u);
  for (int v : adj[u]) {
    if (was[u]) {
      continue;
    }
    if (id[v]) {
      low[u] = min(low[u], id[v]);
    } else {
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
  }
  if (low[u] == id[u]) {
    int v;
    sccs += 1;
    do {
      v = st.top();
      st.pop();
      was[v] = 1;
      root[v] = sccs;
      val[sccs] += a[v];
    } while (u != v);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    edges.push_back({u, v});
  }

  for (int i = 1; i <= n; i++) {
    if (!id[i]) {
      dfs(i);
      time_dfs = 0;
    }
  }

  vector<vector<int>> g(n + 1);
  vector<int> ind(n + 1, 0);
  for (auto [u, v] : edges) {
    if (root[u] == root[v]) {
      continue;
    }
    g[root[u]].push_back(root[v]);
    ind[root[v]] += 1;
  }

  queue<int> que;
  for (int i = 1; i <= sccs; i++) {
    if (!ind[i]) {
      que.push(i);
    }
  }

  while (que.size()) {
    int u = que.front();
    que.pop();
    for (int v : g[u]) {
      
    }
  }

  vector<int> memo(n + 1, -1);
  auto dp = [&] (auto &&self, int u) -> int {
    if (memo[u] != -1) {
      return memo[u];
    }
    memo[u] = val[u];
    for (int v : g[u]) {
      memo[u] = max(memo[u], self(self, v) + val[u]);
    }
    return memo[u];
  };
  int ans = 0;
  for (int i = 1; i <= sccs; i++) {
    ans = max(ans, dp(dp, i));
  }
  cout << ans << "\n";
}

