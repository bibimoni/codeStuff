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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<array<int, 3>> p(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> p[i][0];
    }
    for (int i = 1; i <= n; i++) {
      cin >> p[i][1];
    }
    for (int i = 1; i <= n; i++) {
      cin >> p[i][2];
    }
    // dp[i] di dc i den n
    // dp[j] = dp[i] (i > j)
    // p[j] > p[i] => j < i
    // => p[j] > min(p[i] voi dp[i] = 1)
    // dp[i] = 1 luu min p[i]
    // dp[n] = 1

    // q, k, j => min q, min k, min j => luu vi tri cua min q, min k, min j

    array<int, 3> mn{n, n, n};

    vector<array<int, 3>> reach(n + 1, {-1, -1, -1});

    bool ok = false;

    for (int i = n - 1; i >= 1; i--) {
      bool can = false;
      for (int j = 0; j < 3; j++) {
        if (p[i][j] > p[mn[j]][j]) {
          can = true;
          reach[i][j] = mn[j];
        }
      }

      ok |= (can && i == 1);

      if (can) {
        for (int j = 0; j < 3; j++) {
          if (p[mn[j]][j] > p[i][j]) {
            mn[j] = i;
          }
        }
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    vector<pair<char, int>> ans;
    string s = "qkj";
    int cur = 1;
    while (cur != n) {
      bool mv = false;
      for (int j = 0; j < 3; j++) {
        if (reach[cur][j] != -1) {
          mv = true;
          ans.push_back({s[j], reach[cur][j]});
          cur = reach[cur][j];
          break;
        }
      }
      if (!mv) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n" << ans.size() << '\n';
    for (auto [c, x] : ans) {
      cout << c << ' ' << x << '\n';
    } 
  }
}

