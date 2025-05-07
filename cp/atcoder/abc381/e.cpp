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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;
  for (char &c : s) {
    if (c == '/') {
      c = '0';
    }
  }
  vector<array<int, 3>> cnt(n + 1);
  for (char c : {'0', '1', '2'}) {
    for (int i = 1; i <= n; i++) {
      cnt[i][c - '0'] = cnt[i - 1][c - '0'] + int(s[i] == c);
    }
  }

  auto findNxt = [&] (int from, int sz, int e) -> int {
    int lo = from, hi = n, ret = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (cnt[mid][e] - cnt[from - 1][e] >= sz) {
        ret = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return ret;
  };

  auto can = [&] (int from, int to, int len) -> bool {
    int idx = findNxt(from, len, 1);
    if (idx == -1 || (idx > to)) {
      return false;
    }
    idx = findNxt(idx + 1, 1, 0);
    if (idx == -1 || (idx > to)) {
      return false;
    }
    idx = findNxt(idx + 1, len, 2);
    if (idx == -1 || (idx > to)) {
      return false;
    }
    return true;
  };

  while (q--) {
    int l, r;
    cin >> l >> r;
    int lo = 0, hi = (r - l + 1) / 2, ret = -1;
    while (lo <= hi) {
      int mid = (hi + lo) >> 1;
      if (can(l, r, mid)) {
        lo = mid + 1;
        ret = mid * 2 + 1;
      } else {
        hi = mid - 1;
      }
    }    
    cout << (ret == -1 ? 0 : ret) << '\n';
  }
}


