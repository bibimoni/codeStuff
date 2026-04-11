#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  if (!(cin >> T))
    return 0;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
      cin >> a[i];

    vector<pair<int, int>> edges(n); // edges[1..n-1]
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int id = 1; id <= n - 1; ++id) {
      int u, v;
      cin >> u >> v;
      edges[id] = {u, v};
      adj[u].push_back({v, id});
      adj[v].push_back({u, id});
    }

    vector<char> removed(n, 0); // removed[id] == 1 nếu cạnh id bị xóa

    int q;
    cin >> q;
    while (q--) {
      int type;
      cin >> type;
      if (type == 1) {
        int x;
        cin >> x;
        // Xóa cạnh x
        removed[x] = 1;
        int u = edges[x].first;
        int v = edges[x].second;

        // BFS từ u
        vector<char> vis(n + 1, 0);
        ll sum_u = 0;
        {
          deque<int> dq;
          dq.push_back(u);
          vis[u] = 1;
          while (!dq.empty()) {
            int cur = dq.front();
            dq.pop_front();
            sum_u += a[cur];
            for (auto [to, id] : adj[cur]) {
              if (removed[id])
                continue;
              if (!vis[to]) {
                vis[to] = 1;
                dq.push_back(to);
              }
            }
          }
        }

        // BFS từ v (nếu chưa thăm)
        ll sum_v = 0;
        if (!vis[v]) {
          deque<int> dq;
          dq.push_back(v);
          vis[v] = 1;
          while (!dq.empty()) {
            int cur = dq.front();
            dq.pop_front();
            sum_v += a[cur];
            for (auto [to, id] : adj[cur]) {
              if (removed[id])
                continue;
              if (!vis[to]) {
                vis[to] = 1;
                dq.push_back(to);
              }
            }
          }
        } else {
          // Lý thuyết không đến đây vì sau khi xóa cạnh, u và v phải ở 2 thành
          // phần khác nhau. Nhưng giữ để an toàn.
        }

        ll diff = sum_u - sum_v;
        if (diff < 0)
          diff = -diff;
        cout << diff << '\n';
      } else if (type == 2) {
        int u;
        ll y;
        cin >> u >> y;
        a[u] += y;
      } else if (type == 3) {
        // Tính tổng mỗi thành phần hiện có, lấy max
        vector<char> vis(n + 1, 0);
        ll best = LLONG_MIN;
        for (int i = 1; i <= n; ++i) {
          if (vis[i])
            continue;
          // BFS from i
          ll s = 0;
          deque<int> dq;
          dq.push_back(i);
          vis[i] = 1;
          while (!dq.empty()) {
            int cur = dq.front();
            dq.pop_front();
            s += a[cur];
            for (auto [to, id] : adj[cur]) {
              if (removed[id])
                continue;
              if (!vis[to]) {
                vis[to] = 1;
                dq.push_back(to);
              }
            }
          }
          best = max(best, s);
        }
        cout << best << '\n';
      }
    }
  }

  return 0;
}
