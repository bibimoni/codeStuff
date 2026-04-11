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
#define int int64_t

void sub1(vector<int> &c, int n, int q) {
  vector<int> slot(n + 1);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, p;
      cin >> u >> p;
      if (slot[u] + p <= c[u]) {
        slot[u] += p;
      } else {
        slot[u] = c[u];
      }
    } else if (op == 2) {
      int u;
      cin >> u;
      cout << slot[u] << ' ';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    const int inf = 1e18;
    vector<int> nxt_slot(n + 1, inf);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      deg[v] += 1;
    }

    for (int u = 1; u <= n; u++) {
      sort(adj[u].begin(), adj[u].end());
      nxt_slot[u] = adj[u].size() ? 0 : inf;
    }

    if (m == 0) {
      sub1(c, n, q);
      cout << '\n';
      continue;
    }
    // sub2
    vector<int> slot(n + 1, 0);
    while (q--) {
      int op;
      cin >> op;
      if (op == 1) {
        int u, p;
        cin >> u >> p;
        if (slot[u] + p > c[u]) {
          slot[u] += p;
        } else {
          slot[u] = c[u];
        }
        int cur = u;

        while (nxt_slot[cur] < (int)adj[cur].size()) {
          if (slot[cur] + p <= c[u]) {
            // slot[cur] += p;
            // break;
          } else {
            slot[cur] = c[u];
            p = slot[cur] + p - c[u];
            if (nxt_slot[cur] < (int)adj[cur].size()) {
              cur = adj[cur][nxt_slot[cur]];
              nxt_slot[cur] += 1;
            } else {
              break;
            }
          }
        }
      } else if (op == 2) {
        int u;
        cin >> u;
        cout << slot[u] << ' ';
      }
      dbg(slot);
    }
    cout << '\n';
  }
}
