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
    string s;
    cin >> s;
    array<int, 2> cnt{0, 0};
    for (int i = 0; i < n; i++) {
      cnt[s[i] - '0'] += 1;
    }
    int ngood = (n / 2) - k;
    bool ok = true;
    for (int i = 0; i < ngood; i++) {
      if (cnt[0] > 0 && cnt[1] > 0) {
        cnt[0] -= 1;
        cnt[1] -= 1;
      } else {
        ok = false;
      }
    }
    cout << (ok && cnt[0] % 2 == 0 && cnt[1] % 2 == 0 ? "YES\n" : "NO\n");
  }
}
