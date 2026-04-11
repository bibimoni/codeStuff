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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "01";
    return 0;
  }

  vector<vector<int>> adj(1 << (n - 1));
  for (int i = 0; i < (1 << int(n - 1)); i++) {
    int node = (i << 1) % (1 << (n - 1));
    adj[i].push_back(node);
    adj[i].push_back(node | 1);
  }

  stack<int> st;
  st.push(0);
  vector<int> path;
  while (st.size()) {
    int node = st.top();
    if (adj[node].empty()) {
      path.push_back(node & 1);
      st.pop();
    } else {
      st.push(adj[node].back());
      adj[node].pop_back();
    }
  }

  for (int i = 0; i < n - 2; i++) {
    path.push_back(0);
  }
  for (int i : path) {
    cout << i;
  }
}
