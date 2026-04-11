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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<int> start;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] != 0) {
      adj[a[i]].push_back(i + 1);
      adj[b[i]].push_back(i + 1);
    }
    if (a[i] == 0) {
      start.push_back(i + 1);
    }
  }

  for (int i = 0; i < (int)start.size() - 1; i++) {
    adj[start[i]].push_back(start[i + 1]);
  }
  if (start.size() == 0) {
    cout << 0 << '\n';
    return 0;
  }

  vector<int> was(n + 1, 0);
  queue<int> que;
  que.push(start[0]);
  while (que.size()) {
    int u = que.front();
    que.pop();
    if (was[u]) {
      continue;
    }
    was[u] = 1;
    for (int v : adj[u]) {
      que.push(v);
    }
  }

  int ans = accumulate(was.begin(), was.end(), 0);
  dbg(was);
  cout << ans << '\n';
}
