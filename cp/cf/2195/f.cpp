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

const int N = 3000;
array<int, 3> a[N];
vector<int> adj[N];
vector<int> adjr[N];
int dp[N];
int dp2[N];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i][0] >> a[i][1] >> a[i][2];
      adj[i].clear();
      adjr[i].clear();
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }

        int da = a[i][0] - a[j][0];
        int db = a[i][1] - a[j][1];
        int dc = a[i][2] - a[j][2];
        if ((da > 0 && 1ll * db * db < 4ll * da * dc) ||
            (da == 0 && db == 0 && dc > 0)) {
          adj[i].push_back(j);
          adjr[j].push_back(i);
        }
      }
    }

    auto dfs = [&](auto &&self, int u) -> int {
      if (dp[u] != -1) {
        return dp[u];
      }
      int ret = 1;
      for (int v : adj[u]) {
        ret = max(ret, self(self, v) + 1);
      }
      dp[u] = ret;
      return ret;
    };

    auto dfs2 = [&](auto &&self, int u) -> int {
      if (dp2[u] != -1) {
        return dp2[u];
      }
      int ret = 1;
      for (int v : adjr[u]) {
        ret = max(ret, self(self, v) + 1);
      }
      dp2[u] = ret;
      return ret;
    };

    for (int x = 0; x < n; x++) {
      dp[x] = dp2[x] = -1;
    }

    for (int i = 0; i < n; i++) {
      int ans = dfs(dfs, i) + dfs2(dfs2, i) - 1;
      cout << ans << " \n"[i == n - 1];
    }
  }
}
