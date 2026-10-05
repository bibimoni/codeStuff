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
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  const int inf = 1e18;
  vector<int> d(n + 2, inf);
  set<pair<int, int>> st;
  st.insert({0, n + 1});
  d[n + 1] = 0;
  while (st.size()) {
    auto [w1, u] = *st.begin();
    st.erase(st.begin());
    
    if (d[u] != w1)  {
      continue;
    }

    if (u == n + 1) {
      for (int v = 1; v <= n; v++) {
        if (d[v] > d[u] + b[v]) {
          d[v] = d[u] + b[v];
          st.insert({d[v], v});
        }
      }
    } else {
      for (int v: vector<int>{
        (u % n) + 1,
        (u > 1 ? u - 1 : n),
        n + 1
      }) {
        int w;
        if (v == n + 1) {
          w = b[u];
        } else if ((v == 1 && u == n) || (u == 1 && v == n)) {
          w = a[n];
        } else {
          w = a[min(u, v)];
        }
        if (d[v] > d[u] + w) {
          d[v] = d[u] + w; 
          st.insert({d[v], v});
        }
      }
    }
  }

  vector<int> pre(n + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (v == n + 1) {
      cout << d[u] << '\n';
    } else {
      int dist = pre[v - 1] - pre[u - 1];
      cout << min({pre[n] - dist, dist, d[u] + d[v]}) << '\n';
    }
  }
}
