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

vector<int> spf(int n) {
  n++;
  vector<int> a(n);
  a[1] = 1;
  for (int i = 2; i < n; i++) {
    if (a[i] == 0) {
      a[i] = i;
      for (int j = 2 * i; j < n; j += i) {
        a[j] = i;
      }
    }
  }
  return a;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    auto mxp = spf(n + 5);
    vector<vector<int>> s(n + 1);
    for (int i = n; i >= 1; i--) {
      s[mxp[i]].push_back(i);
    }

    vector<int> was(n + 1);
    vector<vector<int>> nxt(n + 1);
    for (int i = n; i >= 1; i--) {
      for (int v : s[i]) {
        if (was[v]) {
          continue;
        }
        was[v] = 1;
        nxt[i].push_back(v);
      }
    }
    vector<int> ans(n + 1);
    iota(ans.begin(), ans.end(), 0);

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < (int)nxt[i].size(); j++) {
        ans[nxt[i][j]] = nxt[i][(j + 1) % nxt[i].size()];
      }
    }

    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  }
}
