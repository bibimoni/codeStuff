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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
      a[i] -= 1;
    }
    vector<int> mark(n);
    for (int i = 0; i < t; i++) {
      int x;
      cin >> x;
      x -= 1;
      mark[x] = 1;
    }

    sort(a.begin(), a.end());
    auto nxtTo = [&](int x, int y) -> bool {
      return abs(y - x) == 1 || (x == 0 && y == n - 1) ||
             (y == 0 && x == n - 1);
    };

    bool ok = true;
    for (int i = 0; i < m; i++) {
      if (nxtTo(a[(i - 1 + m) % m], a[i]) && nxtTo(a[i], a[(i + 1) % m])) {
        ok = false;
        break;
      }
    }

    if (!ok) {
      cout << "NO\n";
      continue;
    }

    vector<int> was(m);
    for (int i = 0; i < m; i++) {
      if (nxtTo(a[(i - 1 + m) % m], a[i])) {
        int p1 = a[(i - 1 + m) % m];
        int p2 = (a[(i - 1 + m) % m] - 1 + n) % n;
        int p3 = a[i];
        int p4 = (a[i] + 1) % n;
        dbg(i);
        if (!mark[p1] || !mark[p2] || !mark[p3] || !mark[p4]) {
          ok = false;
          break;
        }
        was[i] = 1;
        was[(i - 1 + m) % m] = 1;
        mark[p1] = 0;
        mark[p2] = 0;
        mark[p3] = 0;
        mark[p4] = 0;
      }
    }
    vector<int> tmark;
    auto go = [&](int x) -> bool {
      vector<int> pro{x};
      for (int i = x + 1; i < m; i++) {
        if (was[i] == 0) {
          pro.push_back(i);
        }
      }
      for (int i = x - 1; i >= 0; i--) {
        if (was[i] == 0) {
          pro.push_back(i);
        }
      }
      dbg(pro, a);
      tmark = mark;
      sort(pro.begin(), pro.end());
      bool ok_t = true;
      for (int id = 0; id < int(pro.size()); id++) {
        int i = pro[id];
        int p1 = (a[i] - 1 + n) % n;
        int p2 = a[i];
        int p3 = (a[i] + 1) % n;
        if (tmark[p1] && tmark[p2]) {
          tmark[p1] = 0;
          tmark[p2] = 0;
        } else if (tmark[p2] && tmark[p3]) {
          tmark[p2] = 0;
          tmark[p3] = 0;
        } else if (tmark[p1] && tmark[p3]) {
          tmark[p1] = 0;
          tmark[p3] = 0;
        } else {
          dbg(p1, p2, p3, tmark);
          ok_t = false;
          break;
        }
      }
      dbg(tmark, ok_t);
      if (!ok_t) {
        tmark = mark;
        ok_t = true;
        for (int id = 0; id < int(pro.size()); id++) {
          int i = pro[id];
          int p1 = (a[i] - 1 + n) % n;
          int p2 = a[i];
          int p3 = (a[i] + 1) % n;
          if (tmark[p2] && tmark[p3]) {
            tmark[p2] = 0;
            tmark[p3] = 0;
          } else if (tmark[p1] && tmark[p2]) {
            tmark[p1] = 0;
            tmark[p2] = 0;
          } else if (tmark[p1] && tmark[p3]) {
            tmark[p1] = 0;
            tmark[p3] = 0;
          } else {
            ok_t = false;
            break;
          }
        }
      }
      if (ok_t) {
        dbg(ok_t);
        for (int i = 0; i < int(pro.size()); i++) {
          was[pro[i]] = 1;
        }
        mark = tmark;
        return true;
      }
      return false;
    };
    for (int i = 0; i < m; i++) {
      if (was[i] != 0) {
        continue;
      }
      ok &= go(i);
    }

    if (ok) {
      assert(accumulate(was.begin(), was.end(), 0) == m);
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}
