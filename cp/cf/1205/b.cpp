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
  int n;
  cin >> n;
  vector<int> a(n);
  const int BITS = 60;
  vector<int> cnt(BITS + 1, 0);
  vector<int> mark(BITS + 1, -1);
  vector<set<int>> adj(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j <= BITS; j++) {
      if ((a[i] >> j) & 1) {
        cnt[j] += 1;
        if (mark[j] == -1) {
          mark[j] = i;
        } else {
          adj[mark[j]].insert(i);
          adj[i].insert(mark[j]);
        }
      }
    }
  } 

  int ans = 60;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    if (cnt[i] > 2) {
      ans = 3;
      break;
    }
    ok |= cnt[i] >= 2;
  }
  if (ans == 3) {
    cout << ans << '\n';
    return 0;
  }
  if (!ok) {
    cout << "-1\n";
    return 0;
  }

  const int INF = int(1e9);
  auto dijkstra = [&] (int src, int dest) -> int {
    vector<int> d(n, INF);
    d[src] = 0;
    set<pair<int, int>> st;
    st.insert({d[src], src});
    while (st.size()) {
      auto [w1, u] = *st.begin();
      st.erase(st.begin());
      if (d[u] != w1) {
        continue;
      }
      for (int v : adj[u]) {
        if (d[u] == 1 && v == src) {
          continue;
        }
        if (d[v] > d[u] + 1) {
          d[v] = d[u] + 1;
          st.insert({d[v], v});
        }
      }
    }
    return d[dest] + 1;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= BITS; j++) {
      if (mark[j] != -1 && mark[j] != i) {
        dbg(adj, i, mark[j]);
        bool rem = adj[i].find(mark[j]) != adj[i].end();
        if (rem) {
          adj[i].erase(mark[j]);
          adj[mark[j]].erase(i);
        }
        dbg(adj);
        ans = min(ans, dijkstra(i, mark[j]));
        if (rem) {
          adj[i].insert(mark[j]);
          adj[mark[j]].insert(i);
        }
        dbg(adj)
      }
    }
  }
  cout << ans << '\n';
}


