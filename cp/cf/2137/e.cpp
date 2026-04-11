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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool smol = k <= int(10);
    const int K = min(int(10), k);
    auto mex = [&]() -> int {
      vector<int> cnt(n + 1);
      for (int i = 0; i < n; i++) {
        cnt[a[i]] += 1;
      }

      int cmex = 0;
      vector<int> mark(n, 0);
      for (int i = 0; i < n; i++) {
        if (a[i] == cmex) {
          cmex += 1;
          mark[i] = 1;
        } else if (a[i] > cmex) {
          break;
        }
      }

      for (int i = 0; i < n; i++) {
        if (!mark[i]) {
          a[i] = cmex;
        } else if (cnt[a[i]] > 1) {
          a[i] = cmex;
        }
      }

      sort(a.begin(), a.end());
      return accumulate(a.begin(), a.end(), int(0));
    };

    int sum_odd = -1;
    int sum_even = -1;
    for (int i = 1; i <= K; i++) {
      if (i % 2 == 0) {
        sum_even = mex();
      } else {
        sum_odd = mex();
      }
    }

    if (smol) {
      cout << accumulate(a.begin(), a.end(), int(0)) << '\n';
    } else {
      cout << (k % 2 == 0 ? sum_even : sum_odd) << "\n";
    }
  }
}
