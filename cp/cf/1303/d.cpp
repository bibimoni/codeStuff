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
    int sz, n;
    cin >> sz >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (accumulate(a.begin(), a.end(), 0ll) < sz) {
      cout << "-1\n";
      continue;
    }
    sort(a.begin(), a.end());
    const int LG = 64;
    vector<int> cnt(LG, 0);
    for (int i = 0, j = 0; i < n; i++) {
      while ((1ll << j) < a[i]) {
        j += 1;
      }
      cnt[j] += 1;
    }
    int ans = 0;
    for (int j = 0; j < 61; j++) {
      if (((sz >> j) & 1) == 0) {
        cnt[j + 1] += cnt[j] / 2;
      } else {
        if (cnt[j] == 0) {
          int idx = 0;
          for (int i = j + 1; i < 61; i++) {
            if (cnt[i] > 0) {
              idx = i;
              break;
            }
          }
          for (int i = idx; i > j; i--) {
            cnt[i - 1] += 2;
            cnt[i] -= 1;
            ans += 1;
          }
        } else {
          cnt[j] -= 1;
          cnt[j + 1] += cnt[j] / 2;
        }
      }
    }
    cout << ans << '\n';
  }
}

