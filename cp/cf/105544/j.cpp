/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#define table(...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (true) {
    string s;
    cin >> s;
    s.push_back(',');
    vector<int> a;
    int cur = 0;
    for (int i = 0; i < int(s.size()); i++) {
      if (s[i] == ',') {
        a.push_back(cur);
        cur = 0;
      } else {
        cur = cur * 10 + int(s[i] - '0');
      }
    }

    vector<vector<pair<int, int>>> adj(n);
    vector<int> in(n);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      in[v] += 1;
    }

    vector<int> d(n, 0);
    queue<int> q;
    vector<int> cnt(n);
    vector<int> trace(n, -1);
    for (int u = 0; u < n; u++) {
      if (in[u] == 0) {
        d[u] = a[u];
        q.push(u);
        cnt[u] = 1;
      }
    }

    while (q.size()) {
      int u = q.front();
      q.pop();
      for (auto [v, w] : adj[u]) {
        if (d[v] < d[u] + w + a[v]) {
          d[v] = d[u] + w + a[v];
          trace[v] = u;
          cnt[v] = cnt[u];
        } else if (d[v] == d[u] + w + a[v]) {
          cnt[v] += cnt[u];
        }
        if (--in[v] == 0) {
          q.push(v);
        }
      }
    }

    int u = int(max_element(d.begin(), d.end()) - d.begin());
    int mx = d[u], c = cnt[u];
    for (int i = u + 1; i < n; i++) {
      if (d[i] == mx) {
        c += cnt[i];
      }
    }

    if (c == 1) {
      vector<int> ans;
      while (u != -1) {
        ans.push_back(u);
        u = trace[u];
      }
      reverse(ans.begin(), ans.end());
      cout << mx << ",";
      for (int i = 0; i < int(ans.size()); i++) {
        cout << ans[i] << ",\n"[i == int(ans.size()) - 1];
      }
    } else {
      cout << mx << ",M\n";
    }

    if (!(cin >> n >> m)) {
      break;
    }
  }
}
