/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <complex>
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
  string player;
  cin >> player;
  if (player == "first") {
    int tt;
    cin >> tt;
    for (int tc = 0; tc < tt; tc++) {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> adj(n + 1);
      for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }

      string cv = "rgb";
      queue<int> que;
      vector<int> was(n + 1, -1);
      was[1] = 0;
      que.push(1);
      while (que.size()) {
        auto u = que.front();
        que.pop();
        for (int v : adj[u]) {
          if (was[v] != -1) {
            continue;
          }
          was[v] = was[u] + 1;
          que.push(v);
        }
      }

      for (int i = 1; i <= n; i++) {
        cout << cv[was[i] % 3];
      }
      cout << '\n';
    }
  } else {
    int tt;
    cin >> tt;
    for (int tc = 0; tc < tt; tc++) {
      int q;
      cin >> q;
      while (q--) {
        int d;
        cin >> d;
        string s;
        cin >> s;
        set<char> st(s.begin(), s.end());
        string disc(st.begin(), st.end());
        if (disc.size() == 1) {
          cout << 1 << "\n";
          continue;
        }
        char ans;
        if (disc == "br") {
          ans = 'r';
        } else if (disc == "bg") {
          ans = 'b';
        } else if (disc == "gr") {
          ans = 'g';
        } else {
          throw;
        }

        cout << s.find(ans) + 1 << '\n';
      }
    }
  }
}
