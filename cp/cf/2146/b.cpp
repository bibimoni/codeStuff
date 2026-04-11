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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
      int l;
      cin >> l;
      for (int j = 0; j < l; j++) {
        int x;
        cin >> x;
        a[i].push_back(x);
      }
    }

    vector<int> es(m + 1);
    for (int i = 0; i < n; i++) {
      for (int x : a[i]) {
        es[x] += 1;
      }
    }

    auto check = [&](int skip) -> bool {
      bool ok = true;
      vector<int> e(m + 1);
      for (int i = 0; i < n; i++) {
        if (i == skip) {
          continue;
        }
        for (int x : a[i]) {
          e[x] += 1;
        }
      }
      for (int i = 1; i <= m; i++) {
        ok &= e[i] > 0;
      }
      return ok;
    };

    auto find_id = [&](int skip) -> int {
      int id = -1;
      for (int i = 0; i < n; i++) {
        bool ok = true;
        if (i == skip) {
          continue;
        }
        for (int x : a[i]) {
          if (es[x] == 1) {
            ok = false;
          }
        }
        if (ok) {
          id = i;
        }
      }
      return id;
    };

    int cnt = check(-1);
    int id = find_id(-1);
    if (id != -1) {
      cnt += int(check(id));
      id = find_id(id);
      if (id != -1) {
        cnt += int(check(id));
      }
    }

    cout << (cnt >= 3 ? "Yes\n" : "No\n");
  }
}
