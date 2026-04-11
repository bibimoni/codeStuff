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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> cnt(n + 1);
  auto b = a;
  vector<int> suf(n + 2, 1);
  for (int i = n; i >= 1; i--) {
    bool ok = true;
    if (i - 2 >= 1) {
      while (b[i] % 3 != 0) {
        if (b[i - 1] <= 0 || b[i - 2] <= 0) {
          ok = false;
          break;
        }
        cnt[i] += 1;
        b[i] -= 1;
        b[i - 1] -= 1;
        b[i - 2] -= 1;
      }
    }
    suf[i] &= suf[i + 1] & ok & (b[i] % 3 == 0);
  }

  vector<int> ans;
  bool chk = true;
  for (int i = 1; i <= n; i++) {
    if (i + 2 <= n) {
      while (cnt[i + 2]--) {
        b[i + 1] += 1;
        b[i] += 1;
        b[i + 2] += 1;
      }
    }

    vector<int> cur;
    for (int j = max(1, i - 2); j <= min(n, i + 2); j++) {
      cur.push_back(b[j] + (j == i));
    }

    bool ok = true;
    for (int j = 0; j < (int)cur.size(); j++) {
      if (j + 2 < (int)cur.size()) {
        while (cur[j] % 3 != 0) {
          if (cur[j + 1] <= 0 || cur[j + 2] <= 0) {
            ok = false;
            break;
          }
          cur[j] -= 1;
          cur[j + 1] -= 1;
          cur[j + 2] -= 1;
        }
      }
      ok &= cur[j] % 3 == 0;
    }
    if (ok && chk && ((i + 3 > n) || (i + 3 <= n && suf[i + 3]))) {
      ans.push_back(i);
    }

    if (i - 2 >= 1) {
      while (b[i - 2] % 3 != 0) {
        if (b[i - 1] <= 0 || b[i] <= 0) {
          chk = false;
          break;
        }
        b[i - 2] -= 1;
        b[i - 1] -= 1;
        b[i] -= 1;
      }
    }

    if (i - 2 >= 1) {
      chk &= b[i - 2] % 3 == 0;
    }
  }

  cout << ans.size() << '\n';
  for (int i = 0; i < int(ans.size()); i++) {
    cout << ans[i] << " \n"[i == int(ans.size()) - 1];
  }
}
