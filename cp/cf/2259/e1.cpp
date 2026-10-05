/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <numeric>
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    dbg("org", a);

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });
    vector<int> ans(n);
    bool ok = true;
    for (int id = 0; id < n; id++) {
      int i = p[id];
      if (a[i] == -1) {
        continue;
      }
      if (a[i] == 0) {
        ans[i] = 1;
        continue;
      }

      bool pass = false; 
      for (int j : {i - a[i], i + a[i]}) {
        if (j < 0 || j >= n) {
          continue;
        }
        if (a[j] == 0) {
          pass = true;
          break;
        }
      }
      if (pass) {
        continue;
      }

      for (int j : {i - a[i], i + a[i]}) {
        if (j < 0 || j >= n) {
          continue;
        }
        if (a[j] == -1) {
          pass = true;
          ans[j] = 1;
          break;
        }
      }
      
      ok &= pass;
    }

    if (!ok) {
      cout << "-1\n";
      continue;
    }

    auto build = [&]() -> pair<vector<int>, vector<int>> {
      vector<int> prv(n);
      for (int i = 0; i < n; i++) {
        if (ans[i] == 1) {
          prv[i] = i;
        } else {
          prv[i] = (i == 0 ? -1 : prv[i - 1]);
        }
      }
      vector<int> nxt(n);
      for (int i = n - 1; i >= 0; i--) {
        if (ans[i] == 1) {
          nxt[i] = i;
        } else {
          nxt[i] = (i == n - 1 ? n : nxt[i + 1]);
        }
      }
      return {prv, nxt};
    };

    auto [prv, nxt] = build();

    dbg(a, ans);
    dbg(prv, nxt);
    for (int id = 0; id < n; id++) {
      int i = p[id];
      if (a[i] != -1) {
        break;
      }
      if (prv[i] == -1 && nxt[i] == n) {
        a[i] = 0;
        ans[i] = 1;
      } else if (prv[i] == -1) {
        a[i] = nxt[i] - i;
      } else if (nxt[i] == n) {
        a[i] = i - prv[i];
      } else {
        a[i] = min(nxt[i] - i, i - prv[i]);
      }
    }

    auto k = build();
    prv = k.first;
    nxt = k.second;

    dbg("----------------");
    dbg(a, ans);
    dbg(prv, nxt);
    for (int i = 0; i < n; i++) {
      dbg(i);
      assert(prv[i] != -1 || nxt[i] != n);
      if (prv[i] == -1) {
        ok &= nxt[i] - i == a[i];
      } else if (nxt[i] == n) {
        ok &= i - prv[i] == a[i];
      } else {
        ok &= min(i - prv[i], nxt[i] - i) == a[i];
      }
      dbg(ok);
    }

    if (ok) {
      for (int i = 0; i < n; i++) {
        cout << ans[i];
      }
      cout << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
