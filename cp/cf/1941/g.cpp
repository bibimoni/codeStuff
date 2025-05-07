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
#define int long long

const int N = (int) 2e5 + 5, INF = (int) 2e9;
vector<int> adj[2 * N];
int sz = 0;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, b, e;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for(int i = 1; i <= sz; i++) {
      adj[i].clear();
    }
    vector<int> colors;
    for(int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      colors.push_back(c);
      edges[i] = {u, v, c};
    }
    sort(colors.begin(), colors.end());
    colors.erase(unique(colors.begin(), colors.end()), colors.end());
    for(int i = 0; i < m; i++) {
      auto [u, v, c] = edges[i];
      c = lower_bound(colors.begin(), colors.end(), c) - colors.begin() + 1 + n;
      adj[u].push_back(c);
      adj[c].push_back(u);
      adj[v].push_back(c);
      adj[c].push_back(v);
    }
    int k = colors.size();
    sz = k + n;
    cin >> b >> e;
    vector<int> d(sz + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, b});
    d[b] = 0;
    while(pq.size()) {
      auto [w, u] = pq.top();
      pq.pop();
      if(d[u] != w)
        continue;
      for(int v : adj[u]) {
        if(d[v] > d[u] + 1) {
          d[v] = d[u] + 1;
          pq.push({d[v], v});
        }
      }
    }
    cout << d[e] / 2 << '\n';
  }
}

