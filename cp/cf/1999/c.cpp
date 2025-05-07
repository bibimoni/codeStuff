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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, s, m;
    cin >> n >> s >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    int prev = 0;
    bool ok = false;
    for (auto [l, r] : a) {
      if (l - prev >= s) {
        ok = true;
      }
      prev = r;
    }
    ok |= (m - prev) >= s;
    cout << (ok ? "YES\n" : "NO\n");
  }
}


