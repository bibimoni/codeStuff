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

/**
 * Description: Finding the diameter of tree in O(V + E)
 * Source: Self
 */

struct TD {
  int ans = 0;
  vector<vector<pair<int, int>>> g;

  int Dfs (int u, int pr) {
    pair<int, int> lol = {0, 0};
    for (auto [w, v] : g[u]) {
      if (v == pr) continue;
      int te = Dfs(v, u);
      if (lol.first < te + w) {
        lol.second = lol.first;
        lol.first = te + w;
      } else if (lol.second < te + w) {
        lol.second = te + w;
      }
    }
    ans = max(ans, lol.first + lol.second);
    return lol.first;
  }

  int run() {
    Dfs(1, 1);
    return ans;
  }

  TD(vector<vector<pair<int, int>>>& _g) : g(_g) {}
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    ans += c * 2;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  TD td(adj);
  ans -= td.run();
  cout << ans << '\n';
}


