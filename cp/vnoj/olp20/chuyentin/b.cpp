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
  int k;
  cin >> k;
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  array<vector<int>, 3> p;
  for (int j = 0; j < 3; j++) {
    p[j] = vector<int>(n + 1, 0);
  }

  string t = "VCA";
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      p[j][i] = p[j][i - 1] + (t[j] == s[i]);
    }
  }

  auto range = [&] (int j, int l, int r) -> int {
    return p[j][r] - p[j][l - 1];
  };

  int ans = int(1e9);
  for (int i = n + 1; i >= 1; i--) {
    int lo = 0, hi = i - 1, ret = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      bool ok = true;
      for (int j = 0; j < 3; j++) {
        ok &= range(j, mid + 1, i - 1) >= k;
      }
      if (ok) {
        ret = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    } 
    if (ret != -1) {
      int need = 0;
      for (int j = 0; j < 3; j++) {
        need += range(j, ret + 1, i - 1) - k;
      }
      ans = min(ans, need);
    }
  }
  cout << (ans == int(1e9) ? -1 : ans) << '\n';
}

