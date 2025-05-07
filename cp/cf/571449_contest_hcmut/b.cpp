// time-limit: 3000
/**
 * Author: distiled
 */
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t
const int N = 2e5 + 5, K = 20;
int n, m, k;
int c[K];
vector<int> adj[N];
int dist[K][K];
int pos[N], d[N];
const int B = int(1) << 20;
int dp[B];

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  // freopen("OPERATION.INP", "r", stdin);
  // freopen("OPERATION.OUT", "w", stdout);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  const int INF = 1e9;
  for (int i = 0; i < k; i++) {
    cin >> c[i];
    pos[c[i]] = i;
    for (int j = 0; j < k; j++) {
      dist[i][j] = INF;
    }
  }
  for (int i = 1; i < (int(1) << k); i++) {
    dp[i] = INF;
  }
  for (int i = 1; i <= n; i++) {
    d[i] = INF;    
    pos[i] = -1;
  }
  dp[0] = 0;
  for (int i = 0; i < k; i++) {
    int node = c[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[node] = 0;
    pq.push({d[node], node});
    while (pq.size()) {
      auto [w, u] = pq.top();
      pq.pop();
      if (d[u] != w) {
        continue;
      }
      for (int v : adj[u]) {
        if (d[v] > d[u] + 1) {
          d[v] = d[u] + 1;
          pq.push({d[v], v});
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (pos[i] != -1) {
        dist[pos[node]][pos[i]] = d[i];
      }
      d[i] = INF;
    }
  }
  for (int mask = 0; mask < (int(1) << k); mask++) {
    for (int i = 0; i < k; i++) {
      for (int j = i + 1; j < k; j++) {
        if ((((mask >> j) & 1) ^ 1) && (((mask >> i) & 1) ^ 1) && i != j) {
          if (dist[pos[c[i]]][pos[c[j]]] != INF) {
            int nmask = mask | (int(1) << i) | (int(1) << j);
            dp[nmask] = min(dp[nmask], dp[mask] + dist[pos[c[i]]][pos[c[j]]]);
          }
        }
      }
    }
  }
  int ans = dp[(int(1) << k) - 1];
  cout << (ans != INF ? ans : -1);
}


