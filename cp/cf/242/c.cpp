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
  int xs, ys, xe, ye;
  cin >> xs >> ys >> xe >> ye;
  int n;
  cin >> n;
  vector<array<int, 3>> a(n);
  map<pair<int, int>, int> d;
  const int INF = int(1e9);
  map<pair<int, int>, vector<pair<int, int>>> adj;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    int row = a[i][0], l = a[i][1], r = a[i][2];
    for (int j = l; j <= r; j++) {
      d[{row, j}] = INF;
    }
  }
  for (int i = 0; i < n; i++) {
    int row = a[i][0], l = a[i][1], r = a[i][2];
    for (int j = l; j <= r; j++) {
      if (j > l) {
        adj[{row, j}].push_back({row, j - 1});
      } 
      if (j < r) {
        adj[{row, j}].push_back({row, j + 1});
      }
      for (int m : {-1, 1}) {
        for (int offset : {-1, 0, 1}) {
          if (d.count({row + m, j + offset})) {
            adj[{row, j}].push_back({row + m, j + offset});
          }
        }
      }
    }
  }
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
  pq.push({0, xs, ys});
  d[{xs, ys}] = 0;
  while(pq.size()) {
    auto p = pq.top();
    pq.pop();
    int w1 = p[0], ux = p[1], uy = p[2];
    if (w1 != d[{ux, uy}]) {
      continue;
    }
    for (auto [vx, vy] : adj[{ux, uy}]) {
      if (d[{vx, vy}] > d[{ux, uy}] + 1) {
        d[{vx, vy}] = d[{ux, uy}] + 1;
        pq.push({d[{vx, vy}], vx, vy});
      }
    }
  }
  cout << (d[{xe, ye}] == INF ? -1 : d[{xe, ye}]) << '\n';
}

