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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back({x, y});
  }

  auto cross = [&](int x1, int y1, int x2, int y2) -> int64_t {
    return 1LL * x1 * y2 - 1LL * x2 * y1;
  };

  auto cmp = [&](pair<int, int> i, pair<int, int> j) -> bool {
    int ah = (i.second < 0 || (i.second == 0 && i.first < 0));
    int bh = (j.second < 0 || (j.second == 0 && j.first < 0));
    if (ah != bh) {
      return ah < bh;
    }
    return cross(i.first, i.second, j.first, j.second) > 0;
  };

  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) { return cmp(a[i], a[j]); });
  reverse(p.begin(), p.end());
  dbg(a, p);
  vector<int> rev(n);
  for (int i = 0; i < n; i++) {
    rev[p[i]] = i;
  }

  vector<int> l(n), r(n);
  l[0] = 0, r[n - 1] = n;
  for (int i = 1; i < n; i++) {
    l[i] = (cmp(a[p[i]], a[p[i - 1]]) ? i : l[i - 1]);
  }

  for (int i = n - 2; i >= 0; i--) {
    r[i] = (cmp(a[p[i + 1]], a[p[i]]) ? i + 1 : r[i + 1]);
  }

  while (q--) {
    int x, y;
    cin >> x >> y;
    x -= 1;
    y -= 1;
    x = l[rev[x]];
    y = r[rev[y]];
    if (x < y) {
      cout << y - x << '\n';
    } else {
      cout << n - x + y << '\n';
    }
  }
}
