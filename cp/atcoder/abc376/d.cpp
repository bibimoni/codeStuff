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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> ind(n + 1, 0);
  vector<int> s;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    if (v == 1) {
      s.push_back(u);
    }
  }
  set<pair<int, int>> st;
  const int INF = int(1e9);
  vector<int> d(n + 1, INF);
  d[1] = 0;
  st.insert({d[1], 1});
  while (st.size()) {
    auto [w1, u] = *st.begin();
    st.erase(st.begin());
    if (d[u] != w1) {
      continue;
    }
    dbg(u);
    for (int v : adj[u]) {
      if (d[u] + 1 < d[v]) {
        d[v] = d[u] + 1;
        st.insert({d[v], v});
      }
    }
  }
  int ans = INF;
  dbg(d, s);
  for (int k : s) {
    ans = min(ans, d[k] + 1);
  }
  cout << (ans == INF ? -1 : ans);

}


