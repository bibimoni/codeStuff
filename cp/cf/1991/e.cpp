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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> color(n + 1, -1);
    queue<int> que;
    que.push(1);
    color[1] = 0;
    bool is_bipartite = true;
    while (que.size()) {
      auto u = que.front();
      que.pop();
      for (int v : adj[u]) {
        if (color[v] == -1) {
          color[v] = 1 - color[u];
          que.push(v);
        } else {
          is_bipartite &= color[u] != color[v];
        }
      }
    }
    if (is_bipartite) {
      cout << "Bob\n";
      cout.flush();
      vector<vector<int>> side(2);
      for (int i = 1; i <= n; i++) {
        side[color[i]].push_back(i);
      }
      for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b < a) {
          swap(a, b);
        }
        a -= 1;
        b -= 1;
        if (side[a].size()) {
          cout << side[a].back() << " " << a + 1 << '\n';
          side[a].pop_back();
        } else {
          int rem = 1 - a;
          cout << side[rem].back() << " " << b + 1 << '\n';
          side[rem].pop_back();
        }
        cout.flush();
      }
    } else {
      cout << "Alice\n";
      cout.flush();
      for (int i = 0; i < n; i++) {
        cout << "1 2\n";
        cout.flush();
        int u, c;
        cin >> u >> c;
      }
    }
  }
}

