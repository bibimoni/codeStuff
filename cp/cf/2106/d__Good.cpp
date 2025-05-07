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
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    const int INF = (int) 1e18;
    int ans = INF;
    auto check = [&] (int st, int j) -> bool {
      for (int i = st; i < n; i++) {
        if (j < m && a[i] >= b[j]) {
          j += 1;
        }
      }
      return j == m;
    };
    int j = 0;
    if (check(0, 0)) {
      cout << 0 << '\n';
    } else {
      for (int i = 0; i < n; i++) {
        if (check(i, j + 1)) {
          ans = min(ans, b[j]);
        }
        if (j < m && a[i] >= b[j]) {
          j += 1;
        }
      }
      if (j == m - 1) {
        ans = min(ans, b[j]);
      } else {
        ans = min(ans, INF);
      }
      cout << (ans == INF ? -1 : ans) << "\n";
    }
  }
}

