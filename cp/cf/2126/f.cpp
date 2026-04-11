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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<pair<int, int>> e;
    map<pair<int, int>, int> cost;
    for (int i = 0; i < n - 1; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      e.push_back({u, v});
      adj[u].push_back({v, c});
      adj[v].push_back({u, c});
      cost[{u, v}] = c;
      cost[{v, u}] = c;
    }

    int time = 1;
    vector<vector<pair<int, int>>> events(n + 1);
    while (q--) {
      int v, x;
      cin >> v >> x;
      events[v].push_back({time, x});
      time += 1;
    }

    dbg(events);
    vector<int> ans(time);
    for (auto [u, v] : e) {
      vector<array<int, 3>> s;
      for (auto [t, x] : events[u]) {
        s.push_back({t, 1, x});
      }

      for (auto [t, x] : events[v]) {
        s.push_back({t, 0, x});
      }

      sort(s.begin(), s.end());
      dbg(s);
      int cur_t = 0;
      vector<int> color{a[v], a[u]};
      for (auto p : s) {
        int t = p[0], i = p[1], val = p[2];
        ans[cur_t] += (color[0] != color[1] ? cost[{u, v}] : 0);
        ans[t] -= (color[0] != color[1] ? cost[{u, v}] : 0);
        color[i] = val;
        cur_t = t;
      }
      ans[cur_t] += (color[0] != color[1] ? cost[{u, v}] : 0);
    }

    for (int i = 1; i < time; i++) {
      ans[i] += ans[i - 1];
      cout << ans[i] << '\n';
    }
  }
}
