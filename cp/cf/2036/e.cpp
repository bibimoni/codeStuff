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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k, q;
  cin >> n >> k >> q;
  vector<vector<int>> a(n + 1, vector<int>(k + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 1; j <= k; j++) {
    for (int i = 2; i <= n; i++) {
      a[i][j] |= a[i - 1][j];
    }
  }

  while (q--) {
    int m;
    cin >> m;
    int bl = 1, br = 1e9;
    map<int, pair<int, int>> b;
    while(m--) {
      int r, c;
      char o;
      cin >> r >> o >> c;
      if (!b.count(r)) {
        b[r] = {a[1][r], a[n][r]};
      }
      if (o == '>') {
        b[r].first = max(b[r].first, c + 1);
      } else {
        b[r].second = min(b[r].second, c - 1);
      }
    } 
    int ans = -1;
    bool ok = true;
    for (auto [r, p] : b) {
      auto [bl, br] = p;
      int lo = 1, hi = n, cur = -1;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (a[mid][r] >= bl) {
          cur = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      if (cur == -1 || a[cur][r] > br) {
        ok = false;
        break;
      }
      ans = max(ans, cur);
    }
    if (ans == -1 || !ok) {
      cout << -1 << '\n';
      continue;
    }
    ok = true;
    for (auto [r, p] : b) {
      auto [bl, br] = p;
      ok &= bl <= a[ans][r] && a[ans][r] <= br;
    }
    cout << (ok ? ans : -1) << '\n';
    // dbg(b);
  }
}


